//
// Created by draia on 05/02/2021.
//

#ifndef C4_N_STICKS_BATONNETS_H
#define C4_N_STICKS_BATONNETS_H

#define INIT_BAT_NB 20

//TODO implement CPU-player

int takeBatCheck(int currentBatNb) {

    char input[16];
    int value;
    fgets(input, 15, stdin);
    value = (int) strtol(input, NULL, 10);

    if (value >= 1 && value <= 3 && value < currentBatNb) {
        printf("vous avez choisi : %d batonnet(s).\nil en reste %d\n", value, currentBatNb - value);
        return currentBatNb - value;
    } else {
        printf("l'input est invalide\nvous devez choisir d'enlever entre 1 et 3 batonnets,"
               " et moins que le nombre de batonnets restant\n");
        return takeBatCheck(currentBatNb);
    }
}

int batonnets() {
    int currentPlayer = 1;
    int currentBatNb = INIT_BAT_NB;
    printf("jeu des batonnets :\nil y a 20 batonnets. veuillez choisir le nombre de batonnets a retirer.\n"
           "(le nombre initial est %d, et vous pouvez retirer 1, 2, ou 3 batonnets)\n", INIT_BAT_NB);

    while (currentBatNb > 1) {
        if (currentPlayer == 1) {
            printf("joueur 1 : ");
            currentPlayer = 2;
        } else {
            printf("joueur 2 : ");
            currentPlayer = 1;
        }
        currentBatNb = takeBatCheck(currentBatNb);
    }
    printf("========== joueur %d -- acceptez votre defaite ==========\n", currentPlayer);
    return currentPlayer == 2 ? 1 : 2; // le joueur actuel est celui qui n'a pas pu jouer son dernier coup ( => défaite)
    // -> "joueur actuel est #2? si oui, return 1 -- sinon, return 2"
}

#endif //C4_N_STICKS_BATONNETS_H
