INCLUDE Irvine32.inc
ExitProcess PROTO,dwExitCode:DWORD

.data
b DWORD 1,2,3,4,10,20,30,40,50,60,70,80 
num DWORD 10

.code
main PROC
	mov esi,OFFSET b
	mov ecx,num
L1:
	mov ebx,[esi]
	inc ebx
	mov [esi],ebx
	mov eax,[esi]
	CALL WRITEDEC
	call crlf
	add esi,4
	loop L1


	INVOKE ExitProcess,0
main ENDP
END main
