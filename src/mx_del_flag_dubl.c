#include "../inc/uls.h"

static void del_copy(char **flags, int num) {
    char c = flags[0][num];

    for (int i = 0; i < num; i++) {
        if (c == flags[0][i])
            flags[0][i] = '+';
    }
}

char *mx_del_flag_dubl(char **flags, t_uls **uls) {
    char *ret = NULL;

    for (int i = (*uls)->flags_num - 1; i > 0; i--) {
        if (flags[0][i] == '+')
            continue;
        del_copy(flags, i);
    }
    ret = mx_ret_clean_flag(flags[0], uls, NULL);
    mx_strdel(flags);
    return ret;
}
