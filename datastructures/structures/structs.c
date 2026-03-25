#include <stdio.h>

/*
 * struct groups same or different data types under  a single name
 * its a user derived data type
 * variables used are called members / property / fields of struct
 * The members of a structure are stored in memory in the order in which they’re
 * declared.
 */
// named struct, struct tag
struct employee {
    int empno;
    char empname[50];
    float salary;
};

int main() {

    // anynomous structs
    struct {
        int number;
        char name[10];
        int on_hand;
    } part1 = {532, "Disk Drive", 10}, part2 = {913, "Printer", 5};
}
