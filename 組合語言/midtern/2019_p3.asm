INCLUDE Irvine32.inc
ExitProcess PROTO,dwExitCode:DWORD

.data
NUM1 DWORD 00001234H,56780000H 
NUM2 DWORD 0ABCD0000H,0EF123456H
NUM3 DWORD 3 dup (0) 
CARRY DWORD 0
Step DWORD 0

.code
main PROC
	mov eax,num1
	add eax,num2
	mov num3,eax
	jc IFCF
	mov CARRY,0
	mov Step,2
	jmp Step2
IFCF:
	mov CARRY,1
	cmp Step,2
	je Step2
	jmp Step3
Step2:	
	mov Step,3
	mov eax,CARRY
	mov CARRY,0
	add eax,num1+4
	add eax,num2+4
	mov num3+4,eax
	jc IFCF
	jmp Step3
Step3:
	mov eax,CARRY
	mov NUM3+8,eax
	jmp FINAL
FINAL:
	mov eax,NUM3
	CALL WRITEHEX
	call crlf
	mov eax,NUM3+4
	CALL WRITEHEX
	call crlf
	mov eax,NUM3+8
	CALL WRITEHEX

	INVOKE ExitProcess,0
main ENDP
END main
