#include "libmx.h" 

int mx_atoi(const char *str) {
    int i = 0;
    int n = 0;
    int sign = 1;

    while (mx_isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (mx_isdigit(str[i])) { 
        n = n * 10 + (str[i] - 48) * sign;
        i++;
    }
    return n;
}
