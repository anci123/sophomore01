INCLUDE Irvine32.inc

.data

arr1 sdword 10000 dup(0)
arr2 sdword 10000 dup(0)
arr3 sdword 10000 dup(0)
Str1 byte "Please input the number of row:",0
Str2 byte "Please input the number of column:",0
Str3 byte "Please input an array:",0
Str4 byte "Array 1: ",0
Str5 byte "Array 2: ",0
Str6 byte "Sum offset arrays",0
row byte 0
col byte 0
total byte 0
cnt byte 0
.code
main PROC
	mov edx,OFFSET Str1
	call WRITESTRING
	call READINT
	mov row,al
	mov edx,OFFSET Str2
	call WRITESTRING
	call READINT
	mov col,al
	mov edx,OFFSET Str3
	call WRITESTRING
	call crlf
	mov al,col
	mov bl,row
	mul bl
	mov ecx,0
	mov total,al
	mov cl,total
	mov esi,offset arr1
	mov bl,1
	jmp L1
home:
	cmp bl,0
	je P
	dec bl
	mov edx,OFFSET Str3
	call WRITESTRING
	call crlf
	mov esi,offset arr2
	mov cl,total
	jmp L1


L1:
	mov eax,0
	call READINT
	mov [esi],eax
	mov eax,[esi]
	add esi,4
	dec cl
	cmp cl,0
	je home
	jmp L1
P:	
	mov cnt,1
	mov esi, offset arr1
	mov bl,row
	mov edx,OFFSET Str4
	call WRITESTRING
	jmp R1
home2:
call crlf
	cmp cnt,0
	je A
	dec cnt
	mov esi,offset arr2
	mov bl,row
	mov edx,OFFSET Str5
	call WRITESTRING
	jmp R1
R1:
	call crlf
	dec bl
	mov cl,col
	cmp bl,0
	jae C1

C1: 
	mov eax,[esi]
	call WRITEINT
	add esi,4
	mov al,' '
	call WRITECHAR
	loop C1
	cmp bl,0
	ja R1
	jmp home2

A:	
	mov esi, offset arr3
	mov edi, offset arr1
	mov bl,row
	call crlf
	mov edx,OFFSET Str6
	call WRITESTRING
	jmp R2
R2:
	call crlf
	dec bl
	mov cl,col
	cmp bl,0
	jae C2

C2: 
	mov eax,0
	mov eax,[edi]
	add eax,[edi+40000]
	mov [esi],eax
	mov eax,[esi]
	call WRITEINT
	add esi,4
	add edi,4
	mov al,' '
	call WRITECHAR
	loop C2
	cmp bl,0
	ja R2

	INVOKE ExitProcess,0

main ENDP
END main