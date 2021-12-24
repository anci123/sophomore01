INCLUDE Irvine32.inc
ExitProcess PROTO,dwExitCode:DWORD

.data
hexdgt byte 1,2,3,4,0AH,0BH,6,7,8,9
hexno byte 5
textout byte 11 dup (0)
.code
main PROC
	mov ebx,0
	jmp L1
L1:
	DEC hexno
	cmp ebx,5h
	jl DECIDE
	jmp ENDPRO

DECIDE:
	cmp hexdgt[ebx],9
	jg ALPHA
	jmp DIGIT
DIGIT:
	mov textout[ebx],30H
	mov cl,hexdgt[ebx]
	add textout[ebx],cl
	INC ebx
	jmp L1
ALPHA:
	mov textout[ebx],'A'
	mov cl,hexdgt[ebx]
	add textout[ebx],cl
	sub textout[ebx],10
	INC ebx
	jmp L1
ENDPRO:
	mov textout[ebx],0
	mov edx,OFFSET textout
	CALL WRITESTRING

	INVOKE ExitProcess,0
main ENDP
END main
