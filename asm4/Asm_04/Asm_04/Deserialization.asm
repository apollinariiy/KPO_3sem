.586
.MODEL FLAT, STDCALL
includelib kernel32.lib
ExitProcess PROTO : DWORD
.STACK 4096

.CONST

INT0 DWORD 123

.DATA

CHAR1 BYTE 1, 2, 3


.CODE
main PROC
START :
push - 1
call ExitProcess
main ENDP
end main
