#include "../inc/uls.h"

static void pop_root(t_root **head) {
    t_root *next_node = NULL;

    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    next_node = (*head)->next;
    free(*head);
    *head = next_node;
}

void mx_clean_root(t_root **root) {
    while ((*root) != NULL) {
        mx_strdel(&(*root)->root_name);
        mx_strdel(&(*root)->root_name1);
        mx_clean_file(&(*root)->files);
        pop_root(root);
    }
}
