#include <assert.h>
#include <stdio.h>
void simple_char();
void simple_str();
void change_case(char c);
int main() {
    change_case('a');
    change_case('B');
    // simple_str();
    // simple_char();
    // printf("Hello");
    // fflush(stdout); // Forces "Hello" to display immediately
    //
    // // Simulate delay
    // for (int i = 0; i < 1000000000; i++)
    //     ;
    //
    // printf(" World!");
    return 0;
}

void change_case(char c) {
    /*
    char -> ASCII value
    a -> 97
    A -> 65
    */
    if (c >= 'a') {
        c -= 32;
        printf("%c\n", c);
    } else if (c <= 'Z') {
        c += 32;
        printf("%c\n", c);
    }
}

void simple_str() {
    //   string in C is array of characters terminated by \0 (null character)
    char name[50] = {'R', 'a', 'v', 'i', '\0', 'k'};
    printf("name: %s\n", name); // prints till null char is encountered

    // character is one byte
    for (int i = 0; i < sizeof(name); i++) {
        printf("%c", name[i]);
    }
}

void simple_char() {
    char a = 'a';
    printf("%c\n", a);
    printf("%d\n", a);

    printf("\n");

    char A = 'A';
    printf("%c\n", A);
    printf("%d\n", A);

    char ch;
    printf("enter a character: ");
    scanf("%c", &ch);
    printf("you entered: %c\n", ch);
    printf("its ASCII value is %d\n", ch);
}
