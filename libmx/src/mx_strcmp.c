#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    while (*s1 == *s2 && *s1 && *s2) {
        s1++;
        s2++;
        if (*s1 != *s2)
            break;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
