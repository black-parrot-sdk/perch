// See LICENSE for license details.

#ifndef _PK_H
#define _PK_H

#ifndef __ASSEMBLER__

#include "encoding.h"
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define mb() asm volatile ("fence" ::: "memory")

#define panic(s,...) do { do_panic(s"\n", ##__VA_ARGS__); } while(0)
#define kassert(cond) do { if(!(cond)) kassert_fail(""#cond); } while(0)
void do_panic(const char* s, ...) __attribute__((noreturn));
void kassert_fail(const char* s) __attribute__((noreturn));

#ifdef __cplusplus
extern "C" {
#endif

void printk(const char* s, ...);
void printm(const char* s, ...);
int vsnprintf(char* out, size_t n, const char* s, va_list vl);
int snprintf(char* out, size_t n, const char* s, ...);

static uint64_t lfsr63(uint64_t x)
{
  uint64_t bit = (x ^ (x >> 1)) & 1;
  return (x >> 1) | (bit << 62);
}

static inline int insn_len(long insn)
{
  return (insn & 0x3) < 0x3 ? 2 : 4;
}

#define rdtime64 rdtime
#define rdcycle64 rdcycle
#define rdinstret64 rdinstret

#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))

#ifdef __cplusplus
}
#endif

#endif // !__ASSEMBLER__

#endif
