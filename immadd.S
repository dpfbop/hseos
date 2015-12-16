	.section .text
	.global immadd 
format_string: .string "%d\n"

immadd:
    pushl   %ebp
    movl    %esp, %ebp 
    movl %ebp, %ebx
    movl 4(%ebx), %esi 
    movl (%esi), %eax
    addl 4(%esi), %eax
    pushl %eax
    pushl $format_string
    call printf
    addl $8, %esp    
    addl $8, 4(%ebx)
    movl    %ebp, %esp      
    popl    %ebp    
    ret