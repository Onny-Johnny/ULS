#include "../inc/uls.h"

static t_file_data *create_file(struct dirent *d, struct stat s, char *str) {
    t_file_data *head = malloc(sizeof(t_file_data));

    head->d_name = mx_strdup(d->d_name);
    head->d_name1 = str;
    head->d_len = d->d_namlen;
    head->f_stat = s;
    head->usern_len = 0;
    head->hard_l_len = 0;
    head->g_len = 0;
    head->size_len = -1;
    head->gr_name = NULL;
    head->pw_name = NULL;
    head->next = NULL;
    return head;
}

void mx_push_file(t_file_data **fl, struct dirent *d, struct stat s, char *str) {
    t_file_data *new_node = create_file(d, s, str);

    new_node->next = *fl;
    *fl = new_node;
}
