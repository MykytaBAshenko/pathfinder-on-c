#include "libmx.h"

static char *mx_trim_char(const char *str, char c) {
    if (!str) return NULL;

    int i = 0;
    int start = 0;
    int end = mx_strlen(str) - 1;

    for(; str[start] == c; start++);
    
    if (start == end + 1)
        return mx_strnew(0);

    for(; str[end] == c; end--);

    char *res = malloc(end - start + 2);

    for (; start != end + 1; i++, start++)
        res[i] = str[start];
    
    res[i] = '\0';
    return res;
}

char **mx_strsplit(const char *s, char c) {
    if (!s) return NULL;
    int words = mx_count_words(s, c);
    char **res = malloc((words + 1)*sizeof(char *));
    res[words] = NULL;
    int i = 0;
    int ptr = 0;
    char *word = (char *)s;
    char *tmp = NULL;
    
    while (words--) {
        word = mx_trim_char(word, c);
        tmp = word;
        ptr = mx_get_char_index(word, c);
        if (ptr == -1)
            res[i] = mx_strdup(word);
        else
            res[i] = mx_strndup(word, ptr);
        i++;
        word += ptr;
        free(tmp);
    }
    return res;
}
