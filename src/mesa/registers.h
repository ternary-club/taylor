#ifndef STD_TRYTE_H
#define STD_TRYTE_H
#include "../std/tryte.h"
#endif

// Flags register
// CARRY (1 trit) (0 = no carry, 1 = carry 1, 2 = carry 2)
// SIGN (1 trit) (0 = -, 1 = 0, 2 = +)
// OVERFLOW/PARITY (1 trit) (0 = even, 1 = odd, 2 = overflow)
__trybble(__FLAGS);

__word(__GENERAL);

// Accumulator
__tryte(__ACC);
// Instruction pointer
__tryte(__IP);
// Operation register
__tryte(__OP);
// Argument register
__tryte(__AR);