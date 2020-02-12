#include "../inc/uls.h"

static void split_f_b(t_dich *head, t_dich **f_ref, t_dich **b_ref) {
    t_dich *fast;
    t_dich *slow;

    slow = head;
    fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *f_ref = head;
    *b_ref = slow->next;
    slow->next = NULL;
}

static t_dich *sorted_merge(t_dich *a, t_dich *b) {
    t_dich *result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (mx_strcmp(a->dich_name, b->dich_name) < 0) {
        result = a;
        result->next = sorted_merge(a->next, b);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return result;
}

static void merge_sort(t_dich **t) {
    t_dich *head = *t;
    t_dich *a = NULL;
    t_dich *b = NULL;

    if ((head == NULL) || (head->next == NULL))
        return;
    split_f_b(head, &a, &b);
    merge_sort(&a);
    merge_sort(&b);
    *t = sorted_merge(a, b);
}

void mx_print_dich(t_dich **t, int *flags) {
    DIR *dir = NULL;
    t_dich *cur = NULL;

    flags[21] = 1;
    if (!flags[17])
        merge_sort(t);
    cur = *t;
    while (cur) {
        dir = opendir(cur->dich_name);
        mx_printerr("uls: ");
        perror(cur->dich_name);
        cur = cur->next;
    }
    mx_clean_dich(t);
}
