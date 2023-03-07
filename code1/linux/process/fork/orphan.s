	.file	"orphan.c"
	.text
	.section	.rodata
.LC0:
	.string	"fork fail"
	.align 8
.LC1:
	.string	"is child  process and PID is: %d\n"
	.align 8
.LC2:
	.string	"is parent process and PID is: %d\n"
.LC3:
	.string	"Err!"
	.align 8
.LC4:
	.string	"-------------------------------------------------------------------------------------------------%d\n"
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
	call	fork@PLT
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L2
	leaq	.LC0(%rip), %rdi
	call	perror@PLT
	jmp	.L3
.L2:
	cmpl	$0, -4(%rbp)
	jne	.L4
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L3
.L4:
	cmpl	$0, -4(%rbp)
	jle	.L5
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L5:
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
.L3:
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$10000, %edi
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
