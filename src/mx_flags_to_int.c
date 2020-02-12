#include "../inc/uls.h"

static int ret_flg_ind2(char c) {
    if (c == 'g')
        return 18;
    if (c == 'o')
        return 19;
    return 20;
}

static int ret_flg_ind1(char c) {
    if (c == 'G')
        return 9;
    if (c == 'R')
        return 10;
    if (c == 'T')
        return 11;
    if (c == 'x')
        return 12;
    if (c == 'c')
        return 13;
    if (c == 'A')
        return 14;
    if (c == 'r')
        return 15;
    if (c == '$')
        return 16;
    if (c == 'f')
        return 17;
    return ret_flg_ind2(c);
}

static int ret_flg_ind(char c) {
    if (c == 'a')
        return 0;
    if (c == 'C')
        return 1;
    if (c == '1')
        return 2;
    if (c == 'l')
        return 3;
    if (c == 'S')
        return 4;
    if (c == 't')
        return 5;
    if (c == '@')
        return 6;
    if (c == 'u')
        return 7;
    if (c == 'h')
        return 8;
    return ret_flg_ind1(c);
}

int *mx_flags_to_int(char **flags) {
    int *ret = (int*)malloc(22 * sizeof (int));
    int buf = 0;

    for (int i = 0; i < 22; i++)
        ret[i] = 0;
    for (int i = 0; flags[0][i] != '\0'; i++) {
        buf = ret_flg_ind(flags[0][i]);
        ret[buf] = 1;
    }
    mx_strdel(flags);
    return ret;
}
