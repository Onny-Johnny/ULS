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
    (*flag_c)->cols = ((*flag_c)->win.ws_col
                      / ((8 - ((*flag_c)->max_d_len % 8))
                      + (*flag_c)->max_d_len));
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

void mx_print_c(t_file_data *file, int *flags) {
    t_flag_c *flag_c = get_c(file);

    if (!flag_c) {
        mx_print_one(file, flags);
        return;
    }
    for (int i = 0; i < flag_c->row; i++) {
        for (int j = 0; i + j < flag_c->name_num; j+= flag_c->row) {
            mx_printstr(flag_c->d_names[i + j]);
            mx_print_space(flag_c, i, j);
        }
        mx_printchar('\n');
    }
    free(flag_c->d_names);
    free(flag_c->n_sizes);
    free(flag_c);
    flag_c = NULL;
}
