	.section .text
	.global printstack 
format_string: .string "0x%08x\n"

printstack:
    pushl   %ebp
    movl    %esp, %ebp 
    movl %ebp, %ebx

jumper:
    pushl 4(%ebx)
    pushl $format_string
    call printf
    addl $8, %esp
    movl (%ebx), %ebx
    testl %ebx, %ebx
    jz finish
    jmp jumper

finish:    
    movl    %ebp, %esp      
    popl    %ebp            
    ret
