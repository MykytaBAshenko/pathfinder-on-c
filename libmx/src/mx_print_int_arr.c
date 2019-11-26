#include "libmx.h"

void mx_print_int_arr(int *arr, char *delim, int size) {
	for(int i = 0; arr[i] < size; i++) {
		mx_printint(arr[i]);
		mx_printstr(delim);
	}
}
