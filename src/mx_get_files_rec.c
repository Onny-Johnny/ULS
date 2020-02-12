#include "../inc/uls.h"

static bool is_cont(char *name, int *flags) {
    if ((flags[0] == 0 && name[0] == '.' && flags[14] == 0)
        || (flags[14] == 1 && (mx_strcmp(".", name) == 0
        || mx_strcmp("..", name) == 0))) {
        return true;
    }
    return false;
}

static void make_roat(char *root_name, struct dirent *buf, char **str) {
    int size = mx_strlen(root_name) + buf->d_namlen + 1;

    *str = mx_strnew(size);
    mx_strcat(*str, root_name);
    mx_strcat(*str, "/");
    mx_strcat(*str, buf->d_name);
}

t_file_data *mx_get_files_rec(char *dir, int *flags, char *name, char *str) {
    t_file_data *file = NULL;
    DIR *dr = NULL;
    struct dirent *buf0 = NULL;
    struct stat buf;

    if ((dr = opendir(dir)) == NULL) {
        mx_printerr("uls: ");
        perror(name);
        flags[21] = 1;
        return NULL;
    }
    while ((buf0 = readdir(dr)) != NULL) {
        if (is_cont(buf0->d_name, flags))
            continue;
        make_roat(dir, buf0, &str);
        lstat(str, &buf);
        mx_push_file(&file, buf0, buf, str);
    }
    closedir(dr);
    return file;
}
