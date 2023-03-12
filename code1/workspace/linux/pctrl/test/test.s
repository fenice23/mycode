	.file	"test.c"
	.text
	.section	.rodata
.LC0:
	.string	"^^^^^^^"
	.text
	.globl	function
	.type	function, @function
function:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	call	__errno_location@PLT
	movl	(%rax), %eax
	movl	%eax, %edi
	call	exit@PLT
	.cfi_endproc
.LFE5:
	.size	function, .-function
	.section	.rodata
.LC1:
	.string	"%s"
.LC2:
	.string	"-------"
.LC3:
	.string	"*******"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$0, -19(%rbp)
	movw	$0, -11(%rbp)
	movb	$0, -9(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L3
.L4:
	movl	-24(%rbp), %eax
	cltq
	movb	$45, -19(%rbp,%rax)
	leaq	-19(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush@PLT
	movl	$1000000, %edi
	call	usleep@PLT
	addl	$1, -24(%rbp)
.L3:
	cmpl	$9, -24(%rbp)
	jle	.L4
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	call	function
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L6
	call	__stack_chk_fail@PLT
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
