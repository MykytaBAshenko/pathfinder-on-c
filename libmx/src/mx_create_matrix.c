#include "libmx.h"

// os == islands

static int mx_get_num_str(char *island_tmp);
static int mx_geti(int line, int os_int, char **os, char **os_tmp);

int **mx_create_matrix(char **os, char **os_tmp, int os_int) {
    int **matrix = mx_create_zero_matrix(os_int);

    for (int line = 1; os_tmp[line] != NULL; line++) {
        int j = 0 ;
        int i;

        i = mx_geti(line, os_int, os, os_tmp);
        char *word2 = mx_memchr(os_tmp[line], '-', mx_strlen(os_tmp[line]));
        while (j < os_int) {
            if (mx_memcmp(word2 + 1, os[j], mx_strlen(os[j])) == 0)
                break;
            j++;
        }
        matrix[i][j] = mx_get_num_str(os_tmp[line]);
        matrix[j][i] = matrix[i][j];
    }
    return matrix;
}

static int mx_geti(int line, int os_int, char **os, char **os_tmp){
    int i = 0;

    while (i < os_int) {
        if (mx_memcmp(os_tmp[line], os[i], mx_strlen(os[i])) == 0)
            break;
        i++;
        }

    return i;
}

static int mx_get_num_str(char *island_tmp) {
    int ind = mx_get_char_index(island_tmp, ',') + 1;
    return mx_atoi(&island_tmp[ind]);
}
