#define _DEFAULT_SOURCE
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void walkdir(int recurse) {
    DIR *d = opendir(".");
    assert(d);
    while (1) {
        errno = 0;
        struct dirent *e = readdir(d);
        if (!e)
            break;
        if (e->d_name[0] == '.')
            continue;
        if (recurse) {
            for (int i = 0; i < 2 * (recurse - 1); i++)
                putchar(' ');
        }
        printf("%s", e->d_name);
        if (e->d_type == DT_DIR)
            printf(" [dir]");
        printf("\n");
        if (recurse && e->d_type == DT_DIR) {
            if (chdir(e->d_name) == -1) {
                perror(e->d_name);
                exit(1);
            }
            walkdir(recurse + 1);
            if (chdir("..") == -1) {
                perror("chdir ..");
                exit(1);
            }
        }
    }
    assert(errno == 0);
    closedir(d);
}

int main(int argc, char **argv) {
    int recurse = 0;
    if (argc == 2 && !strcmp(argv[1], "-r")) {
        recurse = 1;
    } else if (argc != 1) {
        fprintf(stderr, "usage: lls [-r]\n");
        return 1;
    }
    walkdir(recurse);
    return 0;
}
