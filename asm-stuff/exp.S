# arg 0 in %rdi, arg 1 in %rsi, result in %rax
	
	.globl asmfn
	# We will treat the arguments as int32_t
	# int64_t asmfn(int64_t b, int64_t x)
asmfn: 
	
	# uint64_t result = 1
	movq    $1, %rax
	
.L0:
	# while (x != 0) {
        testl   %esi, %esi
        jz      .L1
	
	#     result *= b
	# (imul is special: %rax is arg, %rdx:%rax result)
	imulq   %rdi, %rax
	
	#     x--
        decl    %esi
	
	# }
	jmp     .L0
	
.L1:
	# return result
        ret
