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
 */

int main(void) {
    int a;
    int *p = &a;

    printf("%p\n", &a); // print address of a
    printf("%p\n", p);  // p contains same address as value stored in p
}
