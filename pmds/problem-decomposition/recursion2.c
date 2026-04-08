#include <stdio.h>
/*
Tower of Hanoi

- move disk 1 and 2 to position B in same order, picking up one disk at time and
larger disk should never be placed above the smaller disk

1           1
2           2
A B C     A B C


1          1
2          2
3          3
A B C    A B C

Tower: (n, from:A, to:B, via:C)

Base: (n==1);     L1 = ( from:A, to:B)

// Decomposition
Inductive: (n>1); L1 = Tower(n-1, from:A, to:C, via:B) # top n-1 disk to C
                  L2 = Tower(1, from:A, to:B, via:C)  # last dist to B
                  L3 = Tower(n-1, from:C to:B, via:A) # rest n-1 disks from C->B

                  // Recomposition
                  L = append(L1,L2,L3)
*/

void tower(int, char, char, char);
int main() {
    int n = 3;
    tower(n, 'A', 'B', 'C');
}

void tower(int n, char from, char to, char via) {
    // height of tower n
    char A = from;
    char B = to;
    char C = via;

    if (n == 1) {
        printf("%c->%c\n", from, to);
        return;
    } else {

        // transfer top n-1 disks to C via B
        tower(n - 1, A, C, B);

        // move last disk to B
        printf("%c->%c\n", from, to);

        // transfer all n-1 from C to B
        tower(n - 1, C, B, A);
    }
}
