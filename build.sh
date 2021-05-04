#!/bin/sh

exename="tracer"

gcc -pedantic -s -O2 -Werror \
-nostdlib \
-fno-asynchronous-unwind-tables \
-fdata-sections \
-Wl,--gc-sections \
-Wa,--noexecstack \
-fno-builtin \
-fno-stack-protector \
-static \
src/tracer.S src/tracer.c \
-o $exename \
\
&& strip -R .comment $exename