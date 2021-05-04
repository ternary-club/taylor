#ifndef DRIVER_STD_H
#define DRIVER_STD_H
#include "../driver/std.h"
#endif

internal
uintptr strlen(char const *str) {
    char const *p;
    for (p = str; *p; ++p);
    return p - str;
}

internal
uintptr puts(char const *str) {
    return write(stdout, str, strlen(str));
}