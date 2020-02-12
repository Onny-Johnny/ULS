#include "../inc/uls.h"

static bool no_flag(char c) {
    if (c == 'C' || c == '1' || c == 'a'
        || c == 'S' || c == 'l' || c == '@'
        || c == 't' || c == 'u' || c == 'h'
        || c == 'G' || c == 'R' || c == 'T'
        || c == 'c' || c == 'A' || c == 'r'
        || c == 'x' || c == 'f' || c == 'g'
        || c == 'o' || c == 'n') {
        return false;
    }
    return true;
}

bool mx_is_no_our_flags(char *flags) {
    for (int i = 1; flags[i] != '\0'; i++) {
        if (no_flag(flags[i])) {
            mx_p_err_flag(flags[i]);
            return true;
        }
    }
    return false;
}
