#include <assert.h>
#include <stdio.h>
/*
 *  Pointers and Multidimensional array
 *  *(A+i) == A[i]
 *  A+i == &A[i]
 */
void twoDArr();
void oneDArr();
void threeDArr();

int main() {
    threeDArr();
    // twoDArr();
    // oneDArr();
}

void threeDArr() {
    int c[3][2][2] = {{{1, 2}, {4, 9}}, {{0, 3}, {7, 2}}, {{8, 5}, {5, 8}}};
    int (*p)[2][2] = c;
    assert(p == c);

    // C[i][j][k] == *(c[i][j]+k) == *(*(c[i]+[j]+k) == *(*(*(c+i)+j)+k)
}

void oneDArr() {
    int A[] = {1, 2, 3, 4, 5};
    int *p = A; // pointer to entire array
    assert(p = A);
    assert(*p = A[0]);
}

void twoDArr() {
    {
        int B[2][2] = {{1, 2}, {3, 4}};
        int (*pb)[2] = B; // pointer to 1D array of 2 integers

        assert(pb == B);
        assert(pb + 1 == &B[1]);
        assert(*pb == B[0]);
    }
    {
        int b[4][3] = {{1, 2, 3}, {4, 5, 6}, {11, 21, 31}, {42, 52, 62}};
        int (*p)[3] = b; // pointer to 1D array of 3 integers

        assert(*b == b[0]);
        assert(*p == b[0]);     // address of fist row
        assert(*p == &b[0][0]); // &b[0][0] address of first element

        assert(*(p + 1) == b[1]);
        assert(*(p + 1) == &b[1][0]);
        assert(*(p + 2) == b[2]);

        // *b is b[0] or &b[0][0]
        // *(*b) is b[0][0]
        // *(*b+i) is b[0][i] in same array at i distance from fist element
        assert(*(*b + 1) == b[0][1]);

        assert(b[1][2] == 6);
        assert(b[1][2] == *(b[1] + 2));
        assert(b[1][2] == *(*(b + 1) + 2));
        // B[i][j] == *(B[i]+j) == *(*(B+i)+j)
    }

    // int I[1][1] = {{1}};
    // int (*i)[1][1] = &I; // Pointer to the entire array
}
