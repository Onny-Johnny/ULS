#include "../inc/uls.h"

static void print_dir(char *name, char *acs) {
    if ((acs[9] == 't' || acs[9] == 'T') && acs[8] == 'w') {
        mx_printstr(MX_BGREEN);
        mx_printstr(name);
        mx_printstr(MX_RESET);
    } else if (acs[8] == 'w') {
        mx_printstr(MX_BBBRRED);
        mx_printstr(name);
        mx_printstr(MX_RESET);
    } else {
        mx_printstr(MX_BLUE);
        mx_printstr(name);
        mx_printstr(MX_RESET);
    }
}

static void print_ex(char *name, char *acs) {
    if (acs[3] == 's' || acs[3] == 'S') {
        mx_printstr(MX_BRED);
        mx_printstr(name);
        mx_printstr(MX_RESET);
    } else if (acs[6] == 's' || acs[6] == 'S') {
        mx_printstr(MX_BBBLUE);
        mx_printstr(name);
        mx_printstr(MX_RESET);
    } else {
        mx_printstr(MX_RED);
        mx_printstr(name);
        mx_printstr(MX_RESET);
    }
}

static void print_col1(char *name, char *acs) {
    if (acs[0] == 'p') {
        mx_printstr(MX_BRRED);
        mx_printstr(name);
        mx_printstr(MX_RESET);
    } else if (acs[0] == 'b') {
        mx_printstr(MX_BBLUE);
        mx_printstr(name);
        mx_printstr(MX_RESET);
    } else if (acs[0] == 'c') {
        mx_printstr(MX_BBRRED);
        mx_printstr(name);
        mx_printstr(MX_RESET);
    } else if (acs[0] == 'p') {
        mx_printstr(MX_BRRED);
        mx_printstr(name);
        mx_printstr(MX_RESET);
    } else {
        mx_printstr(name);
    }
}

void mx_print_col(char *name, char *acs) {
    if (acs[0] == 'd') {
        print_dir(name, acs);
    } else if (acs[0] == '-' && (acs[3] == 'x'
                || acs[3] == 's' || acs[6] == 'x'
                || acs[6] == 's')) {
        print_ex(name, acs);
    } else if (acs[0] == 'l') {
        mx_printstr(MX_PURPLE);
        mx_printstr(name);
        mx_printstr(MX_RESET);
    } else if (acs[0] == 's') {
        mx_printstr(MX_GREEN);
        mx_printstr(name);
        mx_printstr(MX_RESET);
    } else {
        print_col1(name, acs);
    }
}
