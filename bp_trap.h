#ifndef BP_TRAP_H
#define BP_TRAP_H
int register_trap_handler(void (*handler)(uint64_t *, uint64_t, uint64_t),
        int index, int is_exception);
void bp_trap_handler(uint64_t *regs, uint64_t mcause, uint64_t instr);
#endif
