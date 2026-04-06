#include <limits.h>
#include <stdio.h>
void build_tournament_tree(int *, int);
void traverse_tree(int *, int);

void print_array(int *A, int size) {
    printf("[ ");
    for (int i = 0; i < size - 1; i++) {
        printf("%d ", A[i]);
    }
    printf("%d ]\n", A[size - 1]);
}
int main() {
    int arr[] = {8, 3, 4, 6, 9, 11, 98, 43, 10, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    build_tournament_tree(arr, size);
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

void traverse_tree(int *t, int tsize) {
    printf("print the list in sorted order: ");
    // traversing the tournament tree
    int LOW = INT_MIN;
    int i = 1; // i represents location or position

    while (t[i - 1] != LOW) { // first element becomes the LOW
        printf("%d ", t[0]);
        i = 2 * i; // double the location, moves down to next level

        while (i < tsize) { // break loop at last level
            if (t[i - 1] > t[i + 1 - 1]) {
                t[i - 1] = LOW;
                i = 2 * i;
            } else {
                t[i + 1 - 1] = LOW;
                i = 2 * (i + 1);
            }
        }
        // relocate i at last level
        i = i / 2;

        while (i != 1) {
            // at even postion number
            if (i % 2 == 0) {
                if (t[i - 1] > t[i + 1 - 1]) {
                    t[i / 2 - 1] = t[i - 1];
                    i = i / 2;
                } else {
                    t[i / 2 - 1] = t[i + 1 - 1];
                    i = i / 2;
                }

            } else { // odd position number
                if (t[i - 1] > t[i - 1 - 1]) {
                    t[i / 2 - 1] = t[i - 1];
                    i = i / 2;
                } else {
                    t[i / 2 - 1] = t[i - 1 - 1];
                    i = i / 2;
                }
            }
        }
    }
}

void build_tournament_tree(int *A, int size) {
    // tournament array size
    int t_size = 2 * size - 1;
    int t[t_size] = {};

    // populate the initial tournament array from given array
    for (int i = 0; i < size; i++) {
        t[size - 1 + i] = A[i];
    }
    // pairwise comparisons from right end to handle along
    for (int i = t_size; i >= 1; i -= 2) {
        t[i / 2 - 1] = max(t[i - 1], t[i - 2]);
    }

    printf("tournament tree structure: ");
    print_array(t, t_size);
    traverse_tree(t, t_size);
}
