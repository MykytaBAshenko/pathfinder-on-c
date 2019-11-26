#include "libmx.h"

char *mx_file_to_str(const char *file) {
    char buf[512];
    char test_buf[512];
    char *res;
    char *tmp;
    int n;
    int fd = open(file, O_RDONLY);
    if (fd < 0)
        return NULL;

    int test_read = read(fd, test_buf, sizeof (test_buf) - 1);
    if (test_read <= 0) 
        return mx_strnew(0);
    close(fd);
    fd = open(file, O_RDONLY);

    while ((n = read(fd, buf, sizeof (buf) - 1)) > 0) {
        buf[n] = '\0';
        tmp = res;
        res = mx_strjoin(res, buf);
        free(tmp);
    }
    close(fd);
    return res;
}

