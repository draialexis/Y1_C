#include <stdio.h>

#define N 10
#define M 5

void afficheTab(int tab[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i == n - 1) { printf("%d]\n", tab[i]); }
        else if (i == 0) { printf("[%d, ", tab[i]); }
        else { printf("%d, ", tab[i]); }
    }
}


int main() {
    int t1[N] = {1};
    int t2[M] = {1};
    afficheTab(t1, N);
    afficheTab(t2, M);
    return 0;
}