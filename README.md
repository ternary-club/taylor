# TAYLOR (**T**ern**A**r**Y** virtua**L** pr**O**cesso**R**)

## Operation codes with parameters
0  **NOOP**
<br> 1  **COMP**   addr
<br> 2  **JUMP**   addr
<br> 3  **JMPG**   addr
<br> 4  **JMPL**   addr
<br> 5  **JMPGE**   addr
<br> 6  **JMPLE**   addr
<br> 7  **JMPE**    addr
<br> 8  **JMPN**    addr
<br> 9  **STORE**   addr
<br> A  **LOAD**    addr
<br> B  **ADD**     addr
<br> C  **SUB**     addr
<br> D  **MUL**     addr
<br> E  **DIV**     addr
<br> F  **CALL**    int
<br> G  **HALT**

Folder scopes:
<br> **driver**  = Code related to the communication of TAILOR and the amd64 binary physical processor.
<br> **meta**    = Low-level code related to the virtual scope of this processor.
<br> **mesa**    = Low-level code related to the physical scope of this processor.
<br> **std**     = Code related to this implementation.

LOAD 7
MATH 7
STORE 7
HALT
1

10 4 11 4 9 4 13 1

00000000 00000100 01
00000000 00000001 01
00000000 00000100 10
00000000 00000001 01
00000000 00000100 00
00000000 00000001 01
00000000 00000101 01
00000000 00000000 01

00000000 00000100 01000000 00000000 01010000 00000000 01001000 00000000 00000101 00000000 00000100 00000000 00000000 01010000 00000000 01010100 00000000 00000001
