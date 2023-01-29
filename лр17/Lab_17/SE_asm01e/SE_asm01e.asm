.586P
.MODEL FLAT, STDCALL

includelib kernel32.lib
includelib libucrt.lib
includelib ..\Debug\SE_asm01d.lib

ExitProcess			PROTO: DWORD
SetConsoleTitleA	PROTO: DWORD
GetStdHandle		PROTO: DWORD
WriteConsoleA		PROTO: DWORD, : DWORD, : DWORD, : DWORD, : DWORD
EXTRN getmax: proc
EXTRN getmin: proc

.STACK 4096

.CONST 
consoletitle	DB 'SE_asm01e', 0
Arr				DD 0, 2, 3, 4, 5, 6, 8, 4, 3, 2

.DATA
result1			BYTE "getMax + getMin = ", 0
resultmin			DWORD 0
resultmax           DWORD 0
consolehandle	DD 0h

.CODE
main PROC

	invoke SetConsoleTitleA, offset consoletitle

	push -11
	call GetStdHandle
	mov consolehandle, eax

	push lengthof Arr
	push offset Arr
	call getmin

	mov resultmin, eax

	push lengthof Arr
	push offset Arr
	call getmax

	

	add resultmin, eax
	add resultmin, 30h
	mov eax, resultmin

	mov result1 + 18, al

	invoke WriteConsoleA, consolehandle, offset result1, sizeof result1, 0, 0

	push 0
	call ExitProcess

main ENDP

END main