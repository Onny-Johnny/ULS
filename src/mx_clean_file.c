#include "../inc/uls.h"

static void head_cleaner(t_file_data **head) {
    mx_strdel(&(*head)->d_name);
    mx_strdel(&(*head)->d_name1);
    mx_strdel(&(*head)->gr_name);
    mx_strdel(&(*head)->pw_name);
    free(*head);
    *head = NULL;
}

static void pop_file(t_file_data **head) {
    t_file_data *next_node = NULL;

    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) {
        head_cleaner(head);
        return;
    }
    next_node = (*head)->next;
    head_cleaner(head);
    *head = next_node;
}

void mx_clean_file(t_file_data **file) {
    while ((*file) != NULL)
        pop_file(file);
}
