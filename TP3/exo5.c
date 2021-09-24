#include <stdlib.h>
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

void initClavier(int tab[], int n) {
    printf("\nI N I T I A L I Z I N G   W I T H   K E Y B O A R D\n\n[");
    int input = -1;

    for (int i = 0; i < n; ++i) {
        while (input < 1) {
            printf("Veuillez entrer un entier positif :");
            scanf("%d", &input);
        }
        printf("%d : OK\n", input);
        tab[i] = input;
        input = -1;
    }
}

int main() {
    int t1[N] = {1};
    int t2[M] = {1};
    initRandom(t1, N);
    afficheTab(t1, N);
    initRandom(t2, M);
    afficheTab(t2, M);
    initClavier(t1, N);
    afficheTab(t1, N);
    initClavier(t2, M);
    afficheTab(t2, M);
    return 0;
}