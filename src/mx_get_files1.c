#include "../inc/uls.h"

static bool is_cont(char *name, int *flags) {
    if ((flags[0] == 0 && name[0] == '.' && flags[14] == 0)
        || (flags[14] == 1 && (mx_strcmp(".", name) == 0
        || mx_strcmp("..", name) == 0))) {
        return true;
    }
    return false;
}

t_file_data *mx_get_files1(t_root *r, int *flags) {
    t_file_data *file = NULL;
    DIR *dir = NULL;
    struct dirent *dirent;

    dir = opendir(r->root_name);
    while ((dirent = readdir(dir)) != NULL) {
        if (is_cont(dirent->d_name, flags))
            continue;
        mx_push_file1(&file, dirent);
    }
    closedir(dir);
    return file;
}
