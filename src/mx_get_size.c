#include "../inc/uls.h"

char *mx_get_size(t_file_data *file, t_flagl_limits *lim) {
    char *siz = NULL;
    char *buf = NULL;
    int whitend = lim->size_len - file->size_len;

    if (whitend > 0)
        siz = mx_strnew(whitend + file->size_len + 2);
    else
        siz = mx_strnew(file->size_len + 2);
    siz[0] = ' ';
    siz[1] = ' ';
    for (int i = 2; whitend-- > 0; i++)
        siz[i] = ' ';
    buf = mx_lld_num_to_str(file->f_stat.st_size, file->size_len);
    mx_strcat(siz, buf);
    mx_strdel(&buf);
    return siz;
}
