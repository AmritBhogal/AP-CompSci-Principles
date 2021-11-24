
SECTION .text

GLOBAL SYSTEM_PRINT
SYSTEM_PRINT:
    MOV     RAX, SYSTEM_WRITE_ADDRESS
    MOV     RDI, 0x1
    LEA     RSI, R8
    MOV     RDX, R9
    SYSCALL
    RET

SECTION .data

%include "../common.inc"
