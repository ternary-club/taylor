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

char *batata(uint8_t a) {
    static char b[2] = {0, 0};
    switch (a) {
        case 0:
            b[0] = '-';
            break;
        case 1:
            b[0] = '0';
            break;
        case 2:
            b[0] = '+';
            break;
        }
    return b;
}

int main(int argc, char const* argv[]) {
    // Memory
    __tryte_buffer(memory, MEMORY_SIZE);

    // 0 load 4
    // 1 add  4
    // 2 stor 4
    // 3 halt
    // 4 1
    
    // __tryte(t);
    // __fill_tryte(t, 0, 4, 64);
    // set_tryte(memory, 0, t);    // LOAD

    // __fill_tryte(t, 0, 2, 64);
    // set_tryte(memory, 1, t);    // 7

    // __fill_tryte(t, 0, 4, 128);
    // set_tryte(memory, 2, t);    // ADD

    // __fill_tryte(t, 0, 2, 64);
    // set_tryte(memory, 3, t);    // 7

    // __fill_tryte(t, 0, 4, 0);
    // set_tryte(memory, 4, t);    // STORE

    // __fill_tryte(t, 0, 2, 64);
    // set_tryte(memory, 5, t);    // 7

    // __fill_tryte(t, 0, 6, 64);
    // set_tryte(memory, 6, t);    // HALT

    // __fill_tryte(t, 0, 0, 64);
    // set_tryte(memory, 7, t);    // 1

    // INSTRUCTION in = NOOP;
    // while(in != HALT) {
    //     set_tryte(__OP, 0, get_tryte(memory, read_tryte(__IP)));
    //     in = read_tryte(__OP);

    //     switch(in) {
    //         case NOOP:
    //             puts("NOOP\n");
    //             break;
    //         case COMP:
    //             puts("COMP\n");
    //             __IP++;
    //             break;
    //         case JUMP:
    //             puts("JUMP\n");
    //             __IP++;
    //             break;
    //         case JMPG:
    //             puts("JMPG\n");
    //             __IP++;
    //             break;
    //         case JMPL:
    //             puts("JMPL\n");
    //             __IP++;
    //             break;
    //         case JMPGE:
    //             puts("JMPGE\n");
    //             __IP++;
    //             break;
    //         case JMPLE:
    //             puts("JMPLE\n");
    //             __IP++;
    //             break;
    //         case JMPE:
    //             puts("JMPE\n");
    //             __IP++;
    //             break;
    //         case JMPN:
    //             puts("JMPN\n");
    //             __IP++;
    //             break;
    //         case STORE:
    //             puts("STORE\n");
    //             __IP++;
    //             break;
    //         case LOAD:
    //             puts("LOAD\n");
    //             __IP++;
    //             break;
    //         case ADD:
    //             puts("ADD\n");
    //             __IP++;
    //             break;
    //         case SUB:
    //             puts("SUB\n");
    //             __IP++;
    //             break;
    //         case MUL:
    //             puts("MUL\n");
    //             __IP++;
    //             break;
    //         case DIV:
    //             puts("DIV\n");
    //             __IP++;
    //             break;
    //         case CALL:
    //             puts("CALL\n");
    //             __IP++;
    //             break;
    //         case HALT:
    //             puts("HALT\n");
    //             break;
    //     }
    //     __IP++;
    // }

    // char buffer[200];
    // uint64_t file = open("./exec.txt");
    // read(file, buffer, 200);
    // puts(buffer);
    // puts("\n");

    __tryte(a) = {85, 96, 64};
    __tryte(b) = {85, 86, 0};
    puts(tryte_to_bstring(a));
    puts("\n");
    puts(tryte_to_bstring(b));
    puts("\n");
    ALU_add(a, b);
    puts(tryte_to_bstring(a));
    puts("\n");
    
    // for(uint8_t i = 0; i < 9; i++) {
    //     puts(batata(i % 3));
    //     puts(" sum ");
    //     puts(batata(i / 3));
    //     puts(" = ");
    //     puts(batata(__sum(i % 3, i / 3)));
    //     puts("\n");
    // }
}