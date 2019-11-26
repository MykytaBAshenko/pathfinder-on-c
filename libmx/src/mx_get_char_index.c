int mx_get_char_index(const char *str, char c) {
    if (!str) return -2;
    int res = 0;
    while (str[res] != '\0' && str[res] != c)
        res++;
    if (str[res] == c)
        return res;
    else return -1;
}
