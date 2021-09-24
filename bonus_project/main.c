#include <stdio.h>
#include <stdlib.h>

#include "puissance4.h"
#include "batonnets.h"

int main() {
    int gameNb = 0;
    int winner;
    while (gameNb != 1 && gameNb != 2) {
        printf("choisissez un jeu :\n 1 -- batonnets\n 2 -- puissance4\n\n-1 -- quitter le menu\n");

        char input[16];

        fgets(input, 15, stdin);
        gameNb = (int) strtol(input, NULL, 10);

        if (gameNb == -1) {
            return 0;
        }
    }

    if (gameNb == 1) {
        winner = batonnets();
    } else {
        winner = puissance4();
    }

    if (winner) {
        printf("le vainqueur est : joueur %d\n", winner);
    }

    return 0;
}