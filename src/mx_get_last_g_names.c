#include "../inc/uls.h"

bool mx_get_last_g_names(t_file_data *file, t_file_data **cur) {
    while (file && file->size_len != -1) {
        if ((*cur)->f_stat.st_gid == file->f_stat.st_gid) {
            if (file->gr_name != NULL)
                (*cur)->gr_name = mx_strdup(file->gr_name);
            (*cur)->g_len = file->g_len;
            return false;
        }
        file = file->next;
    }
    return true;
}
