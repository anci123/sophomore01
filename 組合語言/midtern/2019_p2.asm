INCLUDE Irvine32.inc
ExitProcess PROTO,dwExitCode:DWORD

.data
Str1 byte "123aefad656EFS",0
num1 byte 0
num2 byte 0
num3 byte 0

.code
main PROC
	mov ebx,0
	jmp DECIDE
DECIDE:
	mov eax,0
	mov al,Str1[ebx]
	call WRITECHAR


	cmp Str1[ebx],0
	jne NUMSEG
	jmp ENDPRO

NUMSEG:
	cmp Str1[ebx],'0'
	jl DECIDE
	cmp Str1[ebx],'9'
	jg UPSEG
	
	inc num1
	inc ebx
	jmp DECIDE

UPSEG:
	cmp Str1[ebx],'Z'
	jg LOWSEG

	inc num2
	inc ebx
	jmp DECIDE

LOWSEG:	
	cmp Str1[ebx],'z'
	jg DECIDE

	inc num3
	inc ebx
	jmp DECIDE

ENDPRO:
	mov eax,0
	mov bl,num1
	mov al,num2
	mov ah,num3


	INVOKE ExitProcess,0
main ENDP
END main
