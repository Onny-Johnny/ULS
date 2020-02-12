#include "../inc/uls.h"

static bool comp(t_file_data *a, t_file_data *b) {
    if (a->f_stat.st_size < b->f_stat.st_size)
        return true;
    if (a->f_stat.st_size == b->f_stat.st_size
        && mx_strcmp(a->d_name, b->d_name) > 0) {
        return true;
    }
    return false;
}

static t_file_data *sort_size(t_file_data *a, t_file_data *b) {
    t_file_data *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (comp(a, b)) {
        result = a;
        result->next = sort_size(a->next, b);
    } else {
        result = b;
        result->next = sort_size(a, b->next);
    }
    return result;
}

void mx_merge_sort_size_r(t_file_data **file) {
    t_file_data *head = *file;
    t_file_data *a = NULL;
    t_file_data *b = NULL;

    if ((head == NULL) || (head->next == NULL))
        return;
    mx_split_f_b(head, &a, &b);
    mx_merge_sort_size_r(&a);
    mx_merge_sort_size_r(&b);
    *file = sort_size(a, b);
}
