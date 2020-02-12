#include "../inc/uls.h"

void mx_add_h(char *size, off_t sz) {
    for (int i = 5; i >= 3; i--) {
        if (sz > 0) {
            size[i] = sz % 10 + '0';
            sz /= 10;
        } else {
            size[i] = ' ';
        }
    }
}
