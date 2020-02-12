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
    if (flags[17] == 1) {
        mx_file_reverse(file);
        return;
    }
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

void mx_main_rec(char *dir, int *flags, char *name) {
    t_file_data *fl = NULL;

    mx_printstr(dir);
    mx_printstr(":\n");
    fl = mx_get_files_rec(dir, flags, name, NULL);
    if (!fl)
        return;
    sort_fl(&fl, flags);
    mx_printend(&fl, flags);
    mx_print_main_nl_rec(fl, flags);
    mx_clean_file(&fl);
}
