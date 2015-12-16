#include "simpleio.S"
        .text          
        .global main   
main:
    movl $0, %esi
    movl $0, %edi
readl:
    call readi32 
    jnc correct
    jc ex
correct:
    testl $1, %eax
    jz pos
    jnz neg
    jmp read
pos:
    addl %eax, %esi
    jmp readl
neg:
    addl %eax,%edi
    jmp readl
ex:
    movl %esi,%eax
    call writei32
    call nl
    movl %edi, %eax
    call writei32
    call nl
    call finish
