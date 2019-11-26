#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big_len - little_len < 0 || !big_len || !little_len ||
     !big || !little) return NULL;

    size_t len_big = big_len;

    if (little_len > 1) {
        while (len_big > 0) {
            if (*((unsigned char *)big) == *((unsigned char *)little)){
                if(mx_memcmp(big, little, little_len) == 0)
                    return (unsigned char *)big;
            }
            big = (unsigned char *)big + 1;
            len_big--;
        }
    } else return mx_memchr(big, *((unsigned char *)little), big_len);
    return NULL;
}
