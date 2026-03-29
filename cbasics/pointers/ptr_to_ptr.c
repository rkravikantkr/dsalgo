#include <assert.h>
#include <stdio.h>
/*
 * pointer is also stored in 4bytes
 *
 *
 * */

void pointer_to_pointer() {
    int x = 5;
    int *ptx = &x;
    assert(*ptx + 5 == x + 5);

    // store add of a pointer; pointer to a pointer.
    int **q = &ptx;

    // r stores address of q
    int ***r = &q; // pointer to pointer to a pointer
    // printf("address of q: %p\n", &q);
    // printf("value stored at q: %p\n", q);
    // printf("dereferencing r: %p\n", *r);
    assert(*r == q && "deref r contains value stored in q");
    assert(*q == ptx && "deref q contains value stored in ptx");
    assert(*(*(*r)) == 5);
}

int main() { pointer_to_pointer(); }
