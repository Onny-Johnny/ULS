#include "../inc/libmx.h"

void mx_printint(int n) {
    long res = n;

    if (res < 0) {
        res = -res;
        mx_printchar('-');
    }
    if (res / 10 != 0)
        mx_printint(res / 10);
    mx_printchar(res % 10 + '0');
}
