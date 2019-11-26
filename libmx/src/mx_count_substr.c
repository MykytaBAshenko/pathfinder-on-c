#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    if (!str || !sub)
        return -1;
    int s = mx_strlen(sub);
    int len = mx_strlen(str) / s;
    
    for (int i = 0; i < len; i++) {
        if (mx_strstr(str, sub)) {
            count++;
            str = mx_strstr(str, sub) + s;
        }
    }
    return count;
}
