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
        tab[i] = rand() % 1001;
    }
}


int maxPosTabV2(int tab[], int n) {
    printf("\nS E A R C H I N G   F O R   P O S I T I O N   O F   M A X   I N    A R R A Y   V 2\n\n");
    int iMax;
    for (int i = 0; i < n; ++i) {
        if (i == 0) { iMax = i; }
        if (tab[i] > tab[iMax]) {
            iMax = i;
        }
    }
    return iMax;
}

int echangeDernierTab(int tab[], int n, int p) {
    if (p > n - 1 || p < 0) {
        printf("Indice non valide\n");
        return 0;
        } else {
            afficheTab(tab, n);
            printf("\nS W I T C H I N G   T A B [ %d ]   W I T H   T A B [ %d ]\n\n", p, (n - 1));
            int tmp = tab[p];
            tab[p] = tab[n - 1];
            tab[n - 1] = tmp;
            afficheTab(tab, n);
            return 1;
    }
}

void sortByMax(int tab[], int n) {
    printf("\n__________let the sorting begin__________\n");
    int maxPos;
    for (int i = n; i > 1; --i) {
        maxPos = maxPosTabV2(tab, i);
        echangeDernierTab(tab, i, maxPos);
    }
    printf("\n__________result__________\n");
    afficheTab(tab, n);
}

int main() {
    srand(time(NULL));
    int t1[N] = {1};
    int t2[M] = {1};
    initRandom(t1, N);
    afficheTab(t1, N);
    initRandom(t2, M);
    afficheTab(t2, M);

    sortByMax(t1, N);
    sortByMax(t2, M);
    return 0;
}