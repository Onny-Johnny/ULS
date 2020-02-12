#include "../inc/uls.h"

static void sort_rev(t_file_data **file, int *flags) {
    if (flags[4] == 1)
        mx_merge_sort_size_r(file);
    else if (flags[13] == 1 && flags[5] == 1)
        mx_merge_sort_status_r(file);
    else if (flags[7] == 1 && flags[5] == 1)
        mx_merge_sort_last_acc_r(file);
    else if (flags[5] == 1)
        mx_merge_sort_modification_r(file);
    else
        mx_merge_sort_r(file);
}

static void sort_fl(t_file_data **file, int *flags) {
    if (flags[17] == 1)
        return;
    if (flags[15] == 1) {
        sort_rev(file, flags);
        return;
    } else {
        if (flags[4] == 1)
            mx_merge_sort_size(file);
        else if (flags[13] == 1 && flags[5] == 1)
            mx_merge_sort_status(file);
        else if (flags[7] == 1 && flags[5] == 1)
            mx_merge_sort_last_acc(file);
        else if (flags[5] == 1)
            mx_merge_sort_modification(file);
        else
            mx_merge_sort(file);
    }
}

void mx_p_l(t_file_data **file, int *flags, int root_num) {
    if (!*file)
        return;
    sort_fl(file, flags);
    if (flags[2] == 1 || (isatty(1) == 0 && flags[16] == 1)
        || (isatty(1) == 0 && flags[1] == 0
        && flags[3] == 0 && flags[12] == 0)) {
        mx_print_one(*file, flags);
    } else if (flags[3] == 1) {
        mx_print_l_light(file, flags);
    } else if (flags[12] == 1) {
        mx_print_x(*file, flags);
    } else if (((flags[1] && flags[9])
               || (!flags[1] && flags[9])) && isatty(1) == 1) {
        mx_print_c_col(*file, flags);
    } else {
        mx_print_c(*file, flags);
    }
    if (root_num != 0)
        mx_printchar('\n');
    mx_clean_file(file);
}
