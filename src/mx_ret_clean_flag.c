#include "../inc/uls.h"

char *mx_ret_clean_flag(char *flags, t_uls **uls, char *ret) {
    int index = 0;
    int size = 0;

    for (int i = 0; i < (*uls)->flags_num; i++) {
        if (flags[i] == '+')
            continue;
        size++;
    }
    ret = mx_strnew(size);
    for (int i = 0; i < (*uls)->flags_num; i++) {
        if (flags[i] == '+')
            continue;
        ret[index++] = flags[i];
    }
    (*uls)->flags_num = size;
    return ret;
}
