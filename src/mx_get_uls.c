#include "../inc/uls.h"

t_uls *mx_get_uls(int argc, char **argv) {
    t_uls *uls = malloc(sizeof (t_uls));

    if (!(uls->flags = mx_get_sorted_flags(argc, argv, &uls))) {
        free(uls);
        exit(1);
    }
    uls->root = mx_get_root(&uls, argc, argv);
    if (uls->flags[17] == 1) {
        uls->flags[4] = 0;
        uls->flags[5] = 0;
        uls->flags[14] = 0;
        return uls;
    }
    return uls;
}
