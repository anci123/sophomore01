INCLUDE Irvine32.inc

.data

TIMESTR byte 20 dup(0)

.code

main PROC
	mov dx, 2AE7H
	mov esi, offset TIMESTR
	mov ax,dx
	shr ax,11
	add ax, '0'
	mov [esi],ax
	inc esi
	mov ax,':'
	mov [esi],ax

	mov bx,dx
	shr bx,5
	and bx,3Fh
	mov ax,bx
	aam
	inc esi
	add ah,'0'
	mov [esi],ah
	inc esi
	add al,'0'
	mov [esi],al

	inc esi
	mov ax,':'
	mov [esi],ax

	and dx ,1Fh
	mov ax,dx
	mov bx,2
	mul bx
	aam 
	add ah,'0'
	inc esi
	mov [esi],ah
	add al,'0'
	inc esi
	mov [esi],al


	mov edx, offset TIMESTR
	call WriteString
	ret
main ENDP
END main