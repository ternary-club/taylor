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
    char buffer;
    intptr file = open("./exec.ter");
    if(file <= 0) return 1;

    uint64_t i = 0;
    while(read(file, &buffer, 1)) memory[i++] = buffer;

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
            case ADD:
                puts("ADD\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case SUB:
                puts("SUB\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case MUL:
                puts("MUL\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case DIV:
                puts("DIV\t");
                pop_tryte();
                puts(itoa(read_tryte(OP)));
                puts("\n");
                break;
            case MOD:
                puts("MOD\t");
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
}