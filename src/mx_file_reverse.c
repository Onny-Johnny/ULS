#include "../inc/uls.h"

void mx_file_reverse(t_file_data **head_ref) {
    t_file_data *prev = NULL;
    t_file_data *current = *head_ref;
    t_file_data *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; 
    }
    *head_ref = prev;
}
