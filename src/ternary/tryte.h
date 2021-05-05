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
    return t * TRIT_BIT + t / BYTE_TRIT;
}

// Set tryte in memory
void tryteset(__tryte_ptr(memory), uint64_t address, __tryte(t)) {
    uint64_t byte = tryte_b(address);
    uint8_t offset = byte % TRYTE_TRIT;
    uint8_t mask = 0xff >> offset;
    memory[byte + 0] &= ~mask;
    memory[byte + 0] |= t[0] >> offset;
    memory[byte + 1] =  t[0] << CHAR_BIT - offset;
    memory[byte + 1] |= t[1] >> offset;
    mask >>= TRIT_BIT;
    memory[byte + 2] &= mask;
    memory[byte + 2] |= t[1] << CHAR_BIT - offset;
    memory[byte + 2] |= (t[2] & 192) >> offset; // 192 = 0b11000000 = Last byte mask for normal tryte
}

// Get tryte from memory
__tryte_ret tryteget(__tryte_ptr(memory), uint64_t address) {
    __tryte_buffer(t, 1);
    uint64_t byte = tryte_b(address);
    uint8_t offset = byte % TRYTE_TRIT;
    t[0] =  memory[byte + 0] << offset;
    t[0] |= memory[byte + 1] >> CHAR_BIT - offset;
    t[1] =  memory[byte + 1] << offset;
    t[1] |= memory[byte + 2] >> CHAR_BIT - offset;
    t[2] =  memory[byte + 2] << offset;
    return t;
}

// Print up to 1 KT beginning on provided address
const char *memview(__tryte_ptr(memory), uint64_t address, uint64_t count) {
    static char memBuffer[(HEPTA_TRIT + 1) * KITRI + 1]; // TEMP LENGTH
    uint32_t p = 0;
    for(uint64_t i = 0; i < count; i++) {
        __tryte_ret t = tryteget(memory, address + i);
        memBuffer[p++] = '|';
        for(uint8_t j = 0; j < TRYTE_TRIT; j += HEPTA_TRIT) {
            // 0tX00 +
            memBuffer[p] = ((t[__byte_of_trit(j + 0)] & 3 // 3 = 0b11
                << (BYTE_TRIT - 1 - (j + 0) % BYTE_TRIT) * TRIT_BIT)
                >> (BYTE_TRIT - 1 - (j + 0) % BYTE_TRIT) * TRIT_BIT) * 9 // 3 to the power of 2
            // 0t0X0 +
                                + ((t[__byte_of_trit(j + 1)] & 3 // 3 = 0b11
                << (BYTE_TRIT - 1 - (j + 1) % BYTE_TRIT) * TRIT_BIT)
                >> (BYTE_TRIT - 1 - (j + 1) % BYTE_TRIT) * TRIT_BIT) * 3 // 3 to the power of 1
            // 0t00X
                                + ((t[__byte_of_trit(j + 2)] & 3 // 3 = 0b11
                << (BYTE_TRIT - 1 - (j + 2) % BYTE_TRIT) * TRIT_BIT)
                >> (BYTE_TRIT - 1 - (j + 2) % BYTE_TRIT) * TRIT_BIT) * 1; // 3 to the power of 0
            memBuffer[p] += '0' + (memBuffer[p] >= 10) * ('A' - '9' - 1);
            if(memBuffer[p] > 'Q') memBuffer[p] = '?';
            p++;
        }
    }
    memBuffer[p] = '\0';
    return memBuffer;
}