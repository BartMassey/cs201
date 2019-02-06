# Makefile for asm demos.

CC = gcc
CDEBUG = -g
CFLAGS = $(CDEBUG) -Wall -Werror -fno-pic -no-pie -static

BINS = add add_c xor xor_c

.S.o:
	$(CC) $(CFLAGS) -c $*.S

.c.s:
	$(CC) $(CFLAGS) -S $*.c

.SUFFIXES: .S

all: $(BINS)

add: driver.o add.o
	$(CC) $(CFLAGS) -o add driver.o add.o

add_c: driver.o add_c.o
	$(CC) $(CFLAGS) -o add_c driver.o add_c.o

xor: driver.o xor.o
	$(CC) $(CFLAGS) -o xor driver.o xor.o

xor_c: driver.o xor_c.o
	$(CC) $(CFLAGS) -o xor_c driver.o xor_c.o

clean:
	-rm -f *.o *.s $(BINS)
