#ifndef STD_INT_H
#define STD_INT_H
#include "../std/int.h"
#endif

#ifndef TERNARY_DEF_H
#define TERNARY_DEF_H
#include "def.h"
#endif

// Byte index of last tryte of specified byte
uint64_t tryte_a(uint64_t t) {
    return (uint64_t)t
        + ((uint64_t)t % TRIT_BIT != (uint64_t)t / TRYTE_TRIT % TRIT_BIT)
        + ((uint64_t)t % TRYTE_TRIT >= TRYTE_TRIT - TRIT_BIT);
}

// Byte index of specified tryte
uint64_t tryte_b(uint64_t t) {
    return (uint64_t)t * TRIT_BIT 
        + ((uint64_t)t / BYTE_TRIT);
}

// Set tryte in memory
void tryteset(__tryte_ptr(memory), uint64_t address, __tryte(t)) {
    uint64_t byte = (uint64_t)tryte_b((uint64_t)memory - address);
    uint8_t offset = byte % TRYTE_TRIT;
    uint8_t mask = 0xff >> offset;
    memory[address + 0] &= ~mask;
    memory[address + 0] |= t[0] >> offset;
    memory[address + 1] = 0;
    memory[address + 1] |= t[0] << CHAR_BIT - offset;
    memory[address + 1] |= t[1] >> offset;
    mask >>= TRIT_BIT;
    memory[address + 2] &= mask;
    memory[address + 2] |= t[1] << CHAR_BIT - offset;
    memory[address + 2] |= (t[2] & 192) >> offset; // 192 = 0b11000000 = Last byte mask for normal tryte
}

// Print trits in provided address
const char *memview(__tryte_ptr(memory), uint64_t begin, uint64_t end) {
    static char bitBuffer[256 * 9 + 1]; // TEMP LENGTH
    uint32_t p = 0;
    for(uint64_t i = begin; i < end; i++) {
        bitBuffer[p++] = ':';
        bitBuffer[p++] = ' ';
        uint8_t q;
        for(uint8_t j = 0; j < CHAR_BIT; j++) {
            if(i % TRIT_BIT == i / TRYTE_TRIT % TRIT_BIT - (i % TRYTE_TRIT == TRYTE_TRIT - 1)
                && j == i % TRYTE_TRIT) {
                bitBuffer[p++] = '|';
                bitBuffer[p++] = ' ';
            }

            if(j & 1) {
                bitBuffer[p++] = (memory[i] & (1 << (CHAR_BIT - 1 - j)))
                    ? q ? 'E' : '1'
                    : q ? '2' : '0';
                bitBuffer[p++] = ' ';
            } else q = !!(memory[i] & (1 << (CHAR_BIT - 1 - j)));
        }
    }
    bitBuffer[p] = '\0';
    return bitBuffer;
}