#include <stdio.h>

typedef struct {
    float real;
    float imag;
} complex;

complex add_complex(complex, complex);
void read_complex(complex *);
void write_complex(complex);

int main() {

    complex a, b, c;
    read_complex(&a);
    read_complex(&b);
    c = add_complex(a, b);
    write_complex(c);
}

complex add_complex(complex x, complex y) {
    complex t;
    // x is a struct variable
    t.real = x.real + y.real;
    t.imag = x.imag + y.imag;
    return t;
}

void write_complex(complex x) {
    char c[3] = "+j";
    if (x.imag < 0) {
        c[0] = '-';
        x.imag = -x.imag;
    }
    printf("%5.2f %s%5.2f\n", x.real, c, x.imag);
}

void read_complex(complex *x) { // x is a pointer to struct
    scanf("%f%f", &(x->real), &((*x).imag));
}
