nnss: nnss.o strtoi32/strtoi32.o
	$(CC) $(CFLAGS) -o nnss nnss.o strtoi32/strtoi32.o

nnss.o: strtoi32/strtoi32.h
