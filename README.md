# TAILOR (**T**ern**A**ry v**I**rtua**L** pr**O**cesso**R**)

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