#include <stdio.h>
#include <math.h>

int main() {

    //ex6
    int x, y;
    x = 0;
    y = 0;

    printf("entrez un entier\n");
    scanf("%d", &x);
    fflush(stdin);
    printf("entrez un deuxieme entier\n");
    scanf("%d", &y);
    fflush(stdin);

    int max = x;

    if (x < y) {
        max = y;
    }
    if (x == y) {
        printf("Les deux sont egaux\n");
    } else {
        printf("Le plus grand des deux est : %d\n", max);
    }

    //ex7
    float grade;
    grade = 0;
    printf("Entrez une note\n");
    scanf("%f", &grade);
    fflush(stdin);
    if (grade > 20) {
        printf("Le maximum possible est de 20.0\n");
    } else if (grade >= 18) {
        printf("Tres bien, avec felicitations du jury\n");
    } else if (grade >= 16) {
        printf("Tres bien\n");
    } else if (grade >= 14) {
        printf("Bien\n");
    } else if (grade >= 12) {
        printf("Assez bien\n");
    } else if (grade >= 10) {
        printf("Passable\n");
    } else {
        printf("Echec\n");
    }

    //ex8
    char has_license;
    has_license = 0;
    int age;
    age = 0;
    int chances = 2;

    printf("Bonjour, je suis Robocop. Vos papiers, s'il-vous-plait.\n");

    while (chances > 0) {
        printf("Avez-vous bien votre permis de conduire ?\n('o'ui ou 'n'on)\n");
        scanf(" %c", &has_license);
        fflush(stdin);

        if (has_license == 'o') {
            printf("Declarez votre age.\n(un nombre entier positif)\n");
            scanf(" %d", &age);
            fflush(stdin);

            // scanf(" %d", &age) renvoie 0 si l'utilisateur entre autre chose qu'un entier...

            if (age > 0) {
                printf("Vous dites avoir %d ans.\n", age);
            } else {
                printf("Ne comprend pas ce qu'est un nombre entier positif...\n(Vous etes escorte en prison)\n");
                break;
            }

            if (age >= 18 && age <= 120) {
                printf("Merci. Vous pouvez y aller. Bonne journee.\n");
                break;
            } else if (age > 120) {
                printf("Momie...\n(Vous etes escorte en prison)\n");
                break;
            } else if (age < 18) {
                printf("Mineur...\n(Vous etes escorte en prison)\n");
                break;
            }
        } else if (has_license == 'n') {
            printf("Pas de permis...\n(Vous etes escorte en prison)\n");
            break;
        } else {
            chances--;
            if (chances <= 0) {
                printf("Refuse de repondre 'o' ou 'n'...\n(Vous etes escorte en prison)\n");
                break;
            }
            printf("Derniere chance...\n");
        }
    }

    //ex9
    float a, b, c;
    a = 0;
    b = 0;
    c = 0;

    printf("Veuillez saisir trois reels\n");
    scanf("%f\n%f\n%f", &a, &b, &c);
    fflush(stdin);

    if (a == 0 && b == 0 && c == 0) {
        printf("il y a une infinite de solutions pour a = b = c = 0\n");
    } else if (a == 0 && b == 0) {
        printf("il n'y a pas de solution pour a = b = 0 et c =/= 0\n");
    } else if (a == 0) {
        printf("la solution unique est %f\n", -c / b);
    } else {
        float delta = (b * b) - (4 * a * c);
        if (delta < 0) {
            printf("il n'y a pas de solution reelle pour delta < 0\n");
        } else if (delta == 0) {
            printf("la solution double est %f", -b / (2 * a));
        } else {
            float result1;
            float result2;
            result1 = (-b - sqrtf(delta)) / (2 * a);
            result2 = (-b + sqrtf(delta)) / (2 * a);
            printf("il y a deux solutions : %f et %f\n", result1, result2);
        }
    }

    return 0;
}