#ifndef BP_UTILS_H
#define BP_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "bsg_newlib_intf.h"
#include "aviary.h"
#include "config.h"
#include "host.h"
#include "encoding.h"

uint64_t bp_get_hart();

void bp_barrier_end(volatile uint64_t *barrier_address, uint64_t total_num_cores);

// Prints the given nibble as a hex character. 0 <= nibble <= 0xf.
void bp_hprint(uint8_t nibble);

// Prints the provided ASCII character.
void bp_cprint(uint8_t ch);

// Prints the given value as a 16-nibble hex number, preceded by "0x".
void bp_hprint_uint64(uint64_t val);

void bp_finish(uint8_t code);

void bp_print_string(char *str);

void bp_panic(char *message);

uint32_t bp_param_get(uint64_t addr);

#ifdef __cplusplus
}
#endif

#endif
