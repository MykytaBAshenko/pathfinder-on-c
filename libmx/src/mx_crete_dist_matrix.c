#include "libmx.h"



int **mx_crete_dist_matrix(int **matrix, int size) {
    int max = 999999999;
    int **dist = mx_create_zero_matrix(size);
    
    for (int i = 0; i < size; i++) 
        for (int j = 0; j < size; j++)
            dist[i][j] = matrix[i][j];
            
    for (int k = 0; k < size; k++) { 
        for (int i = 0; i < size; i++) { 
            for (int j = 0; j < size; j++)
                if (dist[i][k] < max 
                && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
        } 
    }
    
    return dist;
}



