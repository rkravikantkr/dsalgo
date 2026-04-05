#include <stdio.h>
/*

given a list of numbers find next maximum ie 2nd largest value
[ 8, 7, 15, 1, 6, 9, 4, 3 ]


*/

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

    if (size % 2 == 0) {
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
        return nmax;

    } else {
        // ✅ handle odd case
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

int main() {
    int Arr[] = {118, 77, 25, 1, 6, 9, 4, 3};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    printf("next max: %d", next_max(Arr, size));
}
