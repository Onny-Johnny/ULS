#include "../inc/uls.h"

static void get_ns(t_file_data *file, t_flag_c **flag_c) {
    int i = 0;

    (*flag_c)->d_names = (char**)malloc(sizeof (char*)
                         * (*flag_c)->name_num + 1);
    (*flag_c)->n_sizes = (int*)malloc(sizeof (int) * (*flag_c)->name_num);
    while (file) {
        (*flag_c)->d_names[i] = file->d_name;
        (*flag_c)->n_sizes[i++] = file->d_len;
        file = file->next;
    }
    (*flag_c)->d_names[(*flag_c)->name_num] = NULL;
}

static void max_fn_len(t_file_data *file, t_flag_c **flag_c) {
    (*flag_c)->name_num = 0;
    while (file) {
        (*flag_c)->name_num++;
        if ((*flag_c)->max_d_len < file->d_len)
            (*flag_c)->max_d_len = file->d_len;
        file = file->next;
    }
    (*flag_c)->cols = (*flag_c)->win.ws_col
                      / ((8 - ((*flag_c)->max_d_len % 8))
                      + (*flag_c)->max_d_len);
    if ((*flag_c)->cols == 0)
        return;
    (*flag_c)->row = (*flag_c)->name_num / (*flag_c)->cols;
    if ((*flag_c)->name_num % (*flag_c)->cols)
        (*flag_c)->row++;
}

static t_flag_c *get_c(t_file_data *file) {
    t_flag_c *flag_c = malloc(sizeof (t_flag_c));

    ioctl(1, TIOCGWINSZ, &flag_c->win);
    if (isatty(1) == 0)
        flag_c->win.ws_col = 86;
    flag_c->max_d_len = 0;
    max_fn_len(file, &flag_c);
    if (flag_c->cols == 0) {
        free(flag_c);
        flag_c = NULL;
        return NULL;
    }
    flag_c->col_len = 8 * ((flag_c->max_d_len / 8) + 1);
    get_ns(file, &flag_c);
    return flag_c;
}

static void flag_clean(t_flag_c **flag) {
    free((*flag)->d_names);
    free((*flag)->n_sizes);
    free(*flag);
    flag = NULL;
}

void mx_print_x(t_file_data *file, int *flags) {
    t_flag_c *flag_c = NULL;

    if (flags[12] && flags[9] && isatty(1) == 1) {
        mx_print_x_col(file, NULL);
        return;
    }
    if ((flag_c = get_c(file)) == NULL) {
        mx_print_one(file, flags);
        return;
    }
    for (int i = 0; i < flag_c->name_num; i += flag_c->cols) {
        for (int j = 0; j < flag_c->cols && j + i < flag_c->name_num; j++) {
            mx_printstr(flag_c->d_names[j + i]);
            mx_print_space_x(flag_c, j, i);
            file = file->next;
        }
        mx_printchar('\n');
    }
    flag_clean(&flag_c);
}
