# Homework 1: Bit Manipulation
CS 201 Winter 2019

In this exercise, you will:

1. Learn / review writing and compiling simple C programs
   in the Linux enviroment.

2. Work with C integers and bitsets.

3. Prepare homework assignments for submission.

You are to build a simple command-line program.  I have made
you a template program [`bittool.c`](bittool.c) and
[`Makefile`](Makefile). You may modify or ignore these if
you like.

## The Program

The program to be built is called "bittool". Bittool
requires two or more non-negative integer arguments on the
command line.  (The program must fail — print an error
message and exit with status -1 — otherwise.)

* When given exactly two arguments, the arguments must be
  unsigned integers of no more than 32 bits. (The program
  must fail otherwise.)  The output will be a description of
  the bits that the two numbers have in common, in four
  formats:

    * As a comma-separated decimal list of set bit positions
      in increasing order.
    
    * As an unsigned hex number representing the bitset.

    * As a signed decimal number representing the bitset.

    * As an unsigned decimal number representing the bitset.

  For example (the `$` in the examples is a shell prompt,
  where you have typed something):

        $ ./bittool 0x0f 0x05
        bits: 0,2
        hex: 0x5
        signed: 5
        unsigned: 5

* When given more than two arguments, all arguments must be
  numbers in the range 0…15. (The program must fail
  otherwise.) The arguments are treated as bit
  positions. The output will be the 16-bit binary number
  representing the bitset union of all the inputs.

  For example:

        $ ./bittool 2 4 3 4
        0000000000011100

## The Writeup

You must include a file called `README.txt` in your
submission. This file must be plain ASCII or Unicode text,
like program text. `README.txt` should start with your name
and the homework assignment number, followed by a blank
line. It should then describe the program, describe how you
tested the program, and say what still doesn't work. Other
comments are also welcome.

For example:

        Bart Massey
        Homework 1

        This program computes bitsets depending on its
        arguments. Please see the homework description
        for details.

        I tested this program with several test cases I
        built by hand. The input and expected output are in
        the file tests.txt.

        This program seems to work for me. It was hard to
        write because C and UNIX and bitsets are hard.

## Submission

To submit the assignment, please make a `zip` file called
`bittool.zip`. This file must contain your `README.txt`,
`bittool.c` and `Makefile` in a subdirectory called
`bittool`. It may contain other things in that directory if
you want us to see them. Please do not include the
executable file or your git repository.

If you are in your `bittool` directory, you might:

        $ cd ..
        $ ls -d bittool
        bittool
        $ zip -r bittool.zip bittool/Makefile \
          bittool/README.txt bittool/bittool.c

(See the manual page for `zip` if you want help with that
program.) Then upload `bittool.zip` to `http://d2l.pdx.edu`.
