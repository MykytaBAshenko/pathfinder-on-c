#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    if (!s) return NULL;
    s = (unsigned char *)s + n;
    size_t i = 0;
    
    while (*((unsigned char *)s) != c && i < n) {
        s = (unsigned char *)s - 1;
        n--;
    }
    
    if (*((unsigned char *)s) == c)
        return (unsigned char *)s;
    else return NULL;
}
