#include "../inc/uls.h"

void mx_root_reverse(t_root **head_ref) {
    t_root *prev = NULL;
    t_root *current = *head_ref;
    t_root *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
