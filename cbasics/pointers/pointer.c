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
 * pointer - variable that stores address of another variable, type dependent
 * int a ; // declare a variable a somewhere in memory
 * int *p = &a;  // p is a pointer to integer; it stores address of a integer
 * variable; &a gets address of a *p ; // dereferencing the pointer variable,
 * gives value at address of a.
 *
 * char c = 'A';
 * char *ptc = &c;
 *
 * memory is addressed byte wise.
 */
void pointerfn();
void void_pointerfn();

int main(void) { pointerfn(); }

void void_pointerfn() { // generic pointer type
    void *pvoid;
    // no arithmetic operations
    // prints nothing
    // implicit typecasting
    //

    int a = 1025;
    pvoid = &a; // explicit type casting is not required
    // assert(*pvoid == 1025 && "generic pointer type can't be dereferenced");
    printf("pvoid: %p", pvoid); // prints nothing !!
    assert(pvoid == NULL);
}

void pointerfn() {
    // binary representation of 1025 stored in a
    int a = 1025; //[[00000000][00000000][00000100][00000001]]

    int *p;
    p = &a;

    assert(p == &a);

    // *p dereferancing pointer, getting the value stored at that address.
    assert(*p == a); //  value stored at address of a, which is stored in p.
    //
    // printf("%" PRIuPTR, (uintptr_t)p);
    // printf("\n");
    // printf("%" PRIuPTR, (uintptr_t)p + 1); // arithmetic moves in 4 byte step
    // printf("\n");
    //
    // making changes to value stored in a via a pointer to it.
    assert(*p + 10 == a + 10);
    // printf("value at p address: %d\n", *p);
    // printf("value at p+1 address: %d\n", *(p + 1)); // garbage value
    // printf("address of pointer to integer : %p\n", &p);
    //
    assert(sizeof(int) == 4 && "integer type has 4 bytes");

    // printf("address of p+1: %p\n", p + 1);

    char *pc;
    pc = (char *)p; // typecasting pointer to integer to pointer to character.
    assert(*pc == 1 && "dereferencing pointer to char reads only 1 byte");
    // char * points to singel byte, so arithmetic moves by 1 byte step.
    assert(*(pc + 1) == 4 && "dereferencing pointer to char reads only 1 byte");
    assert(*(pc + 2) == 0);

    // printf("%" PRIuPTR, (uintptr_t)pc);
    // printf("\n");
    // printf("%" PRIuPTR, (uintptr_t)pc + 1);
    // printf("\nvalue at pc+1 pointer: %d", *(pc + 1));
}
