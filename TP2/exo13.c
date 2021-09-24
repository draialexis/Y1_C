#include <stdio.h>

void afficheZigzag(int n) {
    for (int i = 0; i < n; i++) {
        printf("z");
    }
    printf("igzag");
}

int zigzag(int debut, int fin, int nbDeZ) {
    int n = fin - debut + 1;
    if (n > 1) {
        for (int i = debut; i <= fin; ++i) {
            if (i % 2 == 0) {
                printf("%d ", i);
            }
            afficheZigzag(nbDeZ);
            if (i % 2 != 0) {
                printf(" %d", i);
            }
            printf("\n");
        }
        return (n);
    } else {
        return 0;
    }
}

int main() {
    int input1;
    int input2;
    int input3;
    printf("Veuillez entrer trois entiers (debut, fin, nb de z (debut devra etre inferieur a fin)):\n");
    scanf("%d\n%d\n%d", &input1, &input2, &input3);
    printf("renvoie : %d\n", zigzag(input1, input2, input3));
    return 0;
}