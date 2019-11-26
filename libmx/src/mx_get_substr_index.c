#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if(str == NULL || sub == NULL)
        return -2;
    int n = 0;
    int flag = 0;
    int len_str = mx_strlen(str);
    int len_sub = mx_strlen(sub);

    for(int i = 0; i < len_str; i++) {
        n = i;
        for(int j = 0; j < len_sub; j++) {
            if(str[n] == sub[j])
                flag++;
            n++;
        }
    if(flag == len_sub)
        return i;
    flag = 0;
    }
    return -1;
}
