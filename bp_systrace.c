#include <machine/systrace.h>
#include "bp_host.h"

#ifdef SYSTRACE
#define SYSTRACE_BASE_ADDR ((uint32_t *)(HOST_DEV_BASE_ADDR | 0x05000))

int code_tick;
uint64_t mcycle_tick;

void sys_tick(int code) {
  code_tick = code;
  __asm__ __volatile__ ("csrr %0, mcycle" : "=r"(mcycle_tick));
}

void sys_tock() {
  uint64_t mcycle_tock, mcycle_delta;
  __asm__ __volatile__ ("csrr %0, mcycle" : "=r"(mcycle_tock));
  mcycle_delta = mcycle_tock - mcycle_tick;

  //data format: {11-bit code, 21-bit mcycle}
  uint32_t data = ((uint32_t)mcycle_delta & 0x1FFFFF) | (((uint32_t)code_tick & 0x7FF) << 21);
  *(SYSTRACE_BASE_ADDR) = data;
}
#else
void sys_tick(int code) {}
void sys_tock() {}
#endif
