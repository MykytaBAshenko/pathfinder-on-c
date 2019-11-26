#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    int subs = mx_count_substr(str, sub);
    int sub_one = mx_strlen(sub);
    int subs_length = sub_one * subs;
    int replace_length = mx_strlen(replace) * subs;
    int str_length = mx_strlen(str) - subs_length;
    int index = 0;
    char *result = mx_strnew(str_length + replace_length);
    char *tmp = NULL;

    while (subs--) {
        index = mx_get_substr_index(str, sub); 
        tmp = mx_strndup(str, index);
        mx_strcat(result, tmp);
        mx_strcat(result, replace);
        str += index + sub_one;
        free(tmp);
    }
    mx_strcat(result, str);
    return result;
}
