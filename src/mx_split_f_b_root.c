#include "../inc/uls.h"

void mx_split_f_b_root(t_root *head, t_root **f_ref, t_root **b_ref) {
    t_root *fast;
    t_root *slow;

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
