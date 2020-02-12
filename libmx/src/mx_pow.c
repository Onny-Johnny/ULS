#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    unsigned int i = 1;
    double num = n;

    if (pow == 0)
        return 1;
    while (i++ < pow)
        num = num * n;
    return num;
}
