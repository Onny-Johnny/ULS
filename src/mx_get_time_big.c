#include "../inc/uls.h"

char *mx_get_time_big(time_t ti) {
    char *ret = mx_strnew(22);
    char *str = ctime(&ti);

    for (int i = 3, j = 0; i < 24; i++, j++)
        ret[j] = str[i];
    ret[21] = ' ';
    return ret;
}
