#!/bin/sh

exename="tracer"

gcc -std=c89 -pedantic -s -O2 -Wall -Werror \
-nostdlib \
-fno-unwind-tables \
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