#include "libmx.h"



bool mx_line_check(char *str, int line) {
    while (*str != '-')
        if (mx_isalpha(*str))
            str++;
        else
            mx_print_error(LINE_INVALID, NULL, line);
    str++;
    while (*str != ',')
        if (mx_isalpha(*str))
            str++;
        else
            mx_print_error(LINE_INVALID, NULL, line);
    str++;
    while (*str != '\0')
        if (mx_isdigit(*str))
            str++;
        else 
            mx_print_error(LINE_INVALID, NULL, line);
    return true;
}


