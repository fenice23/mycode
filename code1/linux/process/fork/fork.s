	.file	"fork.c"
	.text
	.section	.rodata
.LC0:
	.string	"hello!"
	.align 8
.LC1:
	.string	"===================================="
.LC2:
	.string	"fork child process fail!"
.LC3:
	.string	"%d\n"
.LC4:
	.string	"is parent process, id: %d\n"
.LC5:
	.string	"is child process,  id: %d\n"
.LC6:
	.string	"Err!"
.LC7:
	.string	"this is process!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	call	fork@PLT
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L2
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	jmp	.L3
.L2:
	cmpl	$0, -4(%rbp)
	jle	.L4
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L3
.L4:
	cmpl	$0, -4(%rbp)
	jne	.L5
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L5:
	leaq	.LC6(%rip), %rdi
	call	puts@PLT
.L3:
	leaq	.LC7(%rip), %rdi
	call	puts@PLT
	movl	$100, %edi
	call	sleep@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
