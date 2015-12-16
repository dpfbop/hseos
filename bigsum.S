#include "simpleio.S"
        .text          
        .global main   
main:
	movl $0,%ebx
	movl $0,%esi
read:
	call readi64 
	jnc correct
	jc ex
correct:
	addl %eax,%ebx
	adcl %edx,%esi
	jmp read
ex:
	movl %ebx,%eax
	movl %esi,%edx
	call writei64
	call nl
	call finish
		
