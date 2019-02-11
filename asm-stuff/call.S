# arg 0 in %rdi, arg 1 in %rsi, result in %rax
	
	.section .rodata
.fmt:
	.string "%d = %d + %d\n"

	.text
	.globl asmfn
asmfn: 
	# set up "base pointer"
	pushq   %rbp
        movq    %rsp, %rbp
	# save "callee-saves" registers to be used
        pushq   %rcx
        pushq   %rdx
        pushq   %r8
	# printf end of argument list
        xorq    %r8, %r8
	# printf arg 3
	movq    %rsi, %rcx
	# printf arg 2
	movq    %rdi, %rdx
	# printf arg 1
	addq    %rdi, %rsi
        # save sum for later
        pushq   %rsi
	# printf arg 0
	movq    $.fmt, %rdi
	# printf call (ignore error)
        call    printf
	# return saved sum
	popq    %rax
	# restore regs
        popq   %r8
        popq   %rdx
        popq   %rcx
	popq   %rbp
        ret
