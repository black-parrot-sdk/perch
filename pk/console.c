// See LICENSE for license details.

#include "pk.h"
//#include "mmap.h"
#include "file.h"
#include "frontend.h"
#include "syscall.h"
//#include "bits.h"
#include <stdint.h>
#include <stdarg.h>

static void vprintk(const char* s, va_list vl)
{
  char out[256]; // XXX
  int res = vsnprintf(out, sizeof(out), s, vl);
  int size = MIN(res, sizeof(out));
  nbwrite(out, size);
  frontend_syscall(SYS_write, 2, (uint64_t)out, size, 0, 0, 0, 0);
}

void printk(const char* s, ...)
{
  va_list vl;
  va_start(vl, s);

  vprintk(s, vl);

  va_end(vl);
}

void do_panic(const char* s, ...)
{
  va_list vl;
  va_start(vl, s);

  vprintk(s, vl);
  shutdown(-1);

  va_end(vl);
}

void kassert_fail(const char* s)
{
  do_panic("assertion failed @ %p: %s\n", __builtin_return_address(0), s);
}
