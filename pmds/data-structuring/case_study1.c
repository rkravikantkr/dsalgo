#include <stdio.h> /* given n integers find maximum and minimum among them
 */
void max_min_value(int *A, int size);
void max_min_value_(int *A, int size);
void swap(int *i, int *j);
int maxi(int arr[], int max, int index);
int mini(int arr[], int min, int index);

void example_code() {

    int n, m, max, min, i, num1, num2;
    int large[100], small[100], index1 = 1, index2 = 1;

    /* Read N */
    printf("Given n:");
    scanf("%d", &n);
    printf("\n n = %d \n", n);

    // Initialize Max and Min
    scanf("%d", &max);
    min = max;

    // m tracks remainig numbers
    m = n - 1;

    /*
        If n is even → handle first 2 numbers
        If n is odd → handle first 1 number
        Then process the rest in pairs
    */

    // Even number of integers
    if (n % 2 == 0) {
        // read one more number, to pair up, since one number is already read
        scanf("%d", &min);
        if (max < min)
            swap(&max, &min);
        // m tracks remainig numbers
        // now two less number
        m = m - 1;
    }

    /* Fill large and small array */
    for (i = 1; i <= m / 2; i++) {
        scanf("%d%d", &num1, &num2);
        if (num1 >= num2) {
            large[index1] = num1;
            index1++;
            small[index2] = num2;
            index2++;
        } else {
            large[index1++] = num2;
            small[index2++] = num1;
        }
    }

    // Print result
    printf("\n MAX = %d, MIN = %d \n", maxi(large, max, index1),
           mini(small, min, index2));
}
int main(void) {

    int arr[] = {8, -111, 2, 19, 0, -4, 2, 5, 4, 7, 15};
    int asize = sizeof(arr) / sizeof(arr[0]);

    int brr[] = {-1, 0, 8, 4, 5, 6, 3, 5, 6, 9};
    int bsize = sizeof(brr) / sizeof(brr[0]);

    max_min_value_(arr, asize);
    max_min_value(arr, asize);
    printf("\n\n");
    max_min_value_(brr, bsize);
    max_min_value(brr, bsize);

    // example_code();
}
void max_min_value_(int *A, int size) {
    int max, min;

    if (A[0] > A[1]) {
        max = A[0];
        min = A[1];

    } else {
        max = A[1];
        min = A[0];
    }

    for (int i = 1; i < size / 2; ++i) {
        if (A[2 * i] > A[2 * i + 1]) {
            if (A[2 * i] > max)
                max = A[2 * i];

            if (A[2 * i + 1] < min)
                min = A[2 * i + 1];

        } else {
            if (A[2 * i + 1] > max)
                max = A[2 * i + 1];

            if (A[2 * i] < min)
                min = A[2 * i];
        }
    }

    if (size % 2 == 0) {
        printf("max: %d, min: %d\n", max, min);

    } else { // ✅ handle odd case
        int last = A[size - 1];

        if (last > max) {
            max = last;
        } else if (last < min) {
            min = last;
        }
        printf("max: %d, min: %d\n", max, min);
    }
}

void max_min_value(int *A, int size) {
    int max = 0;
    int min = 0;

    if (size % 2 == 0) {
        // find max and min in pair wise comparison
        int m = size / 2;
        for (int i = 0; i < m; ++i) {
            //
            // i => A[2i] , A[2i+1]
            if (A[2 * i] > A[2 * i + 1]) {
                if (A[2 * i] > max)
                    max = A[2 * i];

                if (A[2 * i + 1] < min)
                    min = A[2 * i + 1];

            } else {
                if (A[2 * i + 1] > max)
                    max = A[2 * i + 1];

                if (A[2 * i] < min)
                    min = A[2 * i];
            }
        }
        printf("max: %d, min: %d\n", max, min);
    }
    if (size % 2 != 0) {
        // find max and min in pairwise, ignore the last element
        // make one final comparision with max, min and last_element

        int m = (size - 1) / 2; // since given size is odd
        for (int i = 0; i < m; ++i) {
            if (A[2 * i] > A[2 * i + 1]) {
                if (A[2 * i] > max)
                    max = A[2 * i];

                if (A[2 * i + 1] < min)
                    min = A[2 * i + 1];

            } else {
                if (A[2 * i + 1] > max)
                    max = A[2 * i + 1];

                if (A[2 * i] < min)
                    min = A[2 * i];
            }
        }
        if (A[size - 1] > max)
            max = A[size - 1];
        else if (A[size - 1] < min)
            min = A[size - 1];
        printf("max: %d, min: %d\n", max, min);
    }
}

void swap(int *i, int *j) {
    int tem = *i;
    *i = *j;
    *j = tem;
}

int maxi(int arr[], int max, int index) {
    int i;
    for (i = 1; i < index; i++)
        if (max < arr[i])
            max = arr[i];
    return max;
}

int mini(int arr[], int min, int index) {
    int i;
    for (i = 1; i < index; i++)
        if (min > arr[i])
            min = arr[i];
    return min;
}
