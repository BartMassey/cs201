# arg 0 in %rdi, arg 1 in %rsi, result in %rax
	
	.globl asmfn
	# uint64_t asmfn(uint32_t b, uint32_t x)
asmfn: 
	# (save %rdx)
	pushq   %rdx
	
	# uint64_t result = 1
	xorq    %rax, %rax
	movb    $1, %al
	
.L0:
	# while (x != 0) {
        cmpl    $0, %esi
        jz      .L1
	
	#     result *= b
	# (mul is special: %rax is implicit arg, %rdx:%rax result)
	mulq    %rdi
	
	#     x--
        decl    %esi
	
	# }
	jmp     .L0
	
.L1:
	# (restore %rdx)
        popq    %rdx
	# return result
        ret
