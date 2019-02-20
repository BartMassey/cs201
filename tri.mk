tri.s: tri.c
	gcc -Wall -Werror -fno-pic -no-pie -march=x86-64 -mno-sse \
	  -static -O4 -fno-unroll-loops -S tri.c

tri: tri.s
	gcc -Wall -Werror -fno-pic -no-pie -march=x86-64 -mno-sse \
	  -static -O4 -fno-unroll-loops -o tri tri.s
