#include "libmx.h"


int **mx_create_zero_matrix(int islands) {
     int max = 999999999;
    int **res = (int**) malloc(sizeof(int*) * islands);
    for(int i = 0; i < islands; i++) {
        res[i] = (int*) malloc(sizeof(int) * islands);
        for(int j = 0; j < islands; j++) {
            res[i][j] =  max;
        }
    }
    for(int i = 0; i < islands; i++)
        res[i][i] = 0;
    return res;
}

