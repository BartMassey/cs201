# Copyright © 2019 Bart Massey
# Makefile for digraph frequencies

CC = gcc
CFLAGS = -std=c11 -Wall -Werror -g
OBJS = digraphs.o readtext.o readfs.o

digraphs: digraphs.o
	$(CC) $(CFLAGS) -o digraphs $(OBJS)

$(OBJS): digraphs.h

clean:
	-rm -f digraphs
