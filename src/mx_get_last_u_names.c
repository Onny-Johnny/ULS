#include "../inc/uls.h"

bool mx_get_last_u_names(t_file_data *file, t_file_data **cur) {
    while (file && file->size_len != -1) {
        if ((*cur)->f_stat.st_uid == file->f_stat.st_uid) {
            if (file->pw_name != NULL)
                (*cur)->pw_name = mx_strdup(file->pw_name);
            (*cur)->usern_len = file->usern_len;
            return false;
        }
        file = file->next;
    }
    return true;
}
