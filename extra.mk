finitcpp.c: finit.c
	$(CC) -E finit.c | uniq -u | egrep -v '^#' >finitcpp.c

.c.s:
	$(CC) $(CFLAGS) -S $*.c
