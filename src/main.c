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

#ifndef STD_OP_H
#define STD_OP_H
#include "std/op.h"
#endif

#ifndef DRIVER_IO_H
#define DRIVER_IO_H
#include "driver/io.h"
#endif

// Default memory is 3MtT
#define MEMORY_SIZE (3 * METRI)

int main(int argc, char const* argv[]) {
    // Memory
    __tryte_buffer(memory, MEMORY_SIZE);

    // 0 load 4
    // 1 add  4
    // 2 stor 4
    // 3 halt
    // 4 1
    
    __tryte(t);
    __fill_tryte(t, 0, 4, 64);
    set_tryte(memory, 0, t);    // LOAD

    __fill_tryte(t, 0, 2, 64);
    set_tryte(memory, 1, t);    // 7

    __fill_tryte(t, 0, 4, 128);
    set_tryte(memory, 2, t);    // ADD

    __fill_tryte(t, 0, 2, 64);
    set_tryte(memory, 3, t);    // 7

    __fill_tryte(t, 0, 4, 0);
    set_tryte(memory, 4, t);    // STORE

    __fill_tryte(t, 0, 2, 64);
    set_tryte(memory, 5, t);    // 7

    __fill_tryte(t, 0, 6, 64);
    set_tryte(memory, 6, t);    // HALT

    __fill_tryte(t, 0, 0, 64);
    set_tryte(memory, 7, t);    // 1

    INSTRUCTION in = NOOP;
    while(in != HALT) {
        set_tryte(op, 0, get_tryte(memory, read_tryte(ip)));
        in = read_tryte(op);

        switch(in) {
            case NOOP:
                puts("NOOP\n");
                break;
            case COMP:
                puts("COMP\n");
                ip++;
                break;
            case JUMP:
                puts("JUMP\n");
                ip++;
                break;
            case JMPG:
                puts("JMPG\n");
                ip++;
                break;
            case JMPL:
                puts("JMPL\n");
                ip++;
                break;
            case JMPGE:
                puts("JMPGE\n");
                ip++;
                break;
            case JMPLE:
                puts("JMPLE\n");
                ip++;
                break;
            case JMPE:
                puts("JMPE\n");
                ip++;
                break;
            case JMPN:
                puts("JMPN\n");
                ip++;
                break;
            case STORE:
                puts("STORE\n");
                ip++;
                break;
            case LOAD:
                puts("LOAD\n");
                ip++;
                break;
            case ADD:
                puts("ADD\n");
                ip++;
                break;
            case SUB:
                puts("SUB\n");
                ip++;
                break;
            case MUL:
                puts("MUL\n");
                ip++;
                break;
            case DIV:
                puts("DIV\n");
                ip++;
                break;
            case CALL:
                puts("CALL\n");
                ip++;
                break;
            case HALT:
                puts("HALT\n");
                break;
        }
        ip++;
    }

    // char buffer[200];
    // uint64_t file = open("./exec.txt");
    // read(file, buffer, 200);
    // puts(buffer);
    // puts("\n");
}