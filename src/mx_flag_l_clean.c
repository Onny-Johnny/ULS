#include "../inc/uls.h"

void mx_flag_l_clean(t_flag_l **fl_l) {
    mx_strdel(&(*fl_l)->access);
    mx_strdel(&(*fl_l)->hard_links);
    mx_strdel(&(*fl_l)->user_name);
    mx_strdel(&(*fl_l)->group_name);
    mx_strdel(&(*fl_l)->size);
    mx_strdel(&(*fl_l)->time);
    free(*fl_l);
    *fl_l = NULL;
}
