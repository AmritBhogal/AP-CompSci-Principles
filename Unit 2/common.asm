
SECTION .text
GLOBAL SYSTEM_EXIT
SYSTEM_EXIT:
    MOV     RAX, 0x2000004
    XOR     RDI, RDI
    SYSCALL
    RET

%include "../print.asm"
