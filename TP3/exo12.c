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

void bubbleSort(int tab[], int n) {
    int tmp;
    int flags;
    int loops = 0;
    do {
        flags = 0;
        afficheTab(tab, n);
        printf("___new loop___\n");
        for (int i = 0; i < n - 1 - loops; ++i) {
            if (tab[i] > tab[i + 1]) {
                printf("moving %d (tab[%d])\n", tab[i], i);
                afficheTab(tab, n);
                tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                ++flags;
                --i;
            }
        }
        ++loops;
        if (!flags) {
            printf("no out-of-place element found...\n");
        }
    } while (flags);
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

    bubbleSort(t1, N);
    bubbleSort(t2, M);
    return 0;
}