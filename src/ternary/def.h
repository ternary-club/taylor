#ifndef UTILS_MATH_H
#define UTILS_MATH_H
#include "../utils/math.h"
#endif

#ifndef STD_INT_H
#define STD_INT_H
#include "../std/int.h"
#endif

// 1 char = 8 bits
#define CHAR_BIT 8

// 1 trit = 2 bits
#define TRIT_BIT CEIL(3, 2)

// 1 tryte = 9 trits
#define TRYTE_TRIT 9

// 1 byte = 4 trits
#define BYTE_TRIT (CHAR_BIT / TRIT_BIT)

// 1 tryte = 3 bytes
#define TRYTE_BYTE (CEIL(TRYTE_TRIT, BYTE_TRIT))

// 1 heptavintimal character = 3 trits
#define HEPTA_TRIT (27 / TRYTE_TRIT)

// 1 Kitri (Kt) = 3^7 = 2187
#define KITRI 2187L

// 1 Metri (Mt) = 3^7^2 = 2187^2 = 4782969
#define METRI 4782969L

// 1 Gitri (Gt) = 3^7^3 = 2187^3 = 10460353203
#define GITRI 10460353203LL

// 1 Tetri (Tt) = 3^7^4 = 2187^4 = 22876792454961
#define TETRI 22876792454961LL

// Tryte macro declaration
#define __tryte(name) uint8_t name[TRYTE_BYTE]

// Tryte buffer macro declaration
#define __tryte_buffer(name, count) static uint8_t name[CEIL(count * TRYTE_TRIT, BYTE_TRIT)]

// Tryte pointer without name (return type) macro declaration
#define __tryte_ret uint8_t*

// Tryte pointer macro declaration
#define __tryte_ptr(name) uint8_t *name

// Byte a trit is in
#define __byte_of_trit(t) ((t)*TRIT_BIT / CHAR_BIT)

// A 0 valued tryte
__tryte(tryteEMPTY) = {0U, 0U, 0U};

// A 19683 valued tryte
__tryte(tryteFULL) = {170U, 170U, 128U};