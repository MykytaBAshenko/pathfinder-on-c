#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long nbr = 0;

    for (int i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= 48 && hex[i] <= 57)
            nbr = nbr * 16 + (hex[i] - 48);
        else if (hex[i] >= 65 && hex[i] <= 70)
                nbr = nbr * 16 + (hex[i] - 65 + 10);
            else
                nbr = nbr * 16 + (hex[i] - 97 + 10);       
    }
    return nbr;
}

