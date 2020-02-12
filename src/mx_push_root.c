#include "../inc/uls.h"

static t_root *create_root(char *r, struct stat s, char *origr) {
    t_root *head = malloc(sizeof (t_root));

    head->root_name1 = mx_strdup(r);
    head->root_name = mx_strdup(origr);
    head->r_stat = s;
    head->files = NULL;
    head->next = NULL;
    return head;
}

void mx_push_root(t_root **ro, char *r, struct stat s, char *origr) {
    t_root *new_node = create_root(r, s, origr);

    new_node->next = *ro;
    *ro = new_node;
}
