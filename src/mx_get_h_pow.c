#include "../inc/uls.h"

int mx_get_h_pow(off_t sz) {
    int pow = 0;

    while (sz >= 1000) {
        sz /= 1024;
        pow += 10;
    }
    return pow;
}
