#include "libmx.h"

void mx_firstline_check(char *str) {
    while (*str != '\0')
        if (mx_isdigit(*str))
            str++;
        else 
            mx_print_error(LINE1_INVALID, NULL, 1);
}
