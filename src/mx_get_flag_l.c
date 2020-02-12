#include "../inc/uls.h"

static char *ret_time(t_file_data *file, int *flags) {
    if (flags[11] == 1) {
        if (flags[7] == 1)
            return mx_get_time_big(file->f_stat.st_atime);
        else if (flags[13] == 1)
            return mx_get_time_big(file->f_stat.st_ctime);
        return mx_get_time_big(file->f_stat.st_mtime);
    }
    if (flags[7] == 1)
        return mx_get_time(file->f_stat.st_atime);
    else if (flags[13] == 1)
        return mx_get_time(file->f_stat.st_ctime);
    return mx_get_time(file->f_stat.st_mtime);
}

t_flag_l *mx_get_flag_l(t_flagl_limits *lim, t_file_data *file, int *flags) {
    t_flag_l *fl_l = malloc(sizeof (t_flag_l));

    fl_l->access = mx_get_access(file);
    fl_l->hard_links = mx_get_hard_links(file, lim);
    if (flags[18] == 1)
        fl_l->user_name = NULL;
    else
        fl_l->user_name = mx_get_user_name(file, lim);
    if (flags[19] == 1)
        fl_l->group_name = NULL;
    else
        fl_l->group_name = mx_get_g_name(file, lim);
    if (fl_l->access[0] == 'b' || fl_l->access[0] == 'c')
        fl_l->size = mx_get_min_maj(file->f_stat.st_rdev, 0);
    else if (flags[8] == 1 && lim->cb == false)
        fl_l->size = mx_get_h(file->f_stat.st_size);
    else
        fl_l->size = mx_get_size(file, lim);
    fl_l->time = ret_time(file, flags);
    return fl_l;
}
