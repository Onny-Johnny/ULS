#include "../inc/uls.h"

static bool comp(t_file_data *a, t_file_data *b) {
    long t1 = 0;
    long t2 = 0;

    t1 = a->f_stat.st_mtime;
    t2 = b->f_stat.st_mtime;
    if (t1 > t2)
        return true;
    if (t1 == t2) {
        t1 = a->f_stat.st_mtimespec.tv_nsec;
        t2 = b->f_stat.st_mtimespec.tv_nsec;
    }
    if (t1 > t2)
        return true;
    if (t1 == t2 && mx_strcmp(a->d_name, b->d_name) < 0)
        return true;
    return false;
}

static t_file_data *sort_modification(t_file_data *a, t_file_data *b) {
    t_file_data *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (comp(a, b)) {
        result = a;
        result->next = sort_modification(a->next, b);
    } else {
        result = b;
        result->next = sort_modification(a, b->next);
    }
    return result;
}

void mx_merge_sort_modification(t_file_data **file) {
    t_file_data *head = *file;
    t_file_data *a = NULL;
    t_file_data *b = NULL;

    if ((head == NULL) || (head->next == NULL))
        return;
    mx_split_f_b(head, &a, &b);
    mx_merge_sort_modification(&a);
    mx_merge_sort_modification(&b);
    *file = sort_modification(a, b);
}
