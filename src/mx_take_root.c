#include "../inc/uls.h"

static void sort_rev(t_root **r, int *flags) {
    if (flags[4] == 1)
        mx_merge_sort_size_r_root(r);
    else if (flags[13] == 1 && flags[5] == 1)
        mx_merge_sort_status_r_root(r);
    else if (flags[7] == 1 && flags[5] == 1)
        mx_merge_sort_last_acc_r_root(r);
    else if (flags[5] == 1)
        mx_merge_sort_modification_r_root(r);
    else
        mx_merge_sort_r_root(r);
}

static void sort_r(t_root **r, int *flags) {
    if (flags[17] == 1) {
        mx_root_reverse(r);
        return;
    }
    if (flags[15] == 1) {
        sort_rev(r, flags);
        return;
    } else {
        if (flags[4] == 1)
            mx_merge_sort_size_root(r);
        else if (flags[13] == 1 && flags[5] == 1)
            mx_merge_sort_status_root(r);
        else if (flags[7] == 1 && flags[5] == 1)
            mx_merge_sort_last_acc_root(r);
        else if (flags[5] == 1)
            mx_merge_sort_modification_root(r);
        else
            mx_merge_sort_root(r);
    }
}

static void make_buf(char *r, char **buf) {
    int size = mx_strlen(r) + 1;

    *buf = mx_strnew(size);
    mx_strcat(*buf, r);
    mx_strcat(*buf, "/");
}

t_root *mx_take_root(t_uls *uls, char *push, int *root_num) {
    t_root *root = NULL;
    DIR *dir = NULL;
    char *buf = NULL;
    struct stat st;

    *root_num = 0;
    for (int i = 0; uls->root[i] != NULL; i++) {
        push = mx_strdup(uls->root[i]);
        if ((dir = opendir(push)) != NULL) {
            make_buf(push, &buf);
            lstat(buf, &st);
            mx_push_root(&root, buf, st, push);
            closedir(dir);
            *root_num += 1;
        }
        mx_strdel(&buf);
        mx_strdel(&push);
    }
    sort_r(&root, uls->flags);
    return root;
}
