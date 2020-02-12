#include "../inc/uls.h"

void mx_printerr(char *s) {
    write(2, s, mx_strlen(s));
}
