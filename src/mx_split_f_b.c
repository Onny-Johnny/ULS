#include "../inc/uls.h"

void mx_split_f_b(t_file_data *head, t_file_data **f_ref, t_file_data **b_ref) {
    t_file_data *fast;
    t_file_data *slow;

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
