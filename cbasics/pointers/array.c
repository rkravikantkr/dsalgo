#include <assert.h>
#include <stdio.h>
void pointer_to_array();
void arr_as_fnargs();

int main() {
    pointer_to_array();
    arr_as_fnargs();
}

void double_elements(int *A, int size) {
    for (int i = 0; i < size; i++) {
        // A[i] *= 2;
        *(A + i) *= 2;
    }
}

int sum_of_elements(int A[], int size) {
    // compiler converts int A[] to int* A
    // arrays are passed as referenced parameters
    // saves memory overload for larger array
    // number of elements is difficult to calculate using sizeof(A)/sizeof(A[0])
    //
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += A[i]; // A[i] == *(A+i)
    };
    return sum;
}

void arr_as_fnargs() {
    int A[100]; // = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < size; ++i) {
        A[i] = i + 1;
    }
    // name of array is pointer to first element
    assert(sum_of_elements(A, size) == 5050);
    double_elements(A, size);
    for (int i = 0; i < size; i++) {
        assert(A[i] == 2 * (i + 1));
    }
}

void pointer_to_array() {
    int arr[5] = {0, 1, 2, 3, 4};
    // printf("%p", arr);
    assert(sizeof(arr) == 20);
    // pointer to array, stores the address of first element of arr
    // name of array gives address of its first element
    int *ptArr = arr;
    assert(ptArr == arr);
    assert(ptArr == &arr[0]);

    for (int i = 0; i < 5; i++) {
        assert(ptArr + i == &arr[i] && "address of ith element must be same");
        assert(*(ptArr + i) == arr[i]);
    }
}
