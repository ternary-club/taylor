#ifndef DRIVER_STD_H
#define DRIVER_STD_H
#include "../driver/std.h"
#endif

#ifndef STD_INT_H
#define STD_INT_H
#include "int.h"
#endif

// Unsigned 8 bytes integer to string conversion
const char *itoa(uint64_t value) {
    static char uintBuffer[128];
    uint8_t size;
    uint64_t test = value;
    while(test / 10) {
        test /= 10;
        size++;
    }

    uint8_t index = 0;
    while(value / 10) {
        uint8_t remainder = value % 10;
        value /= 10;
        uintBuffer[size - index] = remainder + '0';
        index++;
    }
    uint8_t remainder = value % 10;
    uintBuffer[size - index] = remainder + '0';
    uintBuffer[size + 1] = '\0';
    return uintBuffer;
}

uint32_t strlen(char const *str) {
    char const *p;
    for (p = str; *p; ++p);
    return p - str;
}

internal
uintptr puts(char const *str) {
    return write(stdout, str, strlen(str));
}