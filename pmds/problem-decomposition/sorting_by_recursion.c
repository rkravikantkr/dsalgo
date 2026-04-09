#include <stdio.h>

void merge_sort(int *, int, int);

void merge_arr(int *, int, int);

void quick_sort(int *, int, int);

int main() {

    // int arr[] = {1, 2, 3, 4, 5, 6};
    int arr[] = {99, 3, 8, 7, 1, -1, -320, 0, -13};
    int size = sizeof(arr) / sizeof(arr[0]);
    // merge_sort(arr, 0, size - 1);
    quick_sort(arr, 0, size - 1);
    for (int l = 0; l <= size - 1; l++) {
        printf("%d ", arr[l]);
    }
}

int partition(int *arr, int left, int right) {
    int i = left, j = right, pivot = arr[left];
    int temp;
    while (i < j) {
        while ((i < j) && (arr[i] < pivot))
            i++;
        while ((i < j) && (arr[j] >= pivot))
            j--;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    if (arr[j] <= pivot)
        return j;
    else
        return j - 1;
}

void quick_sort(int *arr, int i, int j) {
    if (i >= j)
        return;
    int p = partition(arr, i, j);
    quick_sort(arr, i, p);
    quick_sort(arr, p + 1, j);
}

void merge_sort(int *arr, int i, int j) {
    // base condition
    // printf("entered with i= %d j= %d\n", i, j);
    if (i >= j)
        return;
    int m = (i + j) / 2;
    merge_sort(arr, i, m);
    merge_sort(arr, m + 1, j);
    merge_arr(arr, i, j);

    for (int k = i; k <= j; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}
void merge_arr(int *arr, int i, int j) {
    // temporary array to store sorted values
    int temp[j + 1]; // or dynamically allocate
    int m = (i + j) / 2;
    int t = i;

    int p = i;
    int q = m + 1;

    while (p <= m && q <= j) {
        if (arr[p] >= arr[q]) {
            temp[t++] = arr[q++];
        } else {
            temp[t++] = arr[p++];
        }
    }
    if (p > m) { // copy remaining from right of m
        while (q <= j)
            temp[t++] = arr[q++];
    } else if (q > j) { // copy remainig from left of m
        while (p <= m)
            temp[t++] = arr[p++];
    }
    // copy [i j] sorted portion back to array
    for (int k = i; k <= j; k++) {
        arr[k] = temp[k];
    }
}
