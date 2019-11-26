#include "libmx.h"

static int  **mx_malloc_route(tool *d, int num);

int **mx_int_route(tool *d, int num, int from, int to) {
    int **paths = mx_malloc_route(d, num);
    int k = 1;
    for (int a = 0; a < num; a++) {
        int end = to;
        paths[a][k - 1] = to;
        while(end != from) {
            paths[a][k] = mx_previos_top(d, from, end);
            if (a > 0 && paths[a][k] == paths[a - 1][k]) {
                int tmp = mx_next_top(d, from, end, paths[a][k] + 1);
                if (tmp != -2)
                    paths[a][k] = tmp;
            }
            end = paths[a][k];
            k++;
        } 
        k = 1;
    }
    return paths;
}


static int  **mx_malloc_route(tool *d, int num){
    int **paths = malloc(num * sizeof(int *));
    for (int a = 0; a < num; a++) {
        paths[a] = malloc((d->size + 1) * sizeof(int)); 
        for (int k = 0; k < d->size + 1; k++)
            paths[a][k] = -1;
    }
    return paths;
}
