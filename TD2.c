#include <stdio.h>

//TD2exo2
//c)
void showIntsDW() {
    printf(". . . S T A R T I N G      S H O W  I N T S  D W. . .\n");
    int i = 0;
    do {
        printf("%d\n", ++i);
    } while (i < 10);
}

//b)
void showIntsW() {
    printf(". . . S T A R T I N G      S H O W  I N T S  W. . .\n");
    int i = 0;
    while (i < 10) {
        printf("%d\n", ++i);
    }
}

//a)
void showIntsF() {
    printf(". . . S T A R T I N G      S H O W  I N T S  F. . .\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }
}

//TD2exo3
//a)
void threeByThree() {
    printf(". . . S T A R T I N G      3 B 3. . .\n");
    int n;
    n = 0;
    printf("Veuillez entrer un entier positif :\n");
    scanf("%d", &n);
    fflush(stdin);
    if (n < 0) {
        printf("n est negatif");
    } else {
        for (int i = 0; i <= n; i++) {
            printf("%d\n", 3 * i);
        }
    }
}

void threeByThreeStep() {
    printf(". . . S T A R T I N G      3 B 3 S. . .\n");
    int n;
    printf("Veuillez entrer un entier positif :\n");
    scanf("%d", &n);
    fflush(stdin);
    if (n < 0) {
        printf("n est negatif");
    } else {
        for (int i = 0; i <= n; i = i + 3) {
            printf("%d\n", i);
        }
    }
}

/* b
 * les deux programmes présentent des différencess à l'exécution.
 * Dans le premier cas, on affiche les entiers, en comptant de trois en trois,
 * de 0 à (n * 3).
 * Dans le deuxieme cas, c'est de 0 à n
 */

//TD2exo4

void table() {
    printf(". . . S T A R T I N G      T A B L E. . .\n");
    int n;
    n = 0;
    printf("Veuillez entrer un entier :\n");
    scanf("%d", &n);
    fflush(stdin);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

//TD2exo5
//a) le programme affiche "Fin" immédiatement, car n (potentiellement) !> 0 et on n'entre pas dans le While
//b) Hell yeah! I mean, no.
void showFin() {
    printf(". . . S T A R T I N G      S H O W F I N. . .\n");
    printf("(entrez un entier négatif ou '0' pour arreter le cycle)\n");
    int n = 0;
    int max = 0;
    int min = 0;
    int maxImpair = 0;
    int premierTour = 1;

    do {
        if ((!premierTour) && ((min > n) || (!min))) {
            min = n;
        } else if (premierTour) {
            premierTour = 0;
        }
        printf("Veuillez entrer un entier strictement positif :\n");
        scanf("%d", &n);
        fflush(stdin);
        if (max < n) {
            max = n;
            if (n % 2 != 0) {
                maxImpair = n;
            }
        }
    } while (n > 0);

    if (n <= 0) {
        printf("Min = %d\n", min);
        printf("Max = %d\n", max);
        if (maxImpair) {
            printf("Max impair = %d\n", maxImpair);
        } else {
            printf("Pas d'entiers impairs a signaler\n");
        }
        printf("Fin\n");
    }
}

//TD2exo6
//a) voir main()
//b) Il vous faudra 5 annees.
//c) boucle infinie, nbMouistique constament tronqué à 99.
//d) par la nature de l'affirmation n+1 = n/2 + 50, on sait que le point d'equilibre de la population est 100.
// par la nature des divisions entieres dans C, le maximum qu'on peut atteindre est 100-1=99
// On peut arrondir à l'entier supérieur à la place, et controller que le seuil est
// bien inférieur ou égal au point d'équilibre

int nbAnnees(int nbDebut, int seuil) {
    printf(". . . S T A R T I N G      N B  A N N E E S. . .\n");

    int nbMoustiques = nbDebut;
    int annees = 0;
    int pointFixe = 0;
    int nbPrev;
    printf("Calcul en cours...\n");
    while ((nbMoustiques < seuil) && (!pointFixe)) {
        nbPrev = nbMoustiques;
        nbMoustiques = (nbMoustiques / 2) + 50;
        annees++;
        printf("%d\n", nbMoustiques);
        if (nbMoustiques == nbPrev) {
            pointFixe = 1;
            printf("Nous avons atteint le point fixe.\n");
        }
    }
    return annees;
}

//TD2exo7
//a)
//b)
//c)
int sensInverse(int n) {
    int result = 0;
    for (int i = n; i >= 0; i--) {
        printf("%d\n", i);
        result = result + i;
    }
    return result;
}

//TD2exo8
int multipleSept(int n) {
    int result = n;
    while (result % 7 != 0) {
        result++;
    }
    return result;
}

//TD2exo9
//si n>m, on n'entre pas dans la boucle for. Il faut ajouter un bloc
//qui s'executera quand n>m, pour inverser n et m par exemple.
int sommeIntervalle(int n, int m) {
    int result = 0;
    if (n == m) { return result; }
    if (n > m) {
        int tmp;
        tmp = m;
        m = n;
        n = tmp;
    }
    for (int i = n; i <= m; i++) {
        result += i;
        printf("i = %d, result = %d\n", i, result);
    }
    return result;
}

//TD2exo10
int sommeEntreMultipleSept(int a, int b) {
    int c = multipleSept(a);
    int d = multipleSept(b);
    printf("c : %d\n", c);
    printf("d : %d\n", d);
    return sommeIntervalle(c, d);
}

//TD2exo11
long long power(int a, int b) {
    if (b < 0) {
        printf("INVALID INPUT\n");
        return 0;
    }
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    long long result = 1;
    for (int i = 1; i <= b; ++i) {
        result = result * a;
        printf("%lld\n", result);
    }
    return result;
}

int main() {
    showIntsDW();
    showIntsW();
    showIntsF();
    threeByThree();
    threeByThreeStep();
    table();
    showFin();

    int initial = 0;
    int cible = 0;
    printf("Avec combien de moustiques commencer ? :");
    scanf("%d", &initial);
    fflush(stdin);
    printf("Combien de moustiques visez-vous ? :");
    scanf("%d", &cible); // missing &
    fflush(stdin);
    int n6 = nbAnnees(initial, cible); // missing line, missing type
    printf("Il vous faudra %d annees.\n", n6);// missing ;

    int n7;
    printf("Veuillez entrer un entier strictement positif :");
    scanf("%d", &n7);
    fflush(stdin);
    printf("La somme des entiers affiches : %d\n", sensInverse(n7));
    printf("Le plus petit multiple de sept superieur ou egal a n est : %d\n", multipleSept(n7));

    int n9;
    int m9;
    printf("Veuillez entrer deux entiers, le deuxieme strictement positif:\n");
    scanf("%d\n%d", &n9, &m9);
    fflush(stdin);
    printf("%d ^ %d = %lld\n", n9, m9, power(n9, m9));
    printf("La somme des entiers dans l'intervalle est : %d\n", sommeIntervalle(n9, m9));
    printf("La somme des entiers dans l'intervalle entre les multiples blablabla est : %d\n", sommeEntreMultipleSept(n9, m9));

    return 0;
}