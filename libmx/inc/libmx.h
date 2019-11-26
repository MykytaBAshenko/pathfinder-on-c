#ifndef LIBMX_H
#define LIBMX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <malloc/malloc.h>

enum m_eror{
    INVALID_NUMBER,
    NOT_EXIST,
    EMPTY,
    LINE1_INVALID,
    LINE_INVALID,
    ISLANDS_INVALID
};

typedef struct graf_data {
    int size;
    int **matrix;
    int **dist;
    char **top;
    char **file; 
} tool;


typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;
 

void mx_printerr(const char *s);
void mx_print_error(enum m_eror errors, char *a, int i); 
void mx_printerr(const char *s);
bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);
bool mx_isalpha(int c);
bool mx_line_check(char *str, int line);
void mx_firstline_check(char *str);
char **mx_read_arguments(char **str, int size);
int **mx_create_matrix(char **islands, char **islands_tmp, int islands_int);
int **mx_crete_dist_matrix(int **matrix, int size);
int mx_arr_size(char **arr);
int **mx_create_zero_matrix(int islands);
int mx_count_short_ways(tool *d,int begin, int end);
void mx_del_intarr(int ***arr);
//
void mx_print_distance(tool *d, int *path, int i, int j);
int mx_count_short_ways(tool *d, int a, int b);
int mx_next_top(tool *data, int from, int to, int paths);
int mx_previos_top(tool *data, int from, int to);
char **mx_file_to_print(tool *d, int **path, int num);
void mx_checked(char *str, char *argv);

// Utils pack:
void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_printint(int n);
void mx_print_strarr(char **arr, const char *delim);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
void mx_print_unicode(wchar_t c);
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_nbr_to_hex(unsigned long nbr);
void mx_foreach(int *arr, int size, void (*f)(int));
char *mx_itoa(int number);
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);
int **mx_int_route(tool *d, int num, int from, int to);

// String pack:
int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_file_to_str(const char *file);
int mx_read_line(char **lineptr, int buf_size, char delim, const int fd);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);

// Memory pack:
void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);

// List pack:
t_list  *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));
void mx_clear_list(t_list **list);

#endif

