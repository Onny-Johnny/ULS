#include "../inc/uls.h"

static char *ret_user(int whitend, int size) {
    char *ret = NULL;

    if (whitend > 0) {
        ret = mx_strnew(whitend + size);
        return ret;
    } else {
        ret = mx_strnew(size);
        return ret;
    }
}

static void make_name(uid_t usid, char **user, int size) {
    char *buf = NULL;

    buf = mx_num_to_str(usid, size);
    mx_strcat(user[0], buf);
    mx_strdel(&buf);
}

char *mx_get_user_name(t_file_data *file, t_flagl_limits *lim) {
    char *user = NULL;
    int whitend = 0;

    whitend = lim->usern_len - file->usern_len;
    user = ret_user(whitend, file->usern_len);
    if (file->pw_name != NULL)
        mx_strcat(user, file->pw_name);
    else
        make_name(file->f_stat.st_uid, &user, file->usern_len);
     for (int i = file->usern_len; whitend-- > 0; i++)
        user[i] = ' ';
    return user;
}
