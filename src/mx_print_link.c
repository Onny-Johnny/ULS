#include "../inc/uls.h"

void mx_print_link(t_file_data *file) {
    char buf[4096] = {'\0'};

    readlink(file->d_name1, buf, 4096);
    mx_printstr(" -> ");
    mx_printstr(buf);
}
