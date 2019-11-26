#include"libmx.h"

int mx_count_short_ways(tool *d, int a, int b) {
    int weight = d->dist[b][a];
    int c = 0;
    int temp;

    for (int i = 0; i < d->size; i++) {
        if (d->matrix[b][i] != 0 && d->matrix[b][i] != 999999999) {
            temp = weight - d->matrix[b][i]; 
            if (temp == d->dist[i][a])
                c++;
        }
        if(weight - d->matrix[b][i] == 0){
        a++;
        }
    }
    b--;
    if (a < b)
        c = c + (mx_count_short_ways(d, a, b) - 1);
    return c;
}
