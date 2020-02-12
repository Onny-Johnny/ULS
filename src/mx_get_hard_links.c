#include "../inc/uls.h"

char *mx_get_hard_links(t_file_data *file, t_flagl_limits *lim) {
    char *hard = NULL;
    char *buf = NULL;
    int whitend = lim->hard_l_len - file->hard_l_len;
    int size = 0;

    if (whitend > 0) {
        size = whitend + file->hard_l_len;
        hard = mx_strnew(size + 1);
    } else {
        size = file->hard_l_len;
        hard = mx_strnew(size + 1);
    }
    for (int i = 0; whitend-- > 0; i++)
        hard[i] = ' ';
    buf = mx_num_to_str(file->f_stat.st_nlink, file->hard_l_len);
    mx_strcat(hard, buf);
    mx_strdel(&buf);
    hard[size] = ' ';
    return hard;
}
