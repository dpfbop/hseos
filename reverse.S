#include "simpleio.S"
        .text          
        .global main  
        .space  64 * 4, 0 
main:
    call readi32
    movl %eax, %ebx
    movl %ebx, %esi
readl:
    testl %ebx, %ebx
    jz writel
    call readi32 
    pushl %eax
    subl $1, %ebx
    jmp readl
writel:
    testl %esi, %esi
    jz ex
    subl $1, %esi
    popl %eax
    call writei32
    call nl
    jmp writel
ex:
    call finish
