#include <stdio.h>

//a)
void rectangleFixe(int n, int m) {
    printf(". . . S T A R T I N G      R E C T A N G L E  F I X E. . .\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");
}

//b)
void rectangleSomme(int n, int m) {
    printf(". . . S T A R T I N G      R E C T A N G L E  S O M M E. . .\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", i + j);
        }
        printf("\n");
    }
    printf("\n");
}

//c)
void rectangleSommeDetail(int n, int m) {
    printf(". . . S T A R T I N G      R E C T A N G L E  S O M M E  D E T A I L. . .\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d+%d ", i, j);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int input1, input2;
    printf("Veuillez entrer deux entiers superieurs a zero, dont au moins un superieur a un :\n");
    scanf("%d\n%d", &input1, &input2);
    if (input1 >= 1 && input2 >= 1 && (input1 > 1 || input2 > 1)) {
        rectangleFixe(input1, input2);
        rectangleSomme(input1, input2);
        rectangleSommeDetail(input1, input2);
    } else {
        printf("INVALID INPUT\n");
    }
    return 0;
}