
INCLUDE Irvine32.inc
ExitProcess PROTO,dwExitCode:DWORD

.data
Dec1 byte 100 dup(0)
Dec2 byte 100 dup(0)
Dec3 byte 100 dup(0)
SUM byte 0
CARRY byte 0
Long1 byte 0
Long2 byte 0
Str1 byte "Please input a decimal number(end with enter or space): ",0


.code
main PROC
	mov edx,OFFSET Str1
	call WRITESTRING

	mov edx,OFFSET Dec1
	mov ecx,SIZEOF Dec1
	call READSTRING
	mov ebx,0
	jmp cnt1
cnt1:
	cmp Dec1[ebx],0
	je INPUT2
	inc Long1
	inc ebx
	jmp cnt1

INPUT2:
	mov edx,OFFSET Str1
	call WRITESTRING
	mov edx,OFFSET Dec2
	mov ecx,SIZEOF Dec2
	call READSTRING
	mov ebx,0
	jmp cnt2
cnt2:
	cmp Dec2[ebx],0
	je OUTCNT
	inc Long2
	inc ebx
	jmp cnt2
OUTCNT:
	mov bl,Long1
	add ebx,OFFSET Dec1
	dec ebx
	mov cl,Long2
	add ecx,OFFSET Dec2
	dec ecx
	mov edx,98
	add edx,OFFSET Dec3
	jmp PRE1
PRE1:
	cmp bl,0
	jl PRE2
	mov al,[ebx]
	sub al,48
	mov [ebx],al
	cmp cl,0
	mov al,[ebx]
	jl ADD2
	mov al,[ecx]
	sub al,48
	mov [ecx],al
	jmp ADD1
PRE2:
	mov al,[ecx]
	add al,CARRY
	cmp al,48
	jl ENDPRO
	mov al,[ecx]
	sub al,48
	mov [ecx],al

	mov al,[ecx]
	jmp ADD2

ADD1:
	mov al,CARRY
	mov CARRY,0
	add al,[ebx]
	add al,[ecx]
	mov SUM,al
	cmp SUM,9
	jg CAR
	jmp L
CAR: 
	sub SUM,10
	mov CARRY,1
L:
	mov al,SUM
	add al,48
	mov [edx],al

	dec ebx
	dec ecx
	dec edx
	jmp PRE1
ADD2:
	add al,CARRY
	mov SUM,al
	mov CARRY,0

	cmp SUM,9
	jg CAR2
	jmp L2
CAR2: 
	sub SUM,10
	mov CARRY,1
L2:
	mov al,SUM
	add al,48
	mov [edx],al

	dec ebx
	dec ecx
	dec edx
	jmp PRE1

ENDPRO:
	call crlf
	cmp CARRY,0
	je OUTPUT
	mov al,1
	call WRITEDEC
OUTPUT:
	inc edx
	call WRITESTRING
	call crlf

	INVOKE ExitProcess,0
main ENDP
END main
