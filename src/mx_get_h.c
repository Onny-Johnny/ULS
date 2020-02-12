#include "../inc/uls.h"

static int round_sz(double g) {
    off_t res;

    if (((off_t)(g * 10) % 10) >= 5)
        res = (off_t)(g * 10) / 10 + 1;
    else
        res = (off_t)(g * 10) / 10;
    return res;
}

static void make_byte(char *size, off_t sz) {
    if (sz == 0) {
        mx_strcat(size, "  0B");
    } else {
        mx_add_h(size, sz);
        size[6] = 'B';
    }
}

static void add_alp(char **size, int pow) {
    if (pow == 10)
        size[0][6] = 'K';
    else if (pow == 20)
        size[0][6] = 'M';
    else if (pow == 30)
        size[0][6] = 'G';
    else if (pow == 40)
        size[0][6] = 'T';
    else
        size[0][6] = 'P';
}

static void make_another(off_t sz, double g, int pow, char *size) {
    if (g >= 9.95) {
        sz = round_sz(g);
        if (sz < 999) {
            mx_add_h(size, sz);
        } else {
            sz = round_sz(g * 10);
            pow += 10;
            size[3] = sz / 10 + 48;
            size[4] = '.';
            size[5] = sz % 10 + 48;
        }
    } else {
        sz = round_sz(g * 10);
        size[3] = sz / 10 + 48;
        size[4] = '.';
        size[5] = sz % 10 + 48;
    }
    add_alp(&size, pow);
}

char *mx_get_h(off_t sz) {
    char *size = mx_strnew(7);
    double g = 0;
    int pow = 0;

    size[0] = ' ';
    size[1] = ' ';
    size[2] = ' ';
    if (sz < 1000) {
        make_byte(size, sz);
    } else {
        pow = mx_get_h_pow(sz);
        g = sz / mx_pow(2, pow);
        make_another(sz, g, pow, size);
    }
    return size;
}
