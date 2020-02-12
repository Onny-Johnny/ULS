#include "../inc/uls.h"

int *mx_get_sorted_flags(int argc, char **argv, t_uls **uls) {
    char *flags = mx_parse_flags(argc, argv, uls);
    int *flags_ret = NULL;

    if (flags != NULL) {
        flags = mx_del_flag_dubl(&flags, uls);
        flags = mx_filter_flags(&flags, uls);
        flags_ret = mx_flags_to_int(&flags);
        if (flags_ret[18] == 1 || flags_ret[19] == 1 || flags_ret[20] == 1)
            flags_ret[3] = 1;
        if (flags_ret[17] == 1)
            flags_ret[0] = 1;
        if (flags_ret[0] == 1)
            flags_ret[14] = 0;
    }
    return flags_ret;
}
