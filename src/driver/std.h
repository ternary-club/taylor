#ifndef DRIVER_DEF_H
#define DRIVER_DEF_H
#include "def.h"
#endif

typedef unsigned long int uintptr;
typedef long int intptr;

#define internal static

void *syscall3(
    uintptr number,
    void *arg1,
    void *arg2,
    void *arg3
);

#define stdout 1

internal
intptr write(int fd, void const *data, uintptr nbytes) {
    return (intptr)
    syscall3(
        SYS_write,
        (void*)(intptr)fd,
        (void*)data,
        (void*)nbytes
    );
}
