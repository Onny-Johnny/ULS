#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char hex[8] = {'\0'};
    int i = 0;
    char *ret = NULL;
    int size = 0;

    while (nbr != 0) {
        if ((nbr % 16) >= 10)
            hex[i++] = (nbr % 16) + '0' + 39;
        else
            hex[i++] = (nbr % 16) + '0';
        nbr /= 16;
    }
    size = i--;
    ret = mx_strnew(size);
    for (int k = 0; k < size; k++, i--)
        ret[k] = hex[i];
    return ret;
}
