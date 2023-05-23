#include "push_swap.h"

void quickSort(int *data, int start, int end) {
    if(start<end) {
        int pivot = getPivot(data, start, end);
        quickSort(data, start, pivot-1);
        quickSort(data, pivot+1, end);
    }
}
int getPivot(int *data, int start, int end) {
    int i = start -1, j, pivot = data[end], tmp;
    for(j = start; j<end; j++) {
        if(data[j] <= pivot) {
            tmp = data[++i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
    tmp = data[i+1];
    data[i+1] = data[end];
    data[end] = tmp;
    return i+1;
}
