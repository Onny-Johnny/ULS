#include "../inc/uls.h"

static bool is_cont(char *name, int *flags) {
    if ((flags[14] == 0 && name[0] == '.' && flags[0] == 0)
        || (flags[14] == 1 && (mx_strcmp(".", name) == 0
        || mx_strcmp("..", name) == 0))) {
        return true;
    }
    return false;
}

static void make_roat(char *root_name, struct dirent *buf, char **str) {
    int size = mx_strlen(root_name) + buf->d_namlen;

    *str = mx_strnew(size);
    mx_strcat(*str, root_name);
    mx_strcat(*str, buf->d_name);
}

static void m_roat(t_root *r, struct dirent *buf0, char **str) {
    int size = 0;

    if (mx_strcmp(r->root_name, "/") == 0) {
        size = 1 + buf0->d_namlen;
        *str = mx_strnew(size);
        mx_strcat(*str, r->root_name);
        mx_strcat(*str, buf0->d_name);
    } else {
        make_roat(r->root_name1, buf0, str);
    }
}

t_file_data *mx_get_files(t_root **r, int *flags) {
    t_file_data *file = NULL;
    DIR *dir = NULL;
    struct dirent *buf0 = NULL;
    struct stat buf;
    char *str = NULL;

    (*r)->rn = 0;
    dir = opendir((*r)->root_name);
    while ((buf0 = readdir(dir)) != NULL) {
        if (is_cont(buf0->d_name, flags))
            continue;
        m_roat(*r, buf0, &str);
        lstat(str, &buf);
        if (flags[10] == 1 && (buf.st_mode & 0170000) == 0040000)
            (*r)->rn += 1;
        mx_push_file(&file, buf0, buf, str);
    }
    closedir(dir);
    return file;
}
