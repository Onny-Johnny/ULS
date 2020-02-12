#include "../inc/uls.h"

void mx_clean_uls(t_uls **uls) {
    free((*uls)->flags);
    mx_del_strarr(&((*uls)->root));
    free(*uls);
    *uls = NULL;
}
