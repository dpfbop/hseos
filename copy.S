#include <asm/unistd_32.h>
        .data
c:      .byte   0
        .text
        .global main

main:
        jmp read_char
read_char:  
        movl    $__NR_read, %eax
       	movl    $0, %ebx
        movl    $c, %ecx
        movl    $1, %edx
        int     $0x80
        testl %eax, %eax
        jz finish
        jmp write_char
write_char:
        movl $__NR_write,%eax
        movl $1, %ebx
        movl $c,%ecx
        movl $1, %edx
        int $0x80
        jmp read_char
finish:
        movl    $__NR_exit, %eax
        xorl    %ebx, %ebx
        int     $0x80
