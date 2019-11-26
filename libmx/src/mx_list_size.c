#include "libmx.h"

int mx_list_size(t_list *list) {
    if (!list) return 0;
    int count = 1;
    t_list *tmp = list;

    while (tmp->next != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
