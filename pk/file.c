// See LICENSE for license details.

#include "file.h"
//#include "atomic.h"
//#include "mmap.h"
#include "frontend.h"
#include "syscall.h"
#include "pk.h"
#include "bp_emulation.h"
#include <string.h>
#include <errno.h>

#define MAX_FDS 128
static file_t* fds[MAX_FDS];
#define MAX_FILES 128
file_t files[MAX_FILES] = {[0 ... MAX_FILES-1] = {-1,0}};

void file_incref(file_t* f)
{
  long prev = amo_addw((uint64_t)&f->refcnt, 1);
  kassert(prev > 0);
}

void file_decref(file_t* f)
{
  if (amo_addw((uint64_t)&f->refcnt, -1) == 2)
  {
    int kfd = f->kfd;
    mb();
    amo_swapw((uint64_t)&f->refcnt, 0);

    frontend_syscall(SYS_close, kfd, 0, 0, 0, 0, 0, 0);
  }
}

static file_t* file_get_free()
{
  for (file_t* f = files; f < files + MAX_FILES; f++)
    if ((amo_addw((uint64_t)&f->refcnt, 0) == 0) && (amo_casw((uint64_t)&f->refcnt, 0, 2) == 0))
      return f;
  return NULL;
}

int file_dup(file_t* f)
{
  for (int i = 0; i < MAX_FDS; i++)
  {
    if (amo_casd((uint64_t)&fds[i], 0, (uint64_t)f) == 0)
    {
      file_incref(f);
      return i;
    }
  }
  return -1;
}

int file_dup3(file_t* f, int newfd)
{
  if (newfd < 0 || newfd >= MAX_FDS)
      return -1;

  if (amo_casd((uint64_t)&fds[newfd], 0, (uint64_t)f) == 0)
  {
      file_incref(f);
      return newfd;
  }

  return -1;
}

void file_init()
{
  // create stdin, stdout, stderr and FDs 0-2
  for (int i = 0; i < 3; i++) {
    file_t* f = file_get_free();
    f->kfd = i;
    file_dup(f);
  }
}

file_t* file_get(int fd)
{
  file_t* f;
  if (fd < 0 || fd >= MAX_FDS || (f = (file_t*)amo_addd((uint64_t)&fds[fd], 0)) == NULL)
    return 0;

  long old_cnt;
  do {
    old_cnt = amo_addw((uint64_t)&f->refcnt, 0);
    if (old_cnt == 0)
      return 0;
  } while (amo_casw((uint64_t)&f->refcnt, old_cnt, old_cnt+1) != old_cnt);

  return f;
}

file_t* file_open(const char* fn, int flags, int mode)
{
  return file_openat(AT_FDCWD, fn, flags, mode);
}

file_t* file_openat(int dirfd, const char* fn, int flags, int mode)
{
  file_t* f = file_get_free();
  if (f == NULL)
    return ERR_PTR(-ENOMEM);

  size_t fn_size = strlen(fn)+1;
  long ret = frontend_syscall(SYS_openat, dirfd, (uint64_t)fn, fn_size, flags, mode, 0, 0);
  if (ret >= 0)
  {
    f->kfd = ret;
    return f;
  }
  else
  {
    file_decref(f);
    return ERR_PTR(ret);
  }
}

int fd_close(int fd)
{
  file_t* f = file_get(fd);
  if (!f)
    return -1;
  file_t* old = (file_t*)amo_casd((uint64_t)&fds[fd], (uint64_t)f, 0);
  file_decref(f);
  if (old != f)
    return -1;
  file_decref(f);
  return 0;
}

ssize_t file_read(file_t* f, void* buf, size_t size)
{
  return frontend_syscall(SYS_read, f->kfd, (uint64_t)buf, size, 0, 0, 0, 0);
}

ssize_t file_pread(file_t* f, void* buf, size_t size, off_t offset)
{
  return frontend_syscall(SYS_pread, f->kfd, (uint64_t)buf, size, offset, 0, 0, 0);
}

ssize_t file_write(file_t* f, const void* buf, size_t size)
{
  return frontend_syscall(SYS_write, f->kfd, (uint64_t)buf, size, 0, 0, 0, 0);
}

ssize_t file_pwrite(file_t* f, const void* buf, size_t size, off_t offset)
{
  return frontend_syscall(SYS_pwrite, f->kfd, (uint64_t)buf, size, offset, 0, 0, 0);
}

int file_truncate(file_t* f, off_t len)
{
  return frontend_syscall(SYS_ftruncate, f->kfd, len, 0, 0, 0, 0, 0);
}

ssize_t file_lseek(file_t* f, size_t ptr, int dir)
{
  return frontend_syscall(SYS_lseek, f->kfd, ptr, dir, 0, 0, 0, 0);
}
