#include <stdio.h>

float perimetreRectangle(float longueur, float largeur) {
    float perimetre;
    perimetre = (2 * longueur) + (2 * largeur);
    return perimetre;
}

float aireRectangle(float longueur, float largeur) {
    float aire;
    aire = longueur * largeur;
    return aire;
}

float aireTriangleRectangle(float longueur, float largeur) {
    float aire;
    aire = longueur * largeur / 2;
    return aire;
}

int main() {
    float L, l;
    float resultat;

    printf("Longueur du rectangle:");
    scanf("%f", &L);
    printf("Largeur du rectangle:");
    scanf("%f", &l);

    resultat = perimetreRectangle(L, l);
    printf("Le perimetre du rectangle ayant comme longueur %f et comme largeur %f est: %f.\n", L, l, resultat);
    printf("L'aire de ce rectangle est: %f.\n", aireRectangle(L, l));
    resultat = aireTriangleRectangle(L, l);
    printf("L'aire du triangle rectangle ayant comme longueur %f et comme largeur %f est: %f.\n", L, l, resultat);

    return 0;
}
