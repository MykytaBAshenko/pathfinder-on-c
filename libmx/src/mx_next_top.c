#include "libmx.h"

int mx_next_top(tool *data, int from, int to, int paths) {
    int weight;
    int temp;
    
    weight = data->dist[to][from];
    for (int i = paths; i < data->size; i++) {
        if (data->matrix[to][i] != 0 && data->matrix[to][i] != 999999999) {
            temp = weight - data->matrix[to][i];
            if (temp == data->dist[i][from])
                return i;
        }
    }
    return -2;
}
