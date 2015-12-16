#include <asm/unistd_32.h>
	.text
msg1:	.string	"Process: %d, %d, %d\n"
	.align	16
	.global	main
main:
	pushl $0
	call umask
	addl $4, %esp
	pushl %eax
	call getgid	
	pushl %eax
	call getuid
	pushl %eax
	pushl	$msg1
	call	printf
	addl	$16, %esp
	pushl $0
	call exit