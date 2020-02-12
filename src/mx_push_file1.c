#include "../inc/uls.h"

static t_file_data *create_file(struct dirent *dirent) {
    t_file_data *head = malloc(sizeof(t_file_data));

    head->d_name = mx_strdup(dirent->d_name);
    head->d_len = dirent->d_namlen;
    head->gr_name = NULL;
    head->pw_name = NULL;
    head->d_name1 = NULL;
    head->next = NULL;
    return head;
}

void mx_push_file1(t_file_data **fl, struct dirent *dirent) {
    t_file_data *new_node = create_file(dirent);

    new_node->next = *fl;
    *fl = new_node;
}
