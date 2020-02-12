#include "../inc/uls.h"

int mx_ret_num_len_lld(long long num, int count) {
    if (num == 0) {
        if (count == 0)
            return 1;
        return count;
    }
    return mx_ret_num_len_lld(num / 10, count + 1);
}
