#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    char *ret = s1;

    s1 += mx_strlen(s1);
    while (*s2) {
        *s1++ = *s2++;
    }
    *s1 = '\0';
    return ret;
}
