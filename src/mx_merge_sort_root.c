#include "../inc/uls.h"

static t_root *sorted_merge(t_root *a, t_root *b) {
    t_root *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (mx_strcmp(a->root_name, b->root_name) < 0) {
        result = a;
        result->next = sorted_merge(a->next, b);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return result;
}

void mx_merge_sort_root(t_root **r) {
    t_root *head = *r;
    t_root *a = NULL;
    t_root *b = NULL;

    if ((head == NULL) || (head->next == NULL))
        return;
    mx_split_f_b_root(head, &a, &b);
    mx_merge_sort_root(&a);
    mx_merge_sort_root(&b);
    *r = sorted_merge(a, b);
}
