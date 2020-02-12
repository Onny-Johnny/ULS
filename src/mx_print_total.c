#include "../inc/uls.h"

void mx_print_total(t_file_data *file) {
    char *buf = NULL;
    int size = 0;
    blkcnt_t total = 0;

    while (file) {
        total += file->f_stat.st_blocks;
        file = file->next;
    }
    size = mx_ret_num_len_lld(total, 0);
    buf = mx_lld_num_to_str(total, size);
    mx_printstr("total ");
    mx_printstr(buf);
    mx_printchar('\n');
    mx_strdel(&buf);
}
