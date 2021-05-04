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
    __tryte_buffer(memory, 5);
    __tryte(t) = {138, 56, 128};
    tryteset(memory, 0, t);
    puts(memview(memory, 0, 3));
    puts("\n");
}