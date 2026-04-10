#include <stdio.h>

void merge_sort(int *, int, int);

void merge_arr(int *, int, int);

void quick_sort(int *, int, int);

int main() {

    // int arr[] = {1, 2, 3, 4, 5, 6};
    int arr[] = {8, 7, 6, 5, 4, 3, 3, 3, 1, 2, 4, 6, 7, -9};
    int size = sizeof(arr) / sizeof(arr[0]);
    // merge_sort(arr, 0, size - 1);
    quick_sort(arr, 0, size - 1);
    printf("\nsorted array\n");
    for (int l = 0; l <= size - 1; l++) {
        printf("%d ", arr[l]);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int make_partition(int *arr, int low, int high) {

    printf("before partitioning\n");
    for (int i = 0; i <= high; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int i = low - 1; // i tracks elements < pivot position
    int pivot = arr[high];

    for (int t = low; t < high; t++) {
        if (arr[t] < pivot) {
            swap(&arr[++i], &arr[t]);
        }
    }
    swap(&arr[++i], &arr[high]);

    printf("after partitioning\n");
    for (int i = 0; i <= high; i++) {
        printf("%d ", arr[i]);
    }
    printf("\npartitioning index: %d", i);
    printf("\n");
    printf("\n");

    return i;
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
        for (int l = 0; l <= j; l++) {
            printf("%d ", arr[l]);
        }

        printf("\ni: %d - j: %d\n", i, j);
    }
    if (arr[j] <= pivot) {
        // printf("curr pivot index: %d, value: %d\n", j, pivot);
        return j;
    } else {
        // printf("curr pivot index: %d, value: %d\n", j - 1, pivot);
        return j - 1;
    }
}

void quick_sort(int *arr, int i, int j) {
    printf("qsort with i:%d, j:%d\n", i, j);
    if (i >= j)
        return;
    // int p = partition(arr, i, j);
    // quick_sort(arr, i, p);
    // quick_sort(arr, p + 1, j);

    int p = make_partition(arr, i, j);
    quick_sort(arr, i, p - 1);
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
