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

int maxTab(int tab[], int n) {
    int max;
    printf("\nS E A R C H I N G   F O R   M A X   I N    A R R A Y\n\n");
    for (int i = 0; i < n; ++i) {
        if (i == 0) { max = tab[i]; }
        if (tab[i] > max) {
            max = tab[i];
        }
    }
    return max;
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

int maxPosTabV1(int tab[], int n) {
    printf("\nS E A R C H I N G   F O R   P O S I T I O N   O F   M A X   I N    A R R A Y   V 1\n\n");
    int result;
    result = rechercheTab(maxTab(tab, n), tab, n);
    return result;
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

int main() {
    srand(time(NULL));
    int t1[N] = {1};
    int t2[M] = {1};
    initRandom(t1, N);
    afficheTab(t1, N);
    initRandom(t2, M);
    afficheTab(t2, M);
    printf("MAX POS dans t2? %d\n", maxPosTabV1(t2, M));
    printf("MAX POS dans t1? %d\n", maxPosTabV2(t1, N));

    return 0;
}