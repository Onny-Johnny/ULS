#include "../inc/uls.h"

static char *ret_if_no_six_month(time_t ti) {
    char *str = ctime(&ti);
    char *ret = mx_strnew(14);

    for (int i = 3, j = 0; i < 16; i++, j++)
        ret[j] = str[i];
    ret[13] = ' ';
    return ret;
}

static char *ret_if_six_month(time_t ti) {
    char *str = ctime(&ti);
    char *ret = mx_strnew(14);
    int j = 0;

    for (int i = 3; i < 10; i++)
        ret[j++] = str[i];
    ret[j++] = ' ';
    for (int i = 19; i < 24; i++)
        ret[j++] = str[i];
    ret[13] = ' ';
    return ret;
}

char *mx_get_time(time_t ti) {
    char *ret = NULL;
    time_t ltime;
    time_t bool_time;
    time(&ltime);

    bool_time = ltime - ti;
    if (bool_time > 15768000)
        ret = ret_if_six_month(ti);
    else
        ret = ret_if_no_six_month(ti);
    return ret;
}
