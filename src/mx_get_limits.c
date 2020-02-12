#include "../inc/uls.h"

static void get_hard_l_len(t_file_data **file, t_flagl_limits **ret) {
    (*file)->hard_l_len = mx_ret_num_len((*file)->f_stat.st_nlink, 0);

    if ((*ret)->hard_l_len < (*file)->hard_l_len)
        (*ret)->hard_l_len = (*file)->hard_l_len;
}

static void get_name_len(t_file_data **file, t_flagl_limits **ret) {
    struct passwd *pass = NULL;

    if ((pass = getpwuid((*file)->f_stat.st_uid)) != NULL) {
        (*file)->pw_name = mx_strdup(pass->pw_name);
        (*file)->usern_len = mx_strlen(pass->pw_name);
    } else {
        (*file)->usern_len = mx_ret_num_len((*file)->f_stat.st_uid, 0);
    }
    if ((*ret)->usern_len < (*file)->usern_len)
        (*ret)->usern_len = (*file)->usern_len;
}

static void get_g_len(t_file_data **file, t_flagl_limits **ret) {
    struct group *gr = NULL;

    if ((gr = getgrgid((*file)->f_stat.st_gid)) != NULL) {
        (*file)->gr_name = mx_strdup(gr->gr_name);
        (*file)->g_len = mx_strlen(gr->gr_name);
    } else {
        (*file)->g_len = mx_ret_num_len((*file)->f_stat.st_gid, 0);
    }
    if ((*ret)->g_len < (*file)->g_len)
        (*ret)->g_len = (*file)->g_len;
}

static void get_size_len(t_file_data **file, t_flagl_limits **ret) {
    if (((*file)->f_stat.st_mode & 0170000) == 0020000
        || ((*file)->f_stat.st_mode & 0170000) == 0060000) {
        (*file)->size_len = 8;
        (*ret)->cb = true;
    } else {
        (*file)->size_len = mx_ret_num_len_lld((*file)->f_stat.st_size, 0);
    }
    if ((*ret)->size_len < (*file)->size_len)
        (*ret)->size_len = (*file)->size_len;
}

t_flagl_limits *mx_get_limits(t_file_data **file, int *flags) {
    t_flagl_limits *ret = malloc(sizeof (t_flagl_limits));
    t_file_data *cur = *file;

    ret->usern_len = -1;
    ret->hard_l_len = -1;
    ret->g_len = -1;
    ret->size_len = -1;
    ret->cb = false;
    for (; cur; cur = cur->next) {
        get_hard_l_len(&cur, &ret);
        if (flags[18] == 0 && mx_get_last_u_names(*file, &cur))
            get_name_len(&cur, &ret);
        if (flags[19] == 0 && mx_get_last_g_names(*file, &cur))
            get_g_len(&cur, &ret);
        get_size_len(&cur, &ret);
    }
    return ret;
}

