#include "../inc/uls.h"

static bool is_in(char *str) {
    struct stat st;

    lstat(str, &st);
    if (st.st_nlink != 0)
        return true;
    return false;
}

static void file_make(t_file_data **file, char *push) {
    struct stat st;
    char *buf = NULL;
    int size = mx_strlen(push);

    buf = mx_strnew(size + 2);
    mx_strcat(buf, ".");
    mx_strcat(buf, "/");
    mx_strcat(buf, push);
    lstat(buf, &st);
    mx_push_file_light(file, st, buf, push);
}

void mx_print_dich_inputs(t_uls *uls, t_file_data *files, int root_num, int *rn) {
    DIR *dir = NULL;
    char *push = NULL;
    t_dich *t = NULL;

    for (int i = 0; uls->root[i] != NULL; i++) {
        push = mx_strdup(uls->root[i]);
        if (!(dir = opendir(push))) {
            if (is_in(push))
                file_make(&files, push);
            else
                mx_push_dich(&t, push);
            *rn += 1;
        } else {
            mx_strdel(&push);
            closedir(dir);
        }
    }
    mx_print_dich(&t, uls->flags);
    mx_p_l(&files, uls->flags, root_num);
}
