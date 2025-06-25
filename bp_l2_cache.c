
#include <bp_l2_cache.h>
#include <bp_utils.h>

  void l2cache_afl(uintptr_t address) {
    uintptr_t pkt_addr = 0;
    uintptr_t pkt_data = 0;
    uintptr_t cce = (address >> L2_CCE_OFFSET) & L2_CCE_MASK;
    uintptr_t dev = (address >> L2_DEV_OFFSET) & L2_DEV_MASK;

    pkt_addr |= (cce << L2_CCE_OFFSET);
    pkt_addr |= (dev << L2_DEV_OFFSET);
    pkt_addr |= AFL_OP;

    pkt_data  = address;

    *((uint64_t *)pkt_addr) = pkt_data;
  }

  void l2cache_aflinv(uintptr_t address) {
    uintptr_t pkt_addr = 0;
    uintptr_t pkt_data = 0;
    uintptr_t cce = (address >> L2_CCE_OFFSET) & L2_CCE_MASK;
    uintptr_t dev = (address >> L2_DEV_OFFSET) & L2_DEV_MASK;

    pkt_addr |= (cce << L2_CCE_OFFSET);
    pkt_addr |= (dev << L2_DEV_OFFSET);
    pkt_addr |= AFLINV_OP;

    pkt_data  = address;

    *((uint64_t *)pkt_addr) = pkt_data;
  }

  void l2cache_ainv(uintptr_t address) {
    uintptr_t pkt_addr = 0;
    uintptr_t pkt_data = 0;
    uintptr_t cce = (address >> L2_CCE_OFFSET) & L2_CCE_MASK;
    uintptr_t dev = (address >> L2_DEV_OFFSET) & L2_DEV_MASK;

    pkt_addr |= (cce << L2_CCE_OFFSET);
    pkt_addr |= (dev << L2_DEV_OFFSET);
    pkt_addr |= AINV_OP;

    pkt_data  = address;

    *((uint64_t *)pkt_addr) = pkt_data;
  }

  void l2cache_alock(uintptr_t address) {
    uintptr_t pkt_addr = 0;
    uintptr_t pkt_data = 0;
    uintptr_t cce = (address >> L2_CCE_OFFSET) & L2_CCE_MASK;
    uintptr_t dev = (address >> L2_DEV_OFFSET) & L2_DEV_MASK;

    pkt_addr |= (cce << L2_CCE_OFFSET);
    pkt_addr |= (dev << L2_DEV_OFFSET);
    pkt_addr |= AINV_OP;

    pkt_data  = address;
    pkt_data |= 1;

    *((uint64_t *)pkt_addr) = pkt_data;
  }

  void l2cache_aunlock(uintptr_t address) {
    uintptr_t pkt_addr = 0;
    uintptr_t pkt_data = 0;
    uintptr_t cce = (address >> L2_CCE_OFFSET) & L2_CCE_MASK;
    uintptr_t dev = (address >> L2_DEV_OFFSET) & L2_DEV_MASK;

    pkt_addr |= (cce << L2_CCE_OFFSET);
    pkt_addr |= (dev << L2_DEV_OFFSET);
    pkt_addr |= AINV_OP;

    pkt_data  = address;
    pkt_data |= 0;

    *((uint64_t *)pkt_addr) = pkt_data;
  }

  void l2cache_tagfl(uint64_t cce, uint64_t slice, uint64_t bank, uint64_t way, uint64_t index) {
    uintptr_t pkt_addr = 0;
    uintptr_t pkt_data = 0;
    uintptr_t dev = CACHE_DEV + slice;

    pkt_addr |= (cce   << L2_CCE_OFFSET);
    pkt_addr |= (dev   << L2_DEV_OFFSET);
    pkt_addr |= (bank  << L2_BANK_OFFSET);
    pkt_addr |= (way   << L2_WAY_OFFSET);
    pkt_addr |= (index << L2_INDEX_OFFSET);
    pkt_addr |= TAGFL_OP;

    pkt_data  = 0;

    *((uint64_t *)pkt_addr) = pkt_data;
  }

  void l2cache_taglv(uint64_t cce, uint64_t slice, uint64_t bank, uint64_t way, uint64_t index) {
    uintptr_t pkt_addr = 0;
    uintptr_t pkt_data = 0;
    uintptr_t dev = CACHE_DEV + slice;

    pkt_addr |= (cce   << L2_CCE_OFFSET);
    pkt_addr |= (dev   << L2_DEV_OFFSET);
    pkt_addr |= (bank  << L2_BANK_OFFSET);
    pkt_addr |= (way   << L2_WAY_OFFSET);
    pkt_addr |= (index << L2_INDEX_OFFSET);
    pkt_addr |= TAGLV_OP;

    pkt_data  = 0;

    *((uint64_t *)pkt_addr) = pkt_data;
  }

  void l2cache_tagla(uint64_t cce, uint64_t slice, uint64_t bank, uint64_t way, uint64_t index) {
    uintptr_t pkt_addr = 0;
    uintptr_t pkt_data = 0;
    uintptr_t dev = CACHE_DEV + slice;

    pkt_addr |= (cce   << L2_CCE_OFFSET);
    pkt_addr |= (dev   << L2_DEV_OFFSET);
    pkt_addr |= (bank  << L2_BANK_OFFSET);
    pkt_addr |= (way   << L2_WAY_OFFSET);
    pkt_addr |= (index << L2_INDEX_OFFSET);
    pkt_addr |= TAGLA_OP;

    pkt_data  = 0;

    *((uint64_t *)pkt_addr) = pkt_data;
  }

  void l2cache_tagst(uint64_t cce, uint64_t slice, uint64_t bank, uint64_t way, uint64_t index, uint64_t tag) {
    uintptr_t pkt_addr = 0;
    uintptr_t pkt_data = 0;
    uintptr_t dev = CACHE_DEV + slice;

    pkt_addr |= (cce   << L2_CCE_OFFSET);
    pkt_addr |= (dev   << L2_DEV_OFFSET);
    pkt_addr |= (bank  << L2_BANK_OFFSET);
    pkt_addr |= (way   << L2_WAY_OFFSET);
    pkt_addr |= (index << L2_INDEX_OFFSET);
    pkt_addr |= TAGLA_OP;

    pkt_data  = tag;

    *((uint64_t *)pkt_addr) = pkt_data;
  }

