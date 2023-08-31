#ifndef BP_ASM_H
#define BP_ASM_H

#include "encoding.h"

#define cbo_inval_block(addr) ({ \
  __asm__ __volatile__ (".insn i 0x0f, 0b010, x0, %0, 0x0" : : "r" (addr)); \
  })

#define cbo_clean_block(addr) ({ \
  __asm__ __volatile__ (".insn i 0x0f, 0b010, x0, %0, 0x1" : : "r" (addr)); \
  })

#define cbo_flush_block(addr) ({ \
  __asm__ __volatile__ (".insn i 0x0f, 0b010, x0, %0, 0x2" : : "r" (addr)); \
  })

#define cbo_zero_block(addr) ({ \
  __asm__ __volatile__ (".insn i 0x0f, 0b010, x0, %0, 0x4" : : "r" (addr)); \
  })

#define cbo_inval_all() ({ \
  __asm__ __volatile__ (".insn i 0x0f, 0b111, x0, x0, 0x0" : :); \
  })

#define cbo_clean_all() ({ \
  __asm__ __volatile__ (".insn i 0x0f, 0b111, x0, x0, 0x1" : :); \
  })

#define cbo_flush_all() ({ \
  __asm__ __volatile__ (".insn i 0x0f, 0b111, x0, x0, 0x2" : :); \
  })

#define tensor_weight_load0(addr) ({ \
  __asm__ __volatile__ (".insn i 0x0b, 0b000, %0, %0, 0" : : "r" (addr)); \
  })

#define tensor_weight_load1(addr) ({ \
  __asm__ __volatile__ (".insn i 0x0b, 0b001, %0, %0, 0" : : "r" (addr)); \
  })

#define tensor_accum_load0(addr) ({ \
  __asm__ __volatile__ (".insn i 0x0b, 0b010, %0, %0, 0" : : "r" (addr)); \
  })

#define tensor_accum_load1(addr) ({ \
  __asm__ __volatile__ (".insn i 0x0b, 0b011, %0, %0, 0" : : "r" (addr)); \
  })

#define tensor_csr_ld(csr) ({ unsigned long __tmp; \
  __asm__ __volatile__ (".insn i 0x0b, 0b100, %0, x0, %1" : "=r"(__tmp) : "I"(csr)); \
  __tmp; })

#define tensor_csr_st(csr, val) ({ \
  __asm__ __volatile__ (".insn i 0x0b, 0b101, x0, %0, " #csr "" : : "rK"(val)); \
  })

#endif

