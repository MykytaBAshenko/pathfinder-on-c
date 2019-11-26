#include "libmx.h"

char **mx_file_to_print(tool *d, int **path, int num) {
    char **nedlee;
    int i = 0;

    nedlee = malloc(sizeof(char *) * (d->size + 1));
    while(path[num][i] != -1)
        i++;
    for (int k = i - 1, c = 0; k >= 0; k--, c++)
        nedlee[c] = mx_strdup(d->top[path[num][k]]);

    return nedlee;
}
