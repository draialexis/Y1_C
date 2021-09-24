#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define N 15
#define M 7

void afficheTab(int tab[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i == n - 1) { printf("%d]\n", tab[i]); }
        else if (i == 0) { printf("[%d, ", tab[i]); }
        else { printf("%d, ", tab[i]); }
    }
}

void initRandom(int tab[], int n) {
    printf("\nI N I T I A L I Z I N G   R A N D O M L Y\n\n");

    for (int i = 0; i < n; ++i) {
        tab[i] = rand() % 11;
    }
}

int rechercheTab(int x, int tab[], int n) {
    printf("\nS E A R C H I N G   A R R A Y\n\n");
    for (int i = 0; i < n; ++i) {
        if (tab[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    srand(time(NULL));
    int t1[N] = {1};
    int t2[M] = {1};
    initRandom(t1, N);
    afficheTab(t1, N);
    initRandom(t2, M);
    afficheTab(t2, M);
    printf("7 est dans t1? %d\n", rechercheTab(7, t1, N));
    printf("7 est dans t2? %d\n", rechercheTab(7, t2, M));
    return 0;
}