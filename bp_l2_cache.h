
#ifndef BP_L2_CACHE_H
#define BP_L2_CACHE_H

#include <stdio.h>

#define CACHE_DEV_BASE_ADDR 0x00400000
#define CACHE_DEV           4

#define AFL_OP        0b000000
#define AFLINV_OP     0b001000
#define AINV_OP       0b010000
#define ALOCK_OP      0b011000

#define TAGFL_OP      0b100000
#define TAGLV_OP      0b101000
#define TAGLA_OP      0b110000
#define TAGST_OP      0b111000

#define L2_INDEX_OFFSET 6
#define L2_INDEX_MASK   0xff
#define L2_WAY_OFFSET   14
#define L2_WAY_MASK     0x7
#define L2_BANK_OFFSET  17
#define L2_BANK_MASK    0x7
#define L2_DEV_OFFSET   20
#define L2_DEV_MASK     0xf

#define L2_CCE_OFFSET   20
#define L2_CCE_MASK     0x7f

  void l2cache_afl(uintptr_t address);

  void l2cache_aflinv(uintptr_t address);

  void l2cache_ainv(uintptr_t address);

  void l2cache_alock(uintptr_t address);

  void l2cache_aunlock(uintptr_t address);

  void l2cache_tagfl(uint64_t cce, uint64_t slice, uint64_t bank, uint64_t way, uint64_t index);

  void l2cache_taglv(uint64_t cce, uint64_t slice, uint64_t bank, uint64_t way, uint64_t index);

  void l2cache_tagla(uint64_t cce, uint64_t slice, uint64_t bank, uint64_t way, uint64_t index);

  void l2cache_tagst(uint64_t cce, uint64_t slice, uint64_t bank, uint64_t way, uint64_t index, uint64_t tag);

#endif

