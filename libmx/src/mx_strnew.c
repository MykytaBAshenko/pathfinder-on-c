#include "libmx.h"

char *mx_strnew(const int size) {
    if (size < 0) return NULL;
    char *new = malloc(size + 1);
    if (!new) return NULL;
    for (int i = 0; i <= size; i++)
        new[i] = '\0';
    return new;
} 
