# TAILOR
 TernAry vIrtuaL prOcessoR

0  NOOP
1  COMP    addr
2  JUMP    addr
3  JMPG    addr
4  JMPL    addr
5  JMPGE   addr
6  JMPLE   addr
7  JMPE    addr
8  JMPN    addr
9  STORE   addr
A  LOAD    addr
B  ADD     addr
C  SUB     addr
D  MUL     addr
E  DIV     addr
F  CALL    int
G  HALT

Folder scopes:
driver  = Code related to the communication of TAILOR and the amd64 binary physical processor.
meta    = Low-level code related to virtual scope of this processor.
mesa    = Low-level code related to physical scope of this processor.
std     = Code related to this implementation.