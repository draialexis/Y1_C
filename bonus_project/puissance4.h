//
// Created by draia on 05/02/2021.
//

#ifndef C4_N_STICKS_PUISSANCE4_H
#define C4_N_STICKS_PUISSANCE4_H

#define LIN 6
#define COL 7

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
    char winChar = '4';
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            char x = arr[i][j];
            if (x != c) {
                continue;
            }
            if (j + 3 < COL && x == arr[i][j + 1] && x == arr[i][j + 2] && x == arr[i][j + 3]) {
                arr[i][j] = arr[i][j + 1] = arr[i][j + 2] = arr[i][j + 3] = winChar;
                return 1;
            }
            if (i + 3 < LIN && x == arr[i + 1][j] && x == arr[i + 2][j] && x == arr[i + 3][j]) {
                arr[i][j] = arr[i + 1][j] = arr[i + 2][j] = arr[i + 3][j] = winChar;
                return 1;
            }
            if (j + 3 < COL && i + 3 < LIN && x == arr[i + 1][j + 1] && x == arr[i + 2][j + 2] &&
                x == arr[i + 3][j + 3]) {
                arr[i][j] = arr[i + 1][j + 1] = arr[i + 2][j + 2] = arr[i + 3][j + 3] = winChar;
                return 1;
            }
            if (j >= 3 && i + 3 < LIN && x == arr[i + 1][j - 1] && x == arr[i + 2][j - 2] &&
                x == arr[i + 3][j - 3]) {
                arr[i][j] = arr[i + 1][j - 1] = arr[i + 2][j - 2] = arr[i + 3][j - 3] = winChar;
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

#endif //C4_N_STICKS_PUISSANCE4_H
