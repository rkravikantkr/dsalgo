#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
/*
 * bytes allocation based on data type
 * int - 4 bytes
 * char - 1 bytes
 * float - 4 bytes
 * double - 8 bytes
 *
 *
 * pointer - variable that stores address of another variable, type dependent
 * int a ; // declare a variable a somewhere in memory
 * int *p = &a;  // p is a pointer to integer; it stores address of a integer
 * variable; &a gets address of a *p ; // dereferencing the pointer variable,
 * gives value at address of a.
 *
 * char c = 'A';
 * char *ptc = &c;
 *
 */

void pointerfn() {
    // binary representation of 1025 stored in a
    int a = 1025; //[[00000000][00000000][00000100][00000001]]

    int *p;
    p = &a;

    assert(p == &a);

    // *p dereferancing pointer, getting the value stored at that address.
    assert(*p == a); //  value stored at address of a, which is stored in p.

    // making changes to value stored in a via a pointer to it.
    assert(*p + 10 == a + 10);

    // printf("address of pointer to integer : %p\n", &p);

    assert(sizeof(int) == 4 && "integer type has 4 bytes");

    // printf("address of p+1: %p\n", p + 1);

    char *pc;
    pc = (char *)p; // typecasting pointer to integer to pointer to character.
    assert(*pc == 1 && "dereferencing pointer to char reads only 1 byte");
    // assert(*pc + 1 == 4 && "dereferencing pointer to char reads only 1
    // byte");

    printf("%" PRIuPTR, (uintptr_t)p);

    printf("\n");
    printf("%" PRIuPTR, (uintptr_t)p + 1);

    printf("\n");
    printf("%" PRIuPTR, (uintptr_t)pc);
    printf("\n");
    printf("%" PRIuPTR, (uintptr_t)pc + 1);
}
int main(void) { pointerfn(); }
