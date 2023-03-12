	.file	"zone.c"
	.text
	.globl	g_val
	.data
	.align 4
	.type	g_val, @object
	.size	g_val, 4
g_val:
	.long	100
	.section	.rodata
.LC0:
	.string	"fork fail"
.LC1:
	.string	"this is child----g_val:%d-%p\n"
.LC2:
	.string	"this is parent---g_val:%d-%p\n"
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
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
.L2:
	cmpl	$0, -4(%rbp)
	jne	.L3
	movl	$200, g_val(%rip)
	movl	g_val(%rip), %eax
	leaq	g_val(%rip), %rdx
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L4
.L3:
	movl	$1, %edi
	call	sleep@PLT
	movl	g_val(%rip), %eax
	leaq	g_val(%rip), %rdx
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L4:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
