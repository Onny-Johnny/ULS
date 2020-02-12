#include "../inc/uls.h"

static void make_access0(mode_t mode, char **access) {
    if ((mode & 0170000) == 0040000)
        access[0][0] = 'd';
    else if ((mode & 0170000) == 0020000)
        access[0][0] = 'c';
    else if ((mode & 0170000) == 0060000)
        access[0][0] = 'b';
    else if ((mode & 0170000) == 0010000)
        access[0][0] = 'p';
    else if ((mode & 0170000) == 0120000)
        access[0][0] = 'l';
    else if ((mode & 0170000) == 0140000)
        access[0][0] = 's';
}

static void make_access1(mode_t mode, char **access) {
    if (0000400 & mode)
        access[0][1] = 'r';
    if (0000200 & mode)
        access[0][2] = 'w';
    if (0000100 & mode)
        access[0][3] = 'x';
    if (000040 & mode)
        access[0][4] = 'r';
    if (000020 & mode)
        access[0][5] = 'w';
    if (0000010 & mode)
        access[0][6] = 'x';
    if (0000004 & mode)
        access[0][7] = 'r';
    if (0000002 & mode)
        access[0][8] = 'w';
    if (0000001 & mode)
        access[0][9] = 'x';
}

static void make_access2(char **access, char *name) {
    ssize_t xattr = 0;
    acl_t acl = NULL;

    xattr = listxattr(name, NULL, 0, 0x0001);
    if (xattr <= 0)
        acl = acl_get_file(name, 0x00000100);
    if (xattr > 0)
        access[0][10] = '@';
    else if (acl != NULL)
        access[0][10] = '+';
    acl_free(acl);
}

static void make_access3(mode_t mode, char **access) {
    if (access[0][3] == 'x' && mode & 0004000)
        access[0][3] = 's';
    else if (mode & 0004000)
        access[0][3] = 'S';
    if (access[0][6] == 'x' && mode & 0002000)
        access[0][6] = 's';
    else if (mode & 0002000)
        access[0][6] = 'S';
}

char *mx_get_access(t_file_data *file) {
    char *acc = NULL;

    acc = mx_strnew(12);
    mx_strcpy(acc, "----------  ");
    make_access0(file->f_stat.st_mode, &acc);
    make_access1(file->f_stat.st_mode, &acc);
    make_access2(&acc, file->d_name1);
    make_access3(file->f_stat.st_mode, &acc);
    if (0001000 & file->f_stat.st_mode && acc[9] == '-')
        acc[9] = 'T';
    else if (0001000 & file->f_stat.st_mode)
        acc[9] = 't';
    return acc;
}
