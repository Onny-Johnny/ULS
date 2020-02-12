#include "../inc/uls.h"

static bool comp(t_root *a, t_root *b) {
    long t1 = 0;
    long t2 = 0;

    t1 = a->r_stat.st_ctime;
    t2 = b->r_stat.st_ctime;
    if (t1 < t2)
        return true;
    if (t1 == t2) {
        t1 = a->r_stat.st_ctimespec.tv_nsec;
        t2 = b->r_stat.st_ctimespec.tv_nsec;
    }
    if (t1 < t2)
        return true;
    if (t1 == t2 && mx_strcmp(a->root_name, b->root_name) > 0)
        return true;
    return false;
}

static t_root *sort_status_change(t_root *a, t_root *b) {
    t_root *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (comp(a, b)) {
        result = a;
        result->next = sort_status_change(a->next, b);
    } else {
        result = b;
        result->next = sort_status_change(a, b->next);
    }
    return result;
}

void mx_merge_sort_status_r_root(t_root **r) {
    t_root *head = *r;
    t_root *a = NULL;
    t_root *b = NULL;

    if ((head == NULL) || (head->next == NULL))
        return;
    mx_split_f_b_root(head, &a, &b);
    mx_merge_sort_status_r_root(&a);
    mx_merge_sort_status_r_root(&b);
    *r = sort_status_change(a, b);
}
