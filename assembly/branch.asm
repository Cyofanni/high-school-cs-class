SECTION .text
global  _start
 
_start:
	mov ecx, 0Ah
	cmp ecx, 0Ah
	jz _start

	mov eax, 3Ch
	syscall
