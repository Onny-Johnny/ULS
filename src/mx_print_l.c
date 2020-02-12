#include "../inc/uls.h"

static void print_l_end(t_flag_l *fl_l, t_file_data *file, int *flags) {
    mx_printstr(fl_l->access);
    mx_printstr(fl_l->hard_links);
    if (flags[18] == 0) {
        mx_printstr(fl_l->user_name);
        if (flags[19] == 0)
            mx_printstr("  ");
    }
    if (flags[19] == 0)
        mx_printstr(fl_l->group_name);
    mx_printstr(fl_l->size);
    mx_printstr(fl_l->time);
    if (flags[9] && isatty(1) == 1)
        mx_print_col(file->d_name, fl_l->access);
    else
        mx_printstr(file->d_name);
    if (fl_l->access[0] == 'l')
        mx_print_link(file);
    mx_printchar('\n');
}

static t_flagl_limits *get_lim(t_file_data **file, int *flags) {
    if (flags[20] == 1)
        return mx_get_limits1(file, flags);
    else
        return mx_get_limits(file, flags);
}

void mx_print_l(t_file_data **file, int *flags) {
    t_file_data *cur = *file;
    t_flagl_limits *lim = get_lim(file, flags);
    t_flag_l *fl_l = NULL;
    mx_print_total(cur);

    while (cur) {
        fl_l = mx_get_flag_l(lim, cur, flags);
        print_l_end(fl_l, cur, flags);
        if (flags[6] == 1 && fl_l->access[10] == '@')
            mx_print_ex_atr(cur->d_name1, lim->size_len);
        mx_flag_l_clean(&fl_l);
        cur = cur->next;
    }
    free(lim);
}
