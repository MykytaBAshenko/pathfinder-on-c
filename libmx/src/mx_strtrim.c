#include "libmx.h"

static bool space(char c) {
    if (c == '\t' || c == '\n' || c == '\v' 
    || c == '\f' || c == '\r' || c == ' ')
    return 1;
    else return 0;
}

char *mx_strtrim(const char *str) {
    if (!str) return NULL;

    int i = 0;
    int start = 0;
    int end = mx_strlen(str) - 1;

    for(; space(str[start]); start++);
    
    if (start == end + 1)
        return mx_strnew(0);

    for(; space(str[end]); end--);

    char *res = malloc(end - start + 2);

    for (; start != end + 1; i++, start++)
        res[i] = str[start];
    
    res[i] = '\0';
    return res;
}
