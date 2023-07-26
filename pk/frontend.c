// See LICENSE for license details.

#include "pk.h"
//#include "atomic.h"
#include "frontend.h"
#include "syscall.h"
#include "htif.h"
//#include "mmap.h"
#include <stdint.h>

void nbfetch(void* p, size_t n) {
  void* nb_ptr = (void*)((uint64_t)0x100000000 | (uint64_t)p);
  memcpy(p, nb_ptr, n);
}

long frontend_syscall(long n, uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5, uint64_t a6)
{
  static uint64_t magic_mem[8];

  //static spinlock_t lock = SPINLOCK_INIT;
  //spinlock_lock(&lock);

  magic_mem[0] = n;
  magic_mem[1] = a0;
  magic_mem[2] = a1;
  magic_mem[3] = a2;
  magic_mem[4] = a3;
  magic_mem[5] = a4;
  magic_mem[6] = a5;
  magic_mem[7] = a6;

  mb();

  htif_syscall((uintptr_t)magic_mem);

  nbfetch(magic_mem, sizeof(magic_mem[0]));

  long ret = magic_mem[0];

  //spinlock_unlock(&lock);
  return ret;
}

void shutdown(int code)
{
  frontend_syscall(SYS_exit, code, 0, 0, 0, 0, 0, 0);
  while (1);
}
