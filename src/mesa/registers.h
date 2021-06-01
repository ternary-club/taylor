#ifndef STD_TRYTE_H
#define STD_TRYTE_H
#include "../std/tryte.h"
#endif

// General purpose registers
__triple_word(__GENERAL)[HEPTA_VINTIMAL];

// Accumulator
__tryte(__ACC);
// Instruction pointer
__tryte(__IP);
// Operation register
__trybble(__OP);
// Argument register
__tryte(__AR);