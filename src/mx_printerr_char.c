#include "../inc/uls.h"

void mx_printerr_char(char c) {
    write(2, &c, 1);
}
