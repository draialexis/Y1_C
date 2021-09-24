#include <stdio.h>

void readIntegersWithWhile(int n) {
    int i = 1;

    if (n == 1) {
        printf("%d\n", n);
    } else if (n > 1) { // pour n entier positif
        while (i <= n) {
            printf("%d\n", i++);
        }
    } else { // pour n nul ou négatif
        while (i >= n) {
            printf("%d\n", i--);
        }
    }
}

int main() {
    int n;
    printf("Veuillez entrer un entier:\n");
    scanf("%d", &n);
    readIntegersWithWhile(n);
    return 0;
}