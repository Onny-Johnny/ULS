#include "../inc/uls.h"

void mx_printend(t_file_data **file, int *flags) {
    if (!*file)
        return;
    if (flags[2] == 1 || (isatty(1) == 0 && flags[16] == 1)
        || (isatty(1) == 0 && flags[1] == 0
        && flags[3] == 0 && flags[12] == 0)) {
        mx_print_one(*file, flags);
    } else if (flags[3] == 1) {
        mx_print_l(file, flags);
    } else if (flags[12] == 1) {
        mx_print_x(*file, flags);
    } else if (((flags[1] && flags[9])
               || (!flags[1] && flags[9])) && isatty(1) == 1) {
        mx_print_c_col(*file, flags);
    } else {
        mx_print_c(*file, flags);
    }
}
