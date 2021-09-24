#include <stdio.h>
#include <stdlib.h>

#define INIT_BAT_NB 20
#define LIN 6
#define COL 7


/*
 * v v v   fonctions liées au puissance4   v v v
 */

//TODO inmplement CPU-player

void display2DArr(char arr[LIN][COL]) {
    printf("\n");

    for (int i = 0; i < LIN; ++i) {
        for (int j = 0; j < COL; ++j) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int checkForV(char arr[LIN][COL], char c) {

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            char x = arr[i][j];
            if (x != c) {
                continue;
            }
            if (j + 3 < COL && x == arr[i][j + 1] && x == arr[i][j + 2] && x == arr[i][j + 3]) {
                return 1;
            }
            if (i + 3 < LIN && x == arr[i + 1][j] && x == arr[i + 2][j] && x == arr[i + 3][j]) {
                return 1;
            }
            if (j + 3 < COL && i + 3 < LIN && x == arr[i + 1][j + 1] && x == arr[i + 2][j + 2] &&
                x == arr[i + 3][j + 3]) {
                return 1;
            }
            if (j >= 3 && i + 3 < LIN && x == arr[i + 1][j - 1] && x == arr[i + 2][j - 2] &&
                x == arr[i + 3][j - 3]) {
                return 1;
            }
        }
    }
    return 0;
}

//TODO find a workaround to avoid using variables to designate array index? (or is it just when initializing an array?)
int insertCoinThingy(char arr[LIN][COL], int currentPlayer, int turnsLeft[]) {

    char input[16];
    int index;
    fgets(input, 15, stdin);
    index = (int) strtol(input, NULL, 10);
    int col = index - 1;

    for (int i = LIN - 1; i >= 0;) {
        if (arr[i][col] == '-') {
            if (currentPlayer == 1) {
                arr[i][col] = 'o';
                if (checkForV(arr, 'o') == 1) {
                    return currentPlayer;
                }
            } else {
                arr[i][col] = 'x';
                if (checkForV(arr, 'x') == 1) {
                    return currentPlayer;
                }
            }
            display2DArr(arr);
            --turnsLeft[0];
            return 200;
        } else {
            --i;
        }
    }
    printf("colonne remplie ou inexistante, entrez un entier valide entre 1 et 7\n");
    return insertCoinThingy(arr, currentPlayer, turnsLeft);
}

int puissance4() {
    int turnsLeft[1] = {42};
    int winner = 0;
    char arr[LIN][COL] =
            {
                    {'-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-'}
            };
    display2DArr(arr);

    int currentPlayer = 1;
    printf("puissance 4 :\nalignez 4 jetons dans un tableau de 6 x 7... diagonales acceptees\n");

    while (turnsLeft[0] > 0) {
        printf("il reste %d tours\nchoisissez une colonne\n", turnsLeft[0]);
        if (currentPlayer == 1) {
            printf("joueur 1 (o) :");
            currentPlayer = 2;
        } else {
            printf("joueur 2 (x) :");
            currentPlayer = 1;
        }
        winner = currentPlayer == 2 ? 1 : 2;
        if (insertCoinThingy(arr, winner, turnsLeft) == winner) {
            display2DArr(arr);
            printf("========== bien joue, joueur %d ==========\n", winner);
            return winner;
        }
    }
    printf("========== match nul ==========\n");
    return 0;
}

/*
 * ^ ^ ^   fonctions liées au puissance4   ^ ^ ^
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 * v v v   fonctions liées au jeu des bâtonnets   v v v
 */

//TODO inmplement CPU-player

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

/*
 * ^ ^ ^   fonctions liées au jeu des bâtonnets   ^ ^ ^
 */
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//TODO

int main() {
    int gameNb = 0;
    int winner = 0;
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