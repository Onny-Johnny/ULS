#include "../inc/uls.h"

static void root_count(t_uls **uls, int argc, char **argv) {
    (*uls)->root_num = 0;
    if ((*uls)->r_s < argc &&
        mx_strcmp(argv[(*uls)->r_s], "--") == 0) {
        (*uls)->r_s++;
    }
    for (int i = (*uls)->r_s; i < argc; i++)
        (*uls)->root_num++;
}

char **mx_get_root(t_uls **uls, int argc, char **argv) {
    char **root = NULL;
    int index = 0;

    root_count(uls, argc, argv);
    if ((*uls)->root_num > 0) {
        root = (char**)malloc((*uls)->root_num * sizeof (char*) + 1);
        root[(*uls)->root_num] = NULL;
        for (int i = (*uls)->r_s; i < argc; i++)
            root[index++] = mx_strdup(argv[i]);
    } else {
        (*uls)->root_num = 1;
        root = (char**)malloc(2 * sizeof (char*));
        root[1] = NULL;
        root[0] = mx_strdup(".");
    }
    return root;
}
