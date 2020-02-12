#include "../inc/uls.h"

static t_file_data *create_file(struct stat s, char *s1, char *s2) {
    t_file_data *head = malloc(sizeof (t_file_data));

    head->d_name = s2;
    head->d_name1 = s1;
    head->d_len = mx_strlen(s2);
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

void mx_push_file_light(t_file_data **list, struct stat s, char *s1, char *s2) {
    t_file_data *cur = NULL;

    if (!(*list)) {
        *list = create_file(s, s1, s2);
        return;
    }
    cur = *list;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = create_file(s, s1, s2);
    cur = cur->next;
}
