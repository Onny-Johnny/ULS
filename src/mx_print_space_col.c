#include "../inc/uls.h"

void mx_print_space_col(t_flag_c *flag_c, int i, int j) {
    if (i + j + flag_c->row >= flag_c->name_num)
        return;
    flag_c->space = flag_c->col_len - flag_c->n_sizes[i + j];
    while (flag_c->space-- > 0)
        mx_printchar(' ');
}
