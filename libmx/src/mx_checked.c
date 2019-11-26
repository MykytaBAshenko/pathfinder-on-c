#include "libmx.h"

void mx_checked(char *str, char *file) {
	if (str == NULL)
        mx_print_error(NOT_EXIST, file, 0);
    if (mx_strlen(str) == 0)
        mx_print_error(EMPTY, file, 0);
}
