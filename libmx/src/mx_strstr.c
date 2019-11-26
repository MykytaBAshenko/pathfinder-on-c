#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    char *begin = (char*) haystack;

    if (*needle == '\0')
        return (begin);
    
    while (*haystack != '\0') {
        begin = (char*) haystack;

        while (*needle == *haystack && *haystack != '\0') {
            ++haystack;
            ++needle;
        }
        if (*needle == '\0')
            return (begin);
        haystack = begin + 1;
    }
    return NULL;
}
