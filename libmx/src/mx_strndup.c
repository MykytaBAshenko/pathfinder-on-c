#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    unsigned long len = mx_strlen(s1);
    
    if (len > n)
        len = n;
    return mx_strncpy(mx_strnew(len), s1, len);
}
