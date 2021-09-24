#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 30
#define S 100

void majuscule(char *source, char *destination) {
    strcpy(destination, source);

    for (int i = 0; i < strlen(destination); ++i) {
        if (destination[i] == '\0') {
            return;
        }
        if ((destination[i] >= 'a') && (destination[i] <= 'z')) {
            destination[i] = (char) destination[i] - 32;
        }
    }
}

int main(int argc, char *argv[]) {

    if (argc != 7) {

        printf("Nombre invalide de parametres\n");

    } else {

        char prenom1[N];
        strcpy(prenom1, argv[1]);
        char nom1[N];
        strcpy(nom1, argv[2]);
        char nom1Maj[N];
        majuscule(nom1, nom1Maj);
        int age1;
        age1 = strtol(argv[3], NULL, 10);

        char prenom2[N];
        strcpy(prenom2, argv[4]);
        char nom2[N];
        strcpy(nom2, argv[5]);
        char nom2Maj[N];
        majuscule(nom2, nom2Maj);
        int age2;
        age2 = strtol(argv[6], NULL, 10);

        char prenom[N];
        char nom[N];
        int age;
        if (nom1Maj[0] <= nom2Maj[0]) { //not really dealing with the == case...
            strcpy(prenom, prenom1);
            strcpy(nom, nom1Maj);
            age = age1;
        } else {
            strcpy(prenom, prenom2);
            strcpy(nom, nom2Maj);
            age = age2;
        }

        char phrase[S];
        sprintf(phrase, "le premier (ABC) est %s %s(%d ans)\n", prenom, nom, age);
        printf("%s", phrase);
    }
    return 0;
}
