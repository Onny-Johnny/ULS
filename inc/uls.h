#ifndef ULS_H
#define ULS_H

#include <unistd.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/termios.h>
#include <sys/ioctl.h>
#include <stddef.h>
#include <dirent.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <grp.h>
#include <time.h>
#include <sys/errno.h>

#define MX_RESET   "\033[0m"
#define MX_BLUE    "\033[0;34m"
#define MX_PURPLE  "\033[0;35m"
#define MX_GREEN   "\033[2;32m"
#define MX_BRRED   "\033[2;31m"
#define MX_RED     "\033[0;31m"
#define MX_BBLUE   "\033[34;46m"
#define MX_BBRRED  "\033[34;43m"
#define MX_BRED    "\033[7;31m"
#define MX_BBBLUE  "\033[30;46m"
#define MX_BGREEN  "\033[30;42m"
#define MX_BBBRRED "\033[30;41m"

typedef struct s_file_data {
    char *d_name;
    char *d_name1;
    int d_len;
    int usern_len;
    int hard_l_len;
    int g_len;
    int size_len;
    char *gr_name;
    char *pw_name;
    struct stat f_stat;
    struct s_file_data *next;
} t_file_data;

typedef struct s_flag_c {
    struct winsize win;
    int max_d_len;
    int col_len;
    int name_num;
    int row;
    int space;
    char **d_names;
    int *n_sizes;
    int cols;
    int *mode;
} t_flag_c;

typedef struct s_root {
    char *root_name;
    char *root_name1;
    t_file_data *files;
    int rn;
    struct stat r_stat;
    struct s_root *next;
} t_root;

typedef struct s_uls {
    int *flags;
    int flags_num;
    int r_s;
    int root_num;
    char **root;
} t_uls;

typedef struct s_flagl_limits {
    int usern_len;
    int hard_l_len;
    int g_len;
    int size_len;
    bool cb;
} t_flagl_limits;

typedef struct s_flag_l {
    char *access;
    char *hard_links;
    char *user_name;
    char *group_name;
    char *size;
    char *time;
} t_flag_l;

typedef struct s_dich {
    char *dich_name;
    struct s_dich *next;
} t_dich;

int mx_strlen(const char *s);
void mx_printchar(char c);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);
void mx_strdel(char **str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);
char *mx_strcat(char *restrict s1, const char *restrict s2);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
double mx_pow(double n, unsigned int pow);
char *mx_nbr_to_hex(unsigned long nbr);
void mx_del_strarr(char ***arr);
void mx_printint(int n);
void mx_clean_uls(t_uls **uls);
char *mx_parse_flags(int argc, char **argv, t_uls **uls);
int *mx_get_sorted_flags(int argc, char **argv, t_uls **uls);
void mx_printerr(char *s);
void mx_p_err_flag(char c);
t_uls *mx_get_uls(int argc, char **argv);
bool mx_is_no_our_flags(char *flags);
void mx_printerr_char(char c);
char **mx_get_root(t_uls **uls, int argc, char **argv);
char *mx_del_flag_dubl(char **flags, t_uls **uls);
char *mx_ret_clean_flag(char *flags, t_uls **uls, char *ret);
char *mx_filter_flags(char **flags, t_uls **uls);
void mx_del_dich_flags(char **flagss, int num, char c);
t_root *mx_take_root(t_uls *uls, char *push, int *root_num);
void mx_push_root(t_root **ro, char *root_name, struct stat s, char *origr);
void mx_clean_root(t_root **root);
int *mx_flags_to_int(char **flags);
void mx_push_file(t_file_data **fl, struct dirent *d, struct stat s, char *str);
void mx_clean_file(t_file_data **file);
t_file_data *mx_get_files(t_root **r, int *flags);
void mx_printend(t_file_data **file, int *flags);
void mx_print_l(t_file_data **file, int *flags);
int mx_ret_num_len_lld(long long num, int count);
int mx_ret_num_len(int num, int count);
t_flagl_limits *mx_get_limits(t_file_data **file, int *flags);
char *mx_get_access(t_file_data *file);
t_flag_l *mx_get_flag_l(t_flagl_limits *lim, t_file_data *file, int *flags);
void mx_flag_l_clean(t_flag_l **fl_l);
char *mx_num_to_str(int num, int size);
char *mx_get_hard_links(t_file_data *file, t_flagl_limits *lim);
char *mx_get_user_name(t_file_data *file, t_flagl_limits *lim);
char *mx_get_g_name(t_file_data *file, t_flagl_limits *lim);
char *mx_lld_num_to_str(long long num, int size);
char *mx_get_size(t_file_data *file, t_flagl_limits *lim);
char *mx_get_time(time_t ti);
void mx_print_total(t_file_data *file);
void mx_print_link(t_file_data *file);
char *mx_get_min_maj(dev_t r_dev, int size);
void mx_push_dich(t_dich **tr, char *dich_name);
void mx_clean_dich(t_dich **dich);
void mx_print_dich(t_dich **t, int *flags);
void mx_p_l(t_file_data **file, int *flags, int root_num);
void mx_push_file_light(t_file_data **list, struct stat s, char *s1, char *s2);
void mx_print_dich_inputs(t_uls *uls, t_file_data *files, int root_num, int *rn);
void mx_print_l_light(t_file_data **file, int *flags);
bool mx_get_last_u_names(t_file_data *file, t_file_data **cur);
bool mx_get_last_g_names(t_file_data *file, t_file_data **cur);
t_file_data *mx_get_files1(t_root *r, int *flags);
void mx_push_file1(t_file_data **fl, struct dirent *dirent);
void mx_print_c(t_file_data *file, int *flags);
void mx_print_one(t_file_data *file, int *flags);
void mx_print_space(t_flag_c *flag_C, int i, int j);
char *mx_get_time_big(time_t ti);
void mx_print_ex_atr(char *name, int size);
void mx_split_f_b(t_file_data *head, t_file_data **f_ref, t_file_data **b_ref);
void mx_merge_sort(t_file_data **file);
void mx_merge_sort_size(t_file_data **file);
void mx_merge_sort_status(t_file_data **file);
void mx_merge_sort_last_acc(t_file_data **file);
void mx_merge_sort_modification(t_file_data **file);
void mx_print_x(t_file_data *file, int *flags);
void mx_merge_sort_r(t_file_data **file);
void mx_merge_sort_size_r(t_file_data **file);
void mx_merge_sort_status_r(t_file_data **file);
void mx_merge_sort_last_acc_r(t_file_data **file);
void mx_merge_sort_modification_r(t_file_data **file);
void mx_split_f_b_root(t_root *head, t_root **f_ref, t_root **b_ref);
void mx_merge_sort_root(t_root **r);
void mx_merge_sort_size_root(t_root **r);
void mx_merge_sort_status_root(t_root **r);
void mx_merge_sort_last_acc_root(t_root **r);
void mx_merge_sort_modification_root(t_root **r);
void mx_merge_sort_r_root(t_root **r);
void mx_merge_sort_size_r_root(t_root **r);
void mx_merge_sort_status_r_root(t_root **r);
void mx_merge_sort_last_acc_r_root(t_root **r);
void mx_merge_sort_modification_r_root(t_root **r);
void mx_print_space_x(t_flag_c *flag_C, int j, int i);
void mx_file_reverse(t_file_data **head_ref);
void mx_root_reverse(t_root **head_ref);
t_flagl_limits *mx_get_limits1(t_file_data **file, int *flags);
void mx_print_main_nl(t_root *r, int *flags, t_file_data *fl);
void mx_main_rec(char *dir, int *flags, char *name);
t_file_data *mx_get_files_rec(char *dir, int *flags, char *name, char *str);
void mx_print_main_nl_rec(t_file_data *fl, int *flags);
char *mx_get_h(off_t sz);
int mx_get_h_pow(off_t sz);
void mx_add_h(char *size, off_t sz);
void mx_print_col(char *name, char *acs);
void mx_print_c_col(t_file_data *file, int *flags);
void mx_print_x_col(t_file_data *file, char *acs);
char *mx_get_access_col(mode_t mode);
void mx_print_space_x_col(t_flag_c *flag_c, int j, int i);
void mx_print_space_col(t_flag_c *flag_c, int i, int j);

#endif
