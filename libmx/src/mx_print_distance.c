#include "libmx.h"

void mx_print_distance(tool *d, int *path, int i, int j) {
    int k = 0;

    while(path[k] != -1)
            k++;
    for (int a = 0; a <= k; a++, k--) {
        mx_printint(d->matrix[path[k - 1]][path[k - 2]]);
        if (a < k - 1)
            mx_printstr(" + ");
    }
    mx_printstr(" = ");
    mx_printint(d->dist[i][j]);
}
