#include "../inc/uls.h"

static t_file_data *sorted_merge(t_file_data *a, t_file_data *b) {
    t_file_data *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (mx_strcmp(a->d_name, b->d_name) > 0) {
        result = a;
        result->next = sorted_merge(a->next, b);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return result;
}

void mx_merge_sort_r(t_file_data **file) {
    t_file_data *head = *file;
    t_file_data *a = NULL;
    t_file_data *b = NULL;

    if ((head == NULL) || (head->next == NULL))
        return;
    mx_split_f_b(head, &a, &b);
    mx_merge_sort_r(&a);
    mx_merge_sort_r(&b);
    *file = sorted_merge(a, b);
}
