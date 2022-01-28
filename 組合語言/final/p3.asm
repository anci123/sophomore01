INCLUDE Irvine32.inc

.data

X dword 123456h
STR1 byte 11 dup(?)
MA byte "0123456789ABCDEF"
.code

main PROC
	mov ecx, 4
	mov bl,7
	mov edi, offset STR1
	mov esi, offset X
	loop L1
L1:
	mov ax,bx
	mov cx,4
	mul cx
	mov cl,al
	mov eax,X
	shr eax,cl
	and eax,0Fh
	mov dl,[MA+eax]
	mov [edi],dl
	inc edi
	mov edx, offset STR1
	dec bl
	cmp bl,0
	jl E
	loop L1

E:
	mov byte ptr [edi], 'H'
	mov byte ptr [edi + 1], 0
	mov edx, offset STR1
	call WriteString
	ret
main ENDP
END main