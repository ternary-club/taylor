#ifndef DRIVER_STD_H
#define DRIVER_STD_H
#include "driver/std.h"
#endif

#ifndef TERNARY_DEF_H
#define TERNARY_DEF_H
#include "ternary/def.h"
#endif

#ifndef TERNARY_TRYTE_H
#define TERNARY_TRYTE_H
#include "ternary/tryte.h"
#endif

#ifndef STD_IO_H
#define STD_IO_H
#include "std/io.h"
#endif

// Default memory is 3MtT
#define MEMORY_SIZE (3 * METRI)

int main(int argc, char const* argv[]) {
    __tryte_buffer(memory, MEMORY_SIZE);
    __tryte(t);
    for(uint64_t i = 0; i < 111; i++) {
        t[0] = i + 237421 * i ^ 63295132;
        t[1] = i + 912476 * i ^ 78621549;
        t[2] = i + 546833 * i ^ 93811123;
        tryteset(memory, i, t);
    }
    puts(memview(memory, 0, 50));
    puts("\n");
}