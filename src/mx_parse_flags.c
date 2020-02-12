#include "../inc/uls.h"

static bool all_good_flags(int argc, char **argv, t_uls **uls) {
    for ((*uls)->r_s = 1; (*uls)->r_s < argc; (*uls)->r_s++) {
        if (mx_memcmp(argv[(*uls)->r_s], "--", 2) == 0) {
            if (mx_strlen(argv[(*uls)->r_s]) > 2) {
                mx_p_err_flag('-');
                return false;
            }
            return true;
        }
        if (mx_strcmp(argv[(*uls)->r_s], "-") == 0
            || argv[(*uls)->r_s][0] != '-') {
            return true;
        }
        if (mx_is_no_our_flags(argv[(*uls)->r_s]))
            return false;
    }
    return true;
}

static int get_flags_num(char **argv, t_uls *uls) {
    int count = 0;

    for (int i = 1; i < uls->r_s; i++) {
        for (int j = 1; argv[i][j] != '\0'; j++)
            count++;
    }
    return count;
}

char *mx_parse_flags(int argc, char **argv, t_uls **uls) {
    char *flags = NULL;

    if (all_good_flags(argc, argv, uls)) {
        (*uls)->flags_num = get_flags_num(argv, *uls);
        if ((*uls)->flags_num != 0) {
            flags = mx_strnew((*uls)->flags_num);
            for (int i = 1; i < (*uls)->r_s; i++)
                mx_strcat(flags, &(argv[i][1]));
        } else {
            (*uls)->flags_num = 1;
            flags = mx_strnew((*uls)->flags_num);
            flags[0] = '$';
        }
    }
    return flags;
}
