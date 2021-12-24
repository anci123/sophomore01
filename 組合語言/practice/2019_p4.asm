INCLUDE Irvine32.inc
ExitProcess PROTO,dwExitCode:DWORD

.data
b SDWORD 1,2,3,4,10,20,30,40,50,60,70,80 
num SDWORD 10

.code

main PROC
	mov esi,OFFSET b
	mov ecx,num
	call prp
	INVOKE ExitProcess,0
main ENDP
prp PROC
L1:
	mov ebx,[esi]
	inc ebx
	mov [esi],ebx
	mov eax,[esi]
	CALL WRITEDEC
	call crlf
	add esi,4
	loop L1
prp ENDP
END main


