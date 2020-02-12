#include "../inc/uls.h"

char *mx_lld_num_to_str(long long num, int size) {
    char *c = mx_strnew(size);

    if (num == 0)
        c[0] = '0';
    for (int i = size - 1; num != 0; i--) {
        c[i] = (num % 10) + '0';
        num /= 10;
    }
    return c;
}
