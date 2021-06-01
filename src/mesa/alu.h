#ifndef STD_TRYTE_H
#define STD_TRYTE_H
#include "../std/tryte.h"
#endif

#ifndef MESA_REGISTERS_H
#define MESA_REGISTERS_H
#include "registers.h"
#endif

#ifndef MESA_LOGIC_H
#define MESA_LOGIC_H
#include "../mesa/logic.h"
#endif

#ifndef STD_STR_H
#define STD_STR_H
#include "../std/str.h"
#endif

// Result variable
__tryte(__alu_RESULT);

// CARRY (1 trit) (0 = no carry, 1 = carry 1, 2 = carry 2)
// SIGN (1 trit) (0 = -, 1 = 0, 2 = +)
// OVERFLOW/PARITY (1 trit) (0 = even, 1 = odd, 2 = overflow)
__trybble(__alu_FLAGS);

void ALU_add(__tryte_ptr(target), __tryte_ptr(source)) {
    __trit(carry) = 1;
    for(uint8_t i = 0; i < TRYTE_TRIT; i++) {
        uint8_t byte = __byte_of_trit(i);
        uint8_t offset = __trit_offset(i);
        uint8_t a = (source[byte] & b11 << offset) >> offset;
        uint8_t b = (target[byte] & b11 << offset) >> offset;
        puts("| ");
        puts(tryte_to_bstring(target));
        puts("\n");
        puts(itoa(offset));
        puts("\n");
        target[byte] &= ~(b11 << offset);
        target[byte] |= __sum(__sum(a, b), carry) << offset;
        carry = __any(__con(a, b), __con(__sum(a, b), carry));
    }
    puts("| ");
    puts(tryte_to_bstring(target));
    puts("\n");
    if(!!carry) __alu_FLAGS |= 192; // Set carry (0b11000000)
}