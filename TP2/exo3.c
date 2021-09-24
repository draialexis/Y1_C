#include <stdio.h>

void readIntegersWithFor(int n) {
    if (n == 1) {
        printf("%d\n", n);
    } else if (n > 1) { // pour n entier positif
        for (int i = 1; i <= n; ++i) {
            printf("%d\n", i);
        }
    } else { // pour n nul ou négatif
        for (int i = 1; i >= n; --i) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int n;
    printf("Veuillez entrer un entier:\n");
    scanf("%d", &n);
    readIntegersWithFor(n);
    return 0;
}

