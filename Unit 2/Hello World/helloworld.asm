GLOBAL start

SECTION .text

SYSPRINT:
    PUSHA

    

    POPA
    RET

start:
    MOV     RAX, SYSTEM_WRITE_ADDRESS                ; System write function
    MOV     RDI, 0x1                                ; 0x1 is standard output (arg for sys write)

    LEA     RSI, [REL MSG]                          ; Loads the address of the message into the RSI register
                                                    ; we have to get the relitive address of the message (REL)
                                                    ; because in the MachO-64x binary format (macOS 64 bit binaries)
                                                    ; the program accesses the top 2gb of the 4gb allocated to it.

    MOV     RDX, MSG_LEN                            ; Load the length of the message
    SYSCALL                                         ; Call the function!

    ; Now we exit ;

    MOV     RAX, SYSTEM_EXIT_ADDRESS                ; Address of the exit function
    MOV     RDI, 0x0                                ; Return value
    SYSCALL
    

SECTION .data

%include "common.inc"

MSG:     DB     "HELLO, WORLD!", NEWLINE, NULL
MSG_LEN: EQU    $-MSG
