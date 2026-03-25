#include <assert.h>
#include <stdio.h>
/*
 * pointers as function arguments - call by reference
 *
 *
 * */

void increment_copy(int a);
void increment_ref(int *a);
int main() {
    int x = 10;

    // copy of x is passed to funtion arguments
    increment_copy(x);
    assert(x == 10);

    increment_ref(&x);
    assert(x == 11);
}
// call by value
void increment_copy(int a) {
    // a is local to this function
    a += 1;
}
// call by reference
void increment_ref(int *a) {
    // recieves address of variable passed into
    *a += 1;
}
