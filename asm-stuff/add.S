# Template Function
# arg 0 in %rdi, arg 1 in %rsi, result in %rax
	
	.globl  asmfn
asmfn: 
	movq    %rsi, %rax
        addq    %rdi, %rax
        ret
