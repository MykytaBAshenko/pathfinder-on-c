#include "libmx.h"

void mx_printint(int n) {
    int tens = 1;
    int flag = 1;

    if (n < 0) {
        flag = -1;
        mx_printchar('-');
    }
    for (int i = n; i / 10 != 0; i /= 10)
        tens *= 10;
    for (int i = n; tens != 0; i %= tens, tens /= 10)
        mx_printchar(i / tens * flag + '0');
}
