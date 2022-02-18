#include <stdint.h>
#include "bp_trap.h"
#include "emulation.h"

#define EXCEPTION_TOTAL            16
#define INTERRUPT_TOTAL            12

static void (*exception_handler[EXCEPTION_TOTAL])(uint64_t *, uint64_t, uint64_t) =
{
  bp_unhandled_trap_abort,        // 0
  bp_unhandled_trap_abort,        // 1
  bp_emulate_illegal_instruction, // 2
  bp_unhandled_trap_abort,        // 3
  bp_unhandled_trap_abort,        // 4
  bp_unhandled_trap_abort,        // 5
  bp_unhandled_trap_abort,        // 6
  bp_unhandled_trap_abort,        // 7
  bp_unhandled_trap_abort,        // 8
  bp_unhandled_trap_abort,        // 9
  bp_unhandled_trap_abort,        // 10
  bp_unhandled_trap_abort,        // 11
  bp_unhandled_trap_abort,        // 12
  bp_unhandled_trap_abort,        // 13
  bp_unhandled_trap_abort,        // 14
  bp_unhandled_trap_abort         // 15
};

static void (*interrupt_handler[INTERRUPT_TOTAL])(uint64_t *, uint64_t, uint64_t) =
{
  bp_unhandled_trap_abort,        // 0
  bp_unhandled_trap_abort,        // 1
  bp_unhandled_trap_abort,        // 2
  bp_unhandled_trap_abort,        // 3
  bp_unhandled_trap_abort,        // 4
  bp_unhandled_trap_abort,        // 5
  bp_unhandled_trap_abort,        // 6
  bp_unhandled_trap_abort,        // 7
  bp_unhandled_trap_abort,        // 8
  bp_unhandled_trap_abort,        // 9
  bp_unhandled_trap_abort,        // 10
  bp_unhandled_trap_abort,        // 11
};

int register_trap_handler(void (*handler)(uint64_t *, uint64_t, uint64_t),
        unsigned long mcause)
{
  unsigned index = mcause & ~(1UL << 63);
  int is_exception = !(mcause & (1UL << 63));
  if(is_exception) {
    // exception handler registration
    if(index < EXCEPTION_TOTAL) {
      exception_handler[index] = handler;
      return 0; // success
    }
    return -1; // fail
  } else {
    // interrupt handler registration
    if(index < INTERRUPT_TOTAL) {
      interrupt_handler[index] = handler;
      return 0; // success
    }
    else {
      return -1; // fail
    }
  }
}

void bp_trap_handler(uint64_t *regs, uint64_t mcause, uint64_t instr)
{
  int is_interrupt = !!(mcause & (1UL << 63));
  int index = mcause & ~(1UL << 63);
  if(is_interrupt) {
    if(index >= 0 && index < INTERRUPT_TOTAL)
      interrupt_handler[index](regs, mcause, instr);
    else {
      // illegal trap code
      bp_unhandled_trap_abort(regs, mcause, instr);
    }
  } else {
    if(index >= 0 && index < EXCEPTION_TOTAL)
      exception_handler[index](regs, mcause, instr);
    else {
      // illegal trap code
      bp_unhandled_trap_abort(regs, mcause, instr);
    }
  }
}

