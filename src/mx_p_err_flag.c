#include "../inc/uls.h"

void mx_p_err_flag(char c) {
    mx_printerr("uls: illegal option -- ");
    mx_printerr_char(c);
    mx_printerr("\n");
    mx_printerr("usage: uls [-ACGRSTacfghlnortux1@] [file ...]");
    mx_printerr("\n");
}
