#include "../inc/uls.h"

void mx_print_space_x(t_flag_c *flag_c, int j, int i) {
    if (j + 1 == flag_c->cols || j + i + 1 == flag_c->name_num)
        return;
    flag_c->space = flag_c->col_len - flag_c->n_sizes[j + i];
    if (flag_c->n_sizes[j + i] % 8 == 0)
        flag_c->space -= 8;
    while (flag_c->space >= 0) {
        mx_printchar('\t');
        flag_c->space -= 8;
    }
}
