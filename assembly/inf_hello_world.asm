	global _start
	section .text
_start:
	mov ecx, 0
	mov eax, 01h
	mov rsi, str
	mov rdx, 0Dh
	syscall
	inc ecx
	jmp _start

	section .data
str:	db "hello, world", 0Ah
	
