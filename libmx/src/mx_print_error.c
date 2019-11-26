#include "libmx.h"

static void mx_othererr(enum m_eror errors, int i);

void mx_print_error(enum m_eror errors, char *a, int i) {
    if (errors == INVALID_NUMBER) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    } else if (errors == NOT_EXIST) {
        mx_printerr("error: file ");
        mx_printerr(a);
        mx_printerr(" does not exist\n");
        exit(1);
    } else if (errors == EMPTY) {
        mx_printerr("error: file ");
        mx_printerr(a);
        mx_printerr(" is empty\n");
        exit(1);
    } else 
        mx_othererr(errors,i);
    exit(1);
}

static void mx_othererr(enum m_eror errors, int i){
    if (errors == LINE1_INVALID) {
            mx_printerr("error: line 1 isn't valid\n");
            exit(1);
    } else if (errors == LINE_INVALID) {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(i + 1));
        mx_printerr(" isn't valid\n");
        exit(1);
    } else if (errors == ISLANDS_INVALID)
        mx_printerr("error: invalid number of islands\n");
}

