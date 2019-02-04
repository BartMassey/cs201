#ifndef _DIGRAPH_H
#define _DIGRAPH_H

#include <stdint.h>

/* Digraph count information. */
struct digraphs {
    /* Number of alphabetic characters examined. */
    uint64_t nchars;
    /*
     * Digraph frequencies. The left (row) index
     * is the first character in the digraph; the right (column)
     * index is the second character. Indices 0..25 are the lowercase
     * characters in order; 26..51 are the uppercase characters.
     */
    uint64_t counts[52][52];
};

/* text.c */

/*
 * Return a malloc-ed struct of counts
 * for the text in the file with the given name.
 * Return a null pointer on error.
 */
extern struct digraphs *
digraphs_text(char *filename);

/* fs.c */

/*
 * Return a malloc-ed struct of counts for the file and
 * directory names starting at the given path. Return a null
 * pointer on error.
 */
extern struct digraphs *
digraphs_fs(char *path);

#endif
