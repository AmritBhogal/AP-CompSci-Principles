
SECTION .text
GLOBAL start
start:
    PUSH    R8
    PUSH    R9
    MOV     R8, [REL MSG]
    MOV     R9, MSG_LEN
    CALL    SYSTEM_PRINT
    RET

%include "../print.asm"

SECTION .data

MSG:        DB  "SegmenBASEDtion fault!!!", NEWLINE, NULL
MSG_LEN:    EQU $-MSG 

%include "../common.inc"
