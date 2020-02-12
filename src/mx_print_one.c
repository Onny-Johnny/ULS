#include "../inc/uls.h"

void mx_print_one(t_file_data *file, int *flags) {
    char *acs = NULL;

    if ((isatty(1) == 1) && (flags[9] == 1)) {
        while (file != NULL) {
            acs = mx_get_access_col(file->f_stat.st_mode);
            mx_print_col(file->d_name, acs);
            mx_printchar('\n');
            mx_strdel(&acs);
            file = file->next;
        }
    } else {
        while (file != NULL) {
            mx_printstr(file->d_name);
            mx_printchar('\n');
            file = file->next;
        }
    }
}
