#include <assert.h>
#include <stdio.h>

void permute_list(char *, int, int, char *, int);
void sublist(char *, int, int, char *);
int main() {
    /*
    given a list [ a, b, c ] permute its r elements
    */
    char List[] = "abcdef";
    char Perm[20];
    int n = sizeof(List);
    int r = 2;

    permute_list(List, n, r, Perm, 0);
}

void permute_list(char *List, int n, int r, char *Perm, int p) {
    char new_list[n];
    if (r == 0) {
        Perm[p] = '\0';
        printf("%s ", Perm);
        return;
    } else {
        for (int i = 0; i < n - 1; i++) {
            Perm[p] = List[i];
            // make a sublist by removing i_th element
            sublist(List, i, n, new_list);
            permute_list(new_list, n - 1, r - 1, Perm, p + 1);
        }
        return;
    }
}

void sublist(char *list, int i, int n, char *new_list) {
    // delete ith element while copying into new list
    for (int j = 0; j < i; j++) {
        new_list[j] = list[j];
    }
    for (int j = i + 1; j < n; j++) {
        new_list[j - 1] = list[j];
    }
}
