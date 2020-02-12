#include "../inc/uls.h"

static char *ret_grou(int whitend, int size) {
    char *ret = NULL;

    if (whitend > 0) {
        ret = mx_strnew(whitend + size);
        return ret;
    } else {
        ret = mx_strnew(size);
        return ret;
    }
}

static void make_grou(gid_t gr_id, char **grou, int size) {
    char *buf = NULL;

    buf = mx_num_to_str(gr_id, size);
    mx_strcat(grou[0], buf);
    mx_strdel(&buf);
}

char *mx_get_g_name(t_file_data *file, t_flagl_limits *lim) {
    char *grou = NULL;
    int whitend = 0;

    whitend = lim->g_len - file->g_len;
    grou = ret_grou(whitend, file->g_len);
    if (file->gr_name != NULL)
        mx_strcat(grou, file->gr_name);
    else
        make_grou(file->f_stat.st_gid, &grou, file->g_len);
    for (int i = file->g_len; whitend-- > 0; i++)
        grou[i] = ' ';
    return grou;
}
