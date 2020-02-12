#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *ss1 = s1;
    const unsigned char *ss2 = s2;

    if (n == 0) {
        return 0;
    }
    while (*ss1 == *ss2 && *ss1 && *ss2 && --n > 0) {
        ss1++;
        ss2++;
    }
    return *ss1 - *ss2;
}
