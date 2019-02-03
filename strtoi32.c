#include <errno.h>

#include "strtoi32.h"

/*
 * Convert the string in s to a 32-bit signed integer,
 * storing the result in *vp. s may represent a string in
 * base 8 (digits start with 0), base 16 (digits start with
 * 0x) or base 10 (otherwise).
 *
 * Returns 0 on success and -1 on error.
 *
 * On error *vp will be unmodified and
 * errno will be set to indicate the error:
 * * EINVAL if s contains invalid characters
 * * ERANGE if *vp would be out of range
 */
int strtoi32(char *s, int32_t *vp) {
    if (*s == '\0') {
        errno = EINVAL;
        return -1;
    }
    char *endptr = s;
    errno = 0;
    int64_t v_found = strtoll(s, &endptr, 0);
    if (errno != 0)
        return -1;
    if (*endptr != '\0') {
        errno = EINVAL;
        return -1;
    }
    if (v_found < INT32_MIN || v_found > INT32_MAX) {
        errno = ERANGE;
        return -1;
    }
    *vp = v_found;
    return 0;
}
