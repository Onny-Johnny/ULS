#include "../inc/uls.h"

void mx_print_space_x_col(t_flag_c *flag_c, int j, int i) {
    if (j + 1 == flag_c->cols || j + i + 1 == flag_c->name_num)
        return;
    flag_c->space = flag_c->col_len - flag_c->n_sizes[i + j];
    while (flag_c->space-- > 0)
        mx_printchar(' ');
}
