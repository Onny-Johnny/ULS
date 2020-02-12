#include "../inc/uls.h"

char *mx_filter_flags(char **flags, t_uls **uls) {
    char *ret = NULL;

    for (int i = (*uls)->flags_num - 1; i > 0; i--) {
        if (flags[0][i] == '+')
            continue;
        mx_del_dich_flags(flags, i, flags[0][i]);
    }
    ret = mx_ret_clean_flag(flags[0], uls, NULL);
    mx_strdel(flags);
    return ret;
}
