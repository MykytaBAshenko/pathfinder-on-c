#include "libmx.h"

int mx_arr_size(char **arr) {
    int size = 0;

    while (arr[size]) {
        size++;
    }
    return size;
}
