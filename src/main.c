#ifndef STD_TRYTE_H
#define STD_TRYTE_H
#include "std/tryte.h"
#endif

#ifndef MESA_TRYTE_H
#define MESA_TRYTE_H
#include "mesa/tryte.h"
#endif

#ifndef MESA_REGISTERS_H
#define MESA_REGISTERS_H
#include "mesa/registers.h"
#endif

#ifndef MESA_ALU_H
#define MESA_ALU_H
#include "./mesa/alu.h"
#endif

#ifndef STD_OP_H
#define STD_OP_H
#include "std/op.h"
#endif

#ifndef STD_STR_H
#define STD_STR_H
#include "std/str.h"
#endif

// Default memory is 3MtT
#define MEMORY_SIZE (3 * METRI)

// Memory
__tryte_buffer(memory, MEMORY_SIZE);

// Extract tryte from memory
void pop_tryte() {
    ALU_add(IP, ONE);
    set_tryte(OP, 0, get_tryte(memory, read_tryte(IP)));
}

int main(int argc, char const* argv[]) {

    // load 4
    // add  4
    // stor 4
    // halt
    // 1

    uint64_t i = 0;
    char buffer;
    uint64_t file = open("./alg.ter");
    while(read(file, &buffer, 1)) memory[i++] = buffer;

    // __tryte(t);
    // __fill_tryte(t, 0, 4, 64);
    // set_tryte(memory, 0, t);    // LOAD

    // __fill_tryte(t, 0, 2, 64);
    // set_tryte(memory, 1, t);    // 7

    // __fill_tryte(t, 0, 4, 128);
    // set_tryte(memory, 2, t);    // MATH

    // __fill_tryte(t, 0, 2, 64);
    // set_tryte(memory, 3, t);    // 7

    // __fill_tryte(t, 0, 4, 0);
    // set_tryte(memory, 4, t);    // STORE

    // __fill_tryte(t, 0, 2, 64);
    // set_tryte(memory, 5, t);    // 7

    // __fill_tryte(t, 0, 5, 64);
    // set_tryte(memory, 6, t);    // HALT

    // __fill_tryte(t, 0, 0, 64);
    // set_tryte(memory, 7, t);    // 1

    do {
        set_tryte(OP, 0, get_tryte(memory, read_tryte(IP)));
        switch(read_tryte(OP)) {
            case NOOP:
                puts("NOOP\n");
                break;
            case COMP:
                puts("COMP\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case JUMP:
                puts("JUMP\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case JMPG:
                puts("JMPG\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case JMPL:
                puts("JMPL\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case JMPGE:
                puts("JMPGE\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case JMPLE:
                puts("JMPLE\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case JMPE:
                puts("JMPE\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case JMPN:
                puts("JMPN\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case STORE:
                puts("STORE\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case LOAD:
                puts("LOAD\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case MATH:
                puts("MATH\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case CALL:
                puts("CALL\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case HALT:
                puts("HALT\n");
                break;
        }
        ALU_add(IP, ONE);
    } while(read_tryte(OP) != HALT);

    // __tryte(a) = {85, 106, 0};
    // __tryte(b) = {85, 21, 64};

    // puts(tryte_to_bstring(a));
    // puts(" + ");
    // puts(tryte_to_bstring(b));
    // puts(" = ");
    // ALU_add(a, b);
    // puts(tryte_to_bstring(a));
    // puts("\n");

    // for(uint8_t i = 0; i < 9; i++) {
    //     puts(batata(i % 3));
    //     puts(" sum ");
    //     puts(batata(i / 3));
    //     puts(" = ");
    //     puts(batata(__sum(i % 3, i / 3)));
    //     puts("\n");
    // }

    // __tryte(foo) = __tryteMIN;

    // for(uint16_t i = 0; i <= TRYTE_MAX; i++) {
    //     puts(btryte_to_string(foo));
    //     puts(" = ");
    //     puts(itoa(read_btryte(foo)));
    //     puts("\n");
    //     ALU_add(foo, ONE);
    // }
}