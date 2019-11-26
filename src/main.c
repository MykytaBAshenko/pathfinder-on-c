#include "libmx.h"

static tool *mx_inicialize(int s, int **m, int **d, char **t);
static void mx_final_print(tool *d);
static void mx_printpath(tool *d, int *path, int i, int j);

int main(int n, char **argv) {
    if (n != 2) 
        mx_print_error(INVALID_NUMBER, NULL, 0);
    char *file_str = mx_file_to_str(argv[1]);
    mx_checked(file_str, argv[1]);
    char **islands_arr = mx_strsplit(file_str, '\n');
    mx_firstline_check(islands_arr[0]);
    int size = mx_atoi(islands_arr[0]);
    char **islands = mx_read_arguments(islands_arr, size);
    int **matrix = mx_create_matrix(islands, islands_arr, size);
    int **min_dist = mx_crete_dist_matrix(matrix, size);
    tool *d = mx_inicialize(size, matrix, min_dist, islands);
    mx_final_print(d);
    free(d);
    return 0;
}

static void mx_final_print(tool *d) {
    int num;
    int **path;
    
    for (int i = 0; i < d->size; i++){
        for (int j = i + 1; j < d->size; j++) {
            num = mx_count_short_ways(d, i, j);
            path = mx_int_route(d, num, i, j);
            for (int c = 0; c < num; c++) {
                d->file = mx_file_to_print(d, path, c);
                mx_printpath(d, path[c], i, j);
                mx_del_strarr(&d->file);
            }
        }
    }       
}


static void mx_printpath(tool *d, int *path, int i, int j) {
    mx_printstr("========================");
    mx_printstr("================\nPath: ");
    mx_printstr(d->top[i]);
    mx_printstr(" -> ");
    mx_printstr(d->top[j]);
    mx_printstr("\nRoute: ");
    mx_print_strarr(d->file, " -> ");
    mx_printstr("Distance: ");
    if(mx_arr_size(d->file) == 2)
        mx_printint(d->dist[i][j]);
    else 
        mx_print_distance(d, path, i, j);
    mx_printstr("\n====================");
    mx_printstr("====================\n");
}

static tool *mx_inicialize(int s, int **m, int **d, char **t) {
    tool *data= malloc(sizeof(tool));
    data->size = s;
    data->matrix = m;
    data->dist = d;
    data->top = t;
    return data;
}
