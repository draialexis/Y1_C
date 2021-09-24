#include <stdio.h>

//a) on ne connait pas encore le nombre d'itérations, donc on doit utiliser une boucle While
int sommeSuiteWhile() {
    int result = 0;
    int input = 0;
    int min;
    int max;
    int isInitMinMax = 0;

    printf("Veuillez entrer des entier, et terminez par '-1':\n");

    while (input != -1) {
        scanf("%d", &input);
        if (!isInitMinMax) {
            isInitMinMax = 1;
            min = input;
            max = input;
        }
        if (input != -1) {
            result = result + input;
            if (max < input) {
                max = input;
            }
            if (min > input) {
                min = input;
            }
        }
    }

    printf("leur somme est egale a : %d\n", result);
    printf("max de cette suite : %d\n", max);
    printf("min de cette suite : %d\n", min);
    return result;
}

//b) on connait le nombre d'itérations, donc on peut utiliser une boucle For
int sommeSuiteFor() {
    int result = 0;
    int nbInputs = 0;
    int min, max;

    printf("Veuiller indiquer combien d'entiers vous souhaitez additioner :\n");
    scanf("%d", &nbInputs);

    if (nbInputs > 1) {
        printf("Veuillez entrer vos %d entiers :\n", nbInputs);
        int input = 0;
        for (int i = 0; i < nbInputs; i++) {
            scanf("%d", &input);
            result = result + input;
            if (i == 0) {
                max = min = input;
            } else {
                if (max < input) {
                    max = input;
                }
                if (min > input) {
                    min = input;
                }
            }
        }
        printf("leur somme est egale a : %d\n", result);
        printf("max de cette suite : %d\n", max);
        printf("min de cette suite : %d\n", min);
        return result;
    } else {
        printf("INVALID INPUT\n");
    }
    return 0;
}

int main() {
    sommeSuiteWhile();
    sommeSuiteFor();
    return 0;
}
