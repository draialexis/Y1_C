#include <stdio.h>

int main() {

    int n;
    n = 0;
    printf("Donnez un entier:");
    scanf("%d", &n);

    if (n < 100) {
        printf("n est strictement inferieur a 100\n");
    } else {
        printf("n est superieur ou egal a 100\n");
    }

    printf("n est egal a %d.\n", n);
    fflush(stdin);
    return 0;
}