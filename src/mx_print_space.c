#include "../inc/uls.h"

void mx_print_space(t_flag_c *flag_c, int i, int j) {
    if (i + j + flag_c->row >= flag_c->name_num)
        return;
    flag_c->space = flag_c->col_len - flag_c->n_sizes[i + j];
    if (flag_c->n_sizes[i + j] % 8 == 0)
        flag_c->space -= 8;
    while (flag_c->space >= 0) {
        mx_printchar('\t');
        flag_c->space -= 8;
    }
}
