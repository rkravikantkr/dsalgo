#include <assert.h>
#include <stdio.h>
void pointer_to_array();
int main() { pointer_to_array(); }

void pointer_to_array() {
    int arr[5] = {0, 1, 2, 3, 4};
    // printf("%p", arr);
    assert(sizeof(arr) == 20);
    // pointer to array, stores the address of first element of arr
    // name of array gives address of its first element
    int *ptArr = arr;
    assert(ptArr == arr);
    assert(ptArr == &arr[0]);
    assert(*ptArr + 1 == arr[1]);
    for (int i = 0; i < 5; i++) {
        assert(ptArr + i == &arr[i]);
        assert(*(ptArr + i) == arr[i]);
    }
}
