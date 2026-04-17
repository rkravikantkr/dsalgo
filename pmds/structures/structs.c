#include <stdio.h>
// Data encapsulation

int main() {
    int i, j;
    float x; //, y;
    // char a;

    struct {
        char name[25];
        char roll_no[8];
        float sgpa[8];
        float cgpa[8];
    } student1;

    printf("name of student: \n");
    // stud1.name is start address of name array
    scanf("%s", student1.name);
    fflush(stdin);

    printf("roll number: \n");
    scanf("%s", student1.roll_no);
    fflush(stdin);

    printf("number of semesters: ");
    scanf("%u", &j);

    printf("\ngive sgpa values: \n");
    for (i = 0; i < j; i++)
        scanf("%f", &(student1.sgpa[i]));

    printf("%s %s \n", student1.name, student1.roll_no);

    // compute CGPA
    for (x = 0.0, i = 0; i < j; i++) {
        x = (x * i + student1.sgpa[i]) / (i + 1);
        student1.cgpa[i] = x;

        // print cgpa of semester
        printf("cgpa in semester %d is %5.2f \n", i + 1, student1.cgpa[i]);
        ;
    }
}
