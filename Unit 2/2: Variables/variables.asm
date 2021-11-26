%include "../common.inc"

SECTION .text
GLOBAL start
start:
    SYSPRINT    MSG, MSG_LEN
    SYSPRINT    MSG2, MSG2_LEN
    CALL        SYSTEM_EXIT

%include "../common.asm"

SECTION .data



MSG:        DB  "SegmenBASEDtion fault!!!", 0xA, 0x0
MSG_LEN:    EQU $-MSG 

MSG2:        DB  "SegmenBASEDtion fault 2!!!", 0xA, 0x0
MSG2_LEN:    EQU $-MSG 

