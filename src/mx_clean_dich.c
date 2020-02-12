#include "../inc/uls.h"

static void pop_dich(t_dich **head) {
    t_dich *next_node = NULL;

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

void mx_clean_dich(t_dich **dich) {
    while ((*dich) != NULL) {
        free((*dich)->dich_name);
	(*dich)-> dich_name = NULL;
        pop_dich(dich);
    }
}
