.data
print_format:
	.string "%d\n"
print_p:
	.string "Owerflow %d\n"
array:
	.long 2, 4, 5, -3, 7, 9, 11
array_end:
	
.text
.global main
.type main, @function

main:
	movl $0, %ecx
	movl $array, %ebx
	jmp bound

loop:
	movl $4, %eax
	cmpl %eax, (%ebx)
	jne less
	je next_num

otr:	
	movl $0, %eax
	cmpl %eax, (%ebx)
	jle next_num
	add (%ebx), %ecx
	jo overfl
	jc overfl
	jge next_num

next_num:	
	addl $4, %ebx
	cmpl $array_end, %ebx
	je exit
	movl $9, %eax
	cmpl %eax, (%ebx)
	je exit
	jne otr
less:
	addl $4, %ebx
bound:
	cmpl $array_end, %ebx
	jne loop
exit: 
	pushl %ecx
	pushl $print_format
	call printf
	addl $8, %esp
	movl $0, %ecx
	movl $0, %ebx
	movl $0, %eax
	ret
overfl:
	push $print_p
	call printf
	addl $4, %esp
	movl $0, %ecx
	movl $0, %ebx
	movl $0, %eax
	ret
