#include "../inc/uls.h"

void mx_print_ex_atr(char *name, int size) {
    char buf[1024] = {'\0'};
    ssize_t xattr = 0;
    int plus = 0;
    int sp = 0;

    listxattr(name, buf, 1024, 0x0001);
    while (buf[plus]) {
        xattr = getxattr(name, buf + plus, 0, 1024, 0, 0x0001);
        mx_printchar('\t');
        mx_printstr(buf + plus);
        mx_printchar('\t');
        sp = size - mx_ret_num_len((int)xattr, 0);
        while (sp-- > 0)
            mx_printchar(' ');
        mx_printint((int)xattr);
        mx_printchar(' ');
        mx_printchar('\n');
        plus += mx_strlen(buf + plus) + 1;
    }
}
