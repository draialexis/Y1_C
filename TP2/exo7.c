#include <stdio.h>

int somme(int n) {
    int result = 0;
    
    for (int i = 1; i <= n; i++) {
        /*
         * Quand n == 0, on n'entre pas dans ce bloc de code
         * (i <= 0 est faux car i == 1)
         * Comme result est initialisé à 0, somme(0) renvoie 0.
         */
        result = result + i;
    }
    return result;
}

int main() {
    int n;
    printf("Veuillez entrer un entier:\n");
    scanf("%d", &n);
    printf("%d\n", somme(n));
    return 0;
}