#include <stdio.h>

void readEvens(int n) {
    for (int i = 0; i <= n * 2; i = i + 2) {
        printf("%d\n", i);
    }
}

int main() {
    int n;
    printf("Veuillez entrer un entier:\n");
    scanf("%d", &n);
    readEvens(n);
    return 0;
}