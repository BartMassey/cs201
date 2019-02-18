#define _DEFAULT_SOURCE
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>

int main() {
    DIR *d = opendir(".");
    assert(d);
    while (1) {
        errno = 0;
        struct dirent *e = readdir(d);
        if (!e)
            break;
        printf("%s", e->d_name);
        if (e->d_type == DT_DIR)
            printf(" [dir]");
        printf("\n");
    }
    assert(errno == 0);
    closedir(d);
    return 0;
}
