#include <assert.h>
#include <stdio.h>
#include <string.h>

/*
 * how string is stored in char array ?
 * size of charArr >= # of chars in string + 1
 * "Rocky" size>= 6
 * ['R', 'o', 'c', 'k', 'y', '\0'] null char ASCII value 0, is put at the end to
 * mark that string has terminated string in C is null terminated
 *
 *  Arrays are always passed as reference, base address
 *
 *  char *c = "Hello"; // stored as compiletime comnstant
 *  const char *c // read only pointer
 */

void char_Arr();
void ptr_charray();
void print_chrray(char *c);
int main() {
    char_Arr();
    ptr_charray();
    // char ch[6] = "hello";
    // print_chrray(ch);
}
void print_charray(char *chr) {
    // int i = 0;
    // while (*(chr + i) != '\0') {
    // printf("%c", chr[i]);
    // i +;
    // }
    printf("\n");
    while (*chr != '\0') {
        printf("%c", *chr);
        chr++;
    }
}

void ptr_charray() {
    char c[6] = "Hello";
    // print_charray(c);
    char *ptch = c;
    assert(ptch == c);
    assert(ptch == &c[0]);
    assert(*(ptch + 1) == c[1]);
    assert(*(c + 1) == c[1]);
}
void char_Arr() {
    char c[6];
    c[0] = 'J';
    c[1] = 'o';
    c[2] = 'h';
    c[3] = 'n';
    c[4] = '\0';
    c[5] = 's';

    // printf("%s\n", c);      // print a string till null character
    assert(strlen(c) == 4); // counts till null char

    char stl[] = "John"; // string literal in same line
    assert(strlen(stl) == 4);
    assert(sizeof(stl) == 5);
    // printf("%lu", sizeof(stl));
}
