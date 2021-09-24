#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C 5

int tousEgaux(int tab[][C], int l) {
    int compare = tab[0][0];
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < C; ++j) {
            if (compare != tab[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int ligneCroissante(int tab[][C], int l, int lineToCheck) {
    if ((lineToCheck < 0) || (lineToCheck >= l)) {
        return -1;
    }
    for (int j = 0; j < l - 1; ++j) {
        if (tab[lineToCheck][j] > tab[lineToCheck][j + 1]) {
            return 0;
        }
    }
    return 1;
}

int colonneDecroissante(int tab[][C], int l, int colToCheck) {
    if ((colToCheck < 0) || (colToCheck >= l)) {
        return -1;
    }
    for (int i = 0; i < l - 1; ++i) {
        if (tab[i][colToCheck] >= 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int tab1[5][C] = {
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {1, 0, 0, 0, 0},
    };
    int tab2[5][C] = {0};
    int tab3[5][C] = {
            {1,  2,  0,  5,  4},
            {1,  2,  2,  3,  4},
            {1,  7,  0,  3,  4},
            {-3, 2,  0,  3,  4},
            {-9, -7, -5, -2, -1}
    };
    int tab4[5][C] = {
            {1, 0, 0, 0, -2},
            {0, 0, 0, 0, -1},
            {1, 0, 0, 0, -3},
            {1, 0, 0, 0, -7},
            {1, 0, 0, 0, -1},
    };

    if (tousEgaux(tab1, 5)) {
        printf("tab1: check\n");
    }
    if (tousEgaux(tab2, 5)) {
        printf("tab2: check\n");
    }
    if (tousEgaux(tab3, 5)) {
        printf("tab3: check\n");
    }
    if (ligneCroissante(tab1, 5, 0)) {
        printf("tab1, l0: check\n");
    }
    if (ligneCroissante(tab1, 5, 1)) {
        printf("tab1, l1: check\n");
    }
    if (ligneCroissante(tab2, 5, 1)) {
        printf("tab2, l1: check\n");
    }
    if (ligneCroissante(tab3, 5, 0)) {
        printf("tab3, l0: check\n");
    }
    if (ligneCroissante(tab3, 5, 1)) {
        printf("tab3, l1: check\n");
    }
    if (ligneCroissante(tab3, 5, 2)) {
        printf("tab3, l2: check\n");
    }
    if (ligneCroissante(tab3, 5, 3)) {
        printf("tab3, l3: check\n");
    }
    if (ligneCroissante(tab3, 5, 4)) {
        printf("tab3, l4: check\n");
    }
    if (colonneDecroissante(tab4, 5, 4)) {
        printf("tab4, c4: check\n");
    }
    if (colonneDecroissante(tab3, 5, 4)) {
        printf("tab4, c4: check\n");
    }

    return 0;
}