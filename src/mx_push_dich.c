#include "../inc/uls.h"

static t_dich *create_dich(char *dich_name) {
    t_dich *head = malloc(sizeof (t_dich));

    head->dich_name = dich_name;
    head->next = NULL;
    return head;
}

void mx_push_dich(t_dich **tr, char *dich_name) {
    t_dich *cur = NULL;

    if (*tr == NULL) {
        *tr = create_dich(dich_name);
        return;
    }
    cur = *tr;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = create_dich(dich_name);
    cur = cur->next;
}
