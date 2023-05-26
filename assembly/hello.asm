; nasm -felf64 hello.asm
; ld -o hello hello.o

        global _start

        section .text
_start: mov    rax, 1
        mov    rdi, 1
        mov    rsi, str
        mov    rdx, 13
        syscall
        mov    rax, 60
        syscall

        section .data
        str: db  "hello, world", 10
