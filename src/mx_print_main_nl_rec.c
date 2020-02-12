#include "../inc/uls.h"

void mx_print_main_nl_rec(t_file_data *fl, int *flags) {
    while (fl) {
        if (mx_strcmp(fl->d_name, ".") != 0
            && mx_strcmp(fl->d_name, "..") != 0
            && (fl->f_stat.st_mode & 0170000) == 0040000) {
            mx_printchar('\n');
            mx_main_rec(fl->d_name1, flags, fl->d_name);
        }
        fl = fl->next;
    }
}
