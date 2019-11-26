#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    int shifts = 0;
    if (arr == NULL || *arr == NULL) return -1;
    if(left < right) {
        int low = left;
        int high = right;
        char *pivot = arr[low + ((high - low) / 2)];

        while(low <= high) {
            while(mx_strlen(arr[low]) < mx_strlen(pivot)) low++;
            while(mx_strlen(arr[high]) > mx_strlen(pivot)) high--;
            if(low <= high) {
                if(arr[low] != arr[high] && mx_strlen(arr[low]) != mx_strlen(arr[high])) shifts++;
                char *tmp = arr[low];
                arr[low] = arr[high];
                arr[high] = tmp;
                low++;
                high--;
            }
        }
        shifts += mx_quicksort(arr, left, high);
        shifts += mx_quicksort(arr, low, right);
    }
    return shifts;
}
