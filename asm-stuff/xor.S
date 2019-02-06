# arg 0 in %rdi, arg 1 in %rsi, result in %rax
	
	.globl  asmfn
asmfn: 
	movq    %rsi, %rax
        xorq    %rdi, %rax
        ret
