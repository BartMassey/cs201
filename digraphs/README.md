# Homework 3: Digraphs
CS 201 Winter 2019

In this exercise, you will:

* Learn / review working with C in multiple files.

* Learn to work with the Linux filesystem.

## Problem

You are going to make a program that prints digraph
statistics taken from one of two places: text, or names from
a filesystem (directory tree).

A *digraph* is a pair of letters that appear next to each
other in a string. For example, the last two digraphs of the
first sentence of this paragraph are "in" and "ng". The
*frequency* of a digraph is just the number of times it
appears in the string. For example, the frequency of "tt" in
the first sentence of this paragraph is 1; the frequency of
"ea" is 2.

Different sources of text (English vs German, Tweets vs
Novels) usually have pretty different digraph frequencies:
it's a good way to tell them apart without understanding
them.

Your program will count the frequency of each digraph in its
source text that consists of a pair of ASCII letters. Upper
and lowercase are distinct. Thus, there will be 52×52 = 2704
counts to maintain. You will maintain 64-bit counts, so your
counters will take up 2704×8 = 21632 bytes of memory: not so
much on a modern machine.

* Your program will be run as

  > `./digraphs -t` *filename*

  where *filename* is the name of a text file containing the
  text to be counted

  > `./digraphs -p` *path*

  where *path* is a directory at which to start searching
  for filenames to count.

* For the `-p` option, you should recursively walk down into
  the subdirectories counting digraphs in all file and
  directory names encountered. Treat each name as a separate
  word: do not count digraphs across name boundaries. Do not
  follow symbolic links: count the digraphs in the link name
  and then stop the search. Similarly, do not traverse into
  directories whose names begin with `.`. (The directories
  `.` and `..` are particularly problematic.)

* If an error is encountered, your program must print "Error
  encountered: exiting." to `stderr` and then exit with
  status -1. You may do other error reporting if you choose.

* On a successful run, you should output the 10 most common
  digraphs in order of decreasing frequency. You make break
  ties in frequency however is convenient.

## Example Output

Your output for the first sentence of the paragraph
referenced above should look something like this:

        alphabetic characters: 58
        top digraphs:
          ap 2
          er 2
          th 2
          ea 2
          in 2
          di 1
          ig 1
          gr 1
          ra 1
          ph 1

## Required Program Structure

* Your program should consist of at least three files:
  `digraphs.c`, `fs.c`, `text.c`. Your code must have a
  working `Makefile`: please use the provided one as a base.

* You must include the provided `digraphs.h` in each
  source file and use its declarations.
  
* You may add to `digraphs.h` and the `Makefile` as needed.

## Hints

* You need to `malloc()` the `struct digraphs`: don't forget
  to initialize this memory.

* Writing the directory walker recursively will be *much*
  easier. Use `chdir("name")` to enter the directory
  `"name"`, use `chdir("..")` to leave.

* Use `opendir()` / `readdir()` / `closedir()` for reading
  directories: see the manual.  You will need to `#define
  _DEFAULT_SOURCE` before `#include <dirent.h>`.  The
  expression `e.d_type & DT_DIR` will be nonzero if and only
  if the directory entry `e` is itself a directory.

* It may be helpful to build an array of the following struct
  for sorting the digraphs:

        struct result {
            char digraph[2];
            uint64_t count;
        };

  Use the `qsort()` library routine to sort your digraphs:
  read the manual page carefully for usage, and ask if you
  have questions. The comparison function will require the
  use of `const` to avoid warnings.

* You could use a library such as `getopt` to look at the
  command line arguments, but again it shouldn't really be
  necessary. Do it if you like.

* You can get a sample run using the `script` command. It
  will start up a new shell: do your stuff and hit
  `control-D` to stop it. Then your typed content will be in
  the file `typescript`. Say `man script` for details.  You
  may want to hand-edit `typescript` a bit when you are
  done: it kind of has some noise in it.

* Write some test files and build some test directories to
  make sure your program works.  We will be testing your
  code, so you should too.

## Coding Style

Please name your main program `digraphs.c`.  Your program
must be formatted according to the course coding
guidelines. It must be valid C11 and compile without
warnings or errors.

The code should be as clear and readable as you can make it:
the graders and TAs are going to read a *lot* of programs,
and if yours is hard to understand they will just subtract
points and move on.

Your program must start with a comment that has your name and
the function of the program. For example

    /*
     * Bart Massey
     * Digraph Frequencies
     */

Each non-trivial function must have a short comment at
the top indicating its behavior.

Your program must use the provided materials as described above.

## Writeup

Your submission *must* include a writeup in a text file
named `README.txt` or `README.md`. (Remove or replace this
description you are reading.)  The writeup should contain
your name, a sample run of your program and a description of
anything interesting about your program or its development.

## Source Control

For this assignment, you are not required to use source
control. However, I strongly suggest putting all your
project files under Git control: it will avoid
backup-file messes and give you a good history of work.

## Submission

You should submit your materials (program, Makefile,
writeup) to the course website as a ZIP archive called
`digraphs.zip`. The ZIP archive should unzip into a directory
named `digraphs`. Use the assignment submission interface on
the course website to upload your archive.
