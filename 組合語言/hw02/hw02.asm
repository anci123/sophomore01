
INCLUDE Irvine32.inc
ExitProcess PROTO,dwExitCode:DWORD

.data
Str1 byte 100 dup(0)
Str2 byte "Please input a string:",0
Str3 byte "Number:",0
Str4 byte "Uppercase:",0
Str5 byte "Lowercase:",0
Str6 byte "Other:",0

num1 byte 0
num2 byte 0
num3 byte 0
num4 byte 0

.code
main PROC
	mov edx,OFFSET Str2
	call WRITESTRING

	mov edx,OFFSET Str1
	mov ecx,SIZEOF Str1
	call READSTRING

	mov ebx,0
	jmp DECIDE
DECIDE:
	cmp Str1[ebx],0
	jne NUMSEG
	jmp ENDPRO

NUMSEG:
	cmp Str1[ebx],'0'
	jl OTHER
	cmp Str1[ebx],'9'
	jg UPSEG
	
	inc num1
	inc ebx
	jmp DECIDE

UPSEG:
	cmp Str1[ebx],'A'
	jl OTHER
	cmp Str1[ebx],'Z'
	jg LOWSEG

	inc num2
	inc ebx
	jmp DECIDE

LOWSEG:	
	cmp Str1[ebx],'a'
	jl OTHER
	cmp Str1[ebx],'z'
	jg OTHER

	inc num3
	inc ebx
	jmp DECIDE

OTHER:
	inc num4
	inc ebx
	jmp DECIDE

ENDPRO:
	mov eax,0
	mov edx,OFFSET Str3
	call WRITESTRING
	mov al,num1
	call WRITEDEC
	call  Crlf 

	mov edx,OFFSET Str4
	call WRITESTRING
	mov al,num2
	call WRITEDEC
	call  Crlf 

	mov edx,OFFSET Str5
	call WRITESTRING
	mov al,num3
	call WRITEDEC
	call  Crlf 

	mov edx,OFFSET Str6
	call WRITESTRING
	mov al,num4
	call WRITEDEC
	call  Crlf 


	INVOKE ExitProcess,0
main ENDP
END main
