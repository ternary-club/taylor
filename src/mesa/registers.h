#ifndef STD_TRYTE_H
#define STD_TRYTE_H
#include "../std/tryte.h"
#endif

// Constant 1
__tryte(ONE) = __tryteONE;

// General purpose registers
__triple_word(GENERAL)[HEPTA_VINTIMAL];

// Accumulator
__tryte(ACC);
// Instruction pointer
__tryte(IP) = __tryteMIN;
// Operation register (SHOULD BE TRYBBLE)
__tryte(OP);
// Argument register
__tryte(AR);