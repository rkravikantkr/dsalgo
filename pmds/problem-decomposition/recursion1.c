#include <stdio.h>
/*
Problem decompostion by recursion

- Given problem P is divided into k sub problems // Decomposition
- Each sub problem returns result, all results are recomposed to get final
solution of problem P

*/

int factorial(int);
int fibbonacci(int);

int main() {
    int n = 5;
    printf("factorial(%d): %d\n", n, factorial(n));
    printf("fibbonacci(%d): %d\n", n, fibbonacci(n));
}
int fibbonacci(int n) {
    /*
       fib: n
       base: (n <= 0) ; value == 0
            ( n == 1) ; value == 1
       inductive: ( n > 1 ) ; x = fib(n-1) // Decomposition
                              y = fib(n-2) // Decomposition
                              val = x + y  // Recomposition
     */

    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    int x = fibbonacci(n - 1);
    int y = fibbonacci(n - 2);
    return x + y;
}

int factorial(int n) {
    /*
    fact: n

    basis: n == 1 ; value == 1
    inductive: n > 1 ; x = fact(n-1) // Decomposition
                    val = n * x     // Recomposition
    */

    if (n == 1)
        return 1;
    int x = n * factorial(n - 1);
    return x;
}
