#include <stdio.h>

int main() {

    char c;

    printf("Donnez un charactere (seul le premier charactere donne sera pris en compte) :");
    scanf(" %c", &c);

    if ((c < 65) || ((c > 90) && (c < 97)) || (c > 122)) {
        printf("ce n'est pas une lettre\n");
        return 0;
    } else {
        printf("code ASCII : %d\n", c);
        if (c != 90 && c != 122) {
            printf("charactere suivant : %c\n", c + 1);
        }
        if (c <= 90) {
            printf("charactere en minuscule : %c\n", c + 32);
        } else if (c >= 97) {
            printf("charactere en majuscule : %c\n", c - 32);
        }
    }
    fflush(stdin);
    return 0;
}