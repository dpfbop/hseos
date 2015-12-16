.section .text
.global sum

sum:
    pushl   %ebp
    movl    %esp, %ebp 

    xorl %ebx, %ebx
    addl 8(%ebp), %ebx
    addl 12(%ebp), %ebx
    jc overflow

output:
    movl 16(%ebp), %esi
    movl %ebx, (%esi)
    
    movl    %ebp, %esp      
    popl    %ebp            
    ret
	
overflow:
    xorl %ebx, %ebx
    decl %ebx
    jmp output
