#include "../inc/uls.h"

static char *get_major(dev_t r_dev, char *buf) {
    char *major = NULL;
    int num = (int32_t)(((u_int32_t)(r_dev) >> 24) & 0xff);
    int size = mx_ret_num_len(num, 0);
    int whitend = 3 - size;

    major = mx_strnew(3);
    for (int i = 0; whitend-- > 0; i++)
        major[i] = ' ';
    buf = mx_num_to_str(num, size);
    mx_strcat(major, buf);
    mx_strdel(&buf);
    return major;
}

static char *hex_minor_go(int num) {
    char *hex = mx_nbr_to_hex(num);
    int size = mx_strlen(hex);
    char *ret = mx_strnew(10);
    int zero_num = 8 - size;

    ret[0] = '0';
    ret[1] = 'x';
    for (int i = 2; zero_num-- > 0; i++)
        ret[i] = '0';
    mx_strcat(ret, hex);
    mx_strdel(&hex);
    return ret;
}

static char *get_minor(dev_t r_dev, char *buf) {
    char *minor = NULL;
    int num = (int32_t)((r_dev) & 0xffffff);
    int size = 0;
    int whitend = 0;

    if (num < 255) {
        size = mx_ret_num_len(num, 0);
        whitend = 3 - size;
        minor = mx_strnew(3);
        for (int i = 0; whitend-- > 0; i++)
            minor[i] = ' ';
        buf = mx_num_to_str(num, size);
        mx_strcat(minor, buf);
        mx_strdel(&buf);
        return minor;
    }
    minor = hex_minor_go(num);
    return minor;
}

char *mx_get_min_maj(dev_t r_dev, int size) {
    char *major = NULL;
    char *minor = NULL;
    char *ret = NULL;

    major = get_major(r_dev, NULL);
    minor = get_minor(r_dev, NULL);
    size = 3 + mx_strlen(minor) + 4;
    ret = mx_strnew(size);
    ret[0] = ' ';
    ret[1] = ' ';
    mx_strcat(ret, major);
    mx_strcat(ret, ", ");
    mx_strcat(ret, minor);
    mx_strdel(&major);
    mx_strdel(&minor);
    return ret;
}
