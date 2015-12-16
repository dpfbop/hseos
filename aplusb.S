#include "simpleio.S"
        .text           // секция кода программы
        .global main    // экспортируем точку входа - функцию main
main:
		call readi32 // read A
		movl %eax,%ebx // A -> ebx
		call readi32 // read B
		mull %ebx // (%eax, %edx) = A * B
		movl %eax,%esi // %esi = A * B 

		call readi32 // 
		movl %eax,%ebx // %eax = C 
		call readi32 
		mull %ebx // (%eax, %edx) = C * D

		subl %eax,%esi
		movl %esi,%eax
		call writei32
		call nl
        call finish  // вызываем подпрограмму finish: exit(0)