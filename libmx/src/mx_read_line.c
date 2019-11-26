#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    static char *remainder = NULL;
    char buf[buf_size + 1];
    int bytes = 0;
    int delim_index = -1;
    char *tmp_s = NULL;
    char *tmp = NULL;
    if (remainder)
        tmp_s = mx_strdup(remainder);

    while ((bytes = read(fd, buf, buf_size)) >= 0) {
        buf[bytes] = '\0';
        tmp = mx_strjoin(tmp_s, buf);
        mx_strdel(&tmp_s);
        tmp_s = mx_strdup(tmp);
        mx_strdel(&tmp);
        delim_index = mx_get_char_index(tmp_s, delim);
        if (delim_index != -1) {
            tmp_s[delim_index] = '\0';
            if (remainder) {
                mx_strdel(&remainder);
            }
            remainder = mx_strdup(tmp_s + delim_index + 1);
            break;
        }
        if (bytes == 0) {
            if (remainder) {
                mx_strdel(&remainder);
            }
            break;
        }
    }
    if (bytes == -1) {
        return -1;
    }
    *lineptr = mx_strdup(tmp_s);
    mx_strdel(&tmp_s);
    return mx_strlen(*lineptr);
}
