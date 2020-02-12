#include "../inc/uls.h"

static bool comp(t_root *a, t_root *b) {
    if (a->r_stat.st_size > b->r_stat.st_size)
        return true;
    if (a->r_stat.st_size == b->r_stat.st_size
        && mx_strcmp(a->root_name, b->root_name) < 0) {
        return true;
    }
    return false;
}

static t_root *sort_size(t_root *a, t_root *b) {
    t_root *result = NULL;

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

void mx_merge_sort_size_root(t_root **r) {
    t_root *head = *r;
    t_root *a = NULL;
    t_root *b = NULL;

    if ((head == NULL) || (head->next == NULL))
        return;
    mx_split_f_b_root(head, &a, &b);
    mx_merge_sort_size_root(&a);
    mx_merge_sort_size_root(&b);
    *r = sort_size(a, b);
}
