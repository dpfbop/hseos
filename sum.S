#include "simpleio.S"
        .text          
        .global main   
main:
	movl $0,%ebx
read:
	call readi32 
	jnc correct
	jc ex
correct:
	addl %eax,%ebx
	jmp read
ex:
	movl %ebx,%eax
	call writei32
	call nl
	call finish
		
