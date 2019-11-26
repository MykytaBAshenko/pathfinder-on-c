#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *ds = (unsigned char *)dst;
    unsigned char *sr = (unsigned char *)src;
    for(size_t i = 0; i < n; i++)
        ds[i] = sr[i];
    return dst;
}
