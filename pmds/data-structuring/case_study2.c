#include <stdio.h>
/*

given a list of numbers find next maximum ie 2nd largest value
[ 8, 7, 15, 1, 6, 9, 4, 3 ]


*/
int next_max(int *A, int size);
void build_tournament_tree(int *A, int size);

int main() {
    int Arr[] = {1, 118, 25, 1, 6, 99, 4};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    printf("size: %d\n", size);
    // printf("next max: %d", next_max(Arr, size));
    build_tournament_tree(Arr, size);
}

void print_array(int *A, int size) {
    printf("[ ");
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", A[i]);
    }
    printf("%d ]\n", A[size - 1]);
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

void build_tournament_tree(int *A, int size) {
    // tournament array
    int t[2 * size - 1] = {};

    printf("tour size: %d\n", 2 * size - 1);

    // populate the tournament array
    for (int i = 1; i <= size; i++) {
        t[size + i - 2] = A[i - 1];
    }

    print_array(A, size);
    printf("initial tour: ");
    print_array(t, 2 * size - 1);

    // pairwise comparisons from right end to handle odd case as well
    for (int i = 2 * size - 2; i >= 1; i -= 2) {
        t[i / 2 - 1] = max(t[i - 1], t[i]);
        print_array(t, 2 * size - 1);
    }

    printf("maximum in tournament tree: %d", t[0]);
}

int next_max(int *A, int size) {
    int max, nmax;

    // pair wise comparison
    if (A[0] > A[1]) {
        max = A[0];
        nmax = A[1];

    } else {
        max = A[1];
        nmax = A[0];
    }

    for (int i = 1; i < size / 2; i++) {
        int big, small;
        if (A[2 * i] > A[2 * i + 1]) {
            big = A[2 * i];
            small = A[2 * i + 1];
        } else {
            big = A[2 * i + 1];
            small = A[2 * i];
        }
        if (big > max) {
            nmax = max;
            max = big;
        } else if (big > nmax) {
            nmax = big;
        }
        if (small > nmax) {
            nmax = small;
        }
    }
    if (size % 2 == 0) { // even number of elements
        return nmax;
    } else {
        // handle odd case, last element
        int last = A[size - 1];
        if (last > max) {
            nmax = max;
            max = last;
        } else if (last > nmax) {
            nmax = last;
        }
    }
    return nmax;
}
