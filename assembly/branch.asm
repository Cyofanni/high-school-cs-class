SECTION .data
msg     db      'Hello, brave new world!', 0Ah ; we can modify this now without having to update anywhere else in the program
 
SECTION .text
global  _start
 
_start:
	mov ecx, 0Ah
	cmp ecx, 0Ah
	jz _start

	mov eax, 3Ch
	syscall
