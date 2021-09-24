#include <stdio.h>
#include <stdlib.h>
#define N 5

int maxTab2D(int tab[N][N]){

    int firstLoop = 1;
    int max;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(firstLoop){
                max = tab[i][j];
                firstLoop = 0;
            } else if (max < tab[i][j]){
                max = tab[i][j];
            }
        }
    }
    return max;
}

void afficheMenu(char * prenom)
{
    
    printf("\nBienvenue, %s\n", prenom);
/*
    char inutile;
    scanf("%c%c", &inutile, &inutile);
*/

    printf("1. Afficher le tableau des resultats\n");
    printf("2. Modifier un resultat\n");
    printf("3. Calculer le nombre de points d'une equipe\n");
    printf("4. Afficher les scores\n");
    printf("5. Savoir quelle équipe a le plus de points\n");
    printf("6. Savoir quelle équipe a le plus de victoires à domicile\n");
    printf("7. Savoir quelle équipe a le plus de victoires à l'extérieur\n");
    printf("0. Quitter\n\n");
}

void afficheTab(int tab[N][N]) {
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            printf("[%d] ", tab[i][j]);
        }
        printf("\n");
    }
}

void modifCase(int tab[N][N]){
    int i;
    char iChar[2] = {0};
    printf("Quel est le numero de l'equipe jouant a domicile? ");
    fgets(iChar, 2, stdin);
    i = atoi(iChar);
    printf("______%d\n", i);
}
/* pour modifCase

    
    
    printf("Quel est le numéro de l'équipe jouant à l'extérieur? ");
    printf("Quel est le nouveau resultat? \n (0: match nul, 1: equipe domicile gagnante, 2: equipe exterieur gagnante)\n");
    */



int main()
{
    
    
    int resultats[N][N]={{0, 1, 1, 2, 0},
                         {2, 0, 1, 1, 1},
                         {1, 1, 0, 2, 2},
                         {2, 1, 1, 0, 0},
                         {0, 0, 1, 2, 0}};
    
    
    char nom[20];
    printf("Bienvenue, quel est votre nom ? ");

    fgets(nom, 20, stdin);

    int choice = 1;
    char choiceChar[10] = {0};
    while (choice) {

        afficheMenu(nom);
        printf("le choix (avant): %d\n", choice);
        fgets(choiceChar, 10, stdin);
        choice = atoi(choiceChar);
        printf("le choix (apres): %d\n", choice);
        switch(choice){
            case 0:
                break;
            case 1:
                afficheTab(resultats);
                break;
            case 2:
                modifCase(resultats);
                break;
            default: 
                printf("valeur non reconnue\n");
                break;
        }  
    }


    printf("Votre choix: %d\n", choice);
    /*
    printf("Choisissez un numero d'équipe: ");
    
    printf("L'equipe ayant le plus de points est l'équipe %d avec %d points\n", A COMPLETER);
    
    printf("L'equipe %d avec %d victoires à domicile est la meilleure dans ces conditions\n", A COMPLETER);
    
    printf("L'equipe %d avec %d victoires à l'exterieur est la meilleure dans ces conditions\n", A COMPLETER );
    */
    printf("Au revoir\n");
    
    return 0;
}
