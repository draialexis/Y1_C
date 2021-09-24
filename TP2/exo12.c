#include <stdio.h>

int suivant(int n) {
    int result;
    if (n == 1) {
        result = 1;
    } else if ((n % 2) == 0) {
        result = n / 2;
    } else {
        result = (3 * n) + 1;
    }
    return result;
}

void syracuse(int n) {
    while (n != 1) {
        printf("%d, ", n);
        n = suivant(n);
    }
    printf("et %d", n);
}

int main() {
    int input;
    printf("Veuillez entrer un entier superieur a 1:\n");
    scanf("%d", &input);
    if (input > 1) {
        syracuse(input);
    } else {
        printf("INVALID INPUT");
    }
    return 0;
}