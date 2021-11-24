
%macro SYSPRINT 2
    PUSH    R8
    PUSH    R9 
    MOV     R8, %1
    MOV     R9, %2
    CALL    SYSTEM_PRINT
    POP     R9
    POP     R8
%endmacro
