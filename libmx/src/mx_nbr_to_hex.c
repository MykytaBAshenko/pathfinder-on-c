#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *hex;
    int len = 1;

    for (unsigned long i = nbr; i / 16 != 0; i /= 16)
        len++;
    hex = malloc(len + 1);
    if (!hex) return NULL;
    hex[len] = '\0';
    
    for (unsigned long i = nbr; len != 0; i /= 16, len--) {
        if (i % 16 <= 9)
            hex[len - 1] =  i % 16 + '0';
        else
            hex[len - 1] =  i % 16 + 'a' - 10;
    }
    return hex;
}
