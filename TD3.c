#include <stdio.h>
#include <stdlib.h>

#define T 11
#define T1 6
#define T2 4

//ex1
//a)
void afficheTabInt(int tab[], int taille) {
    for (int i = 0; i < taille; ++i) {
        if (i == 0 && i == taille - 1) {
            printf("[%d]\n", tab[i]);
        }
        if (i == 0) {
            printf("[%d, ", tab[i]);
        } else if (i == taille - 1) {
            printf("%d]\n", tab[i]);
        } else {
            printf("%d, ", tab[i]);
        }
    }
}

void afficheTabFloat(float tab[], int taille) {
    for (int i = 0; i < taille; ++i) {
        if (i == 0 && i == taille - 1) {
            printf("[%f]\n", tab[i]);
        }
        if (i == 0) {
            printf("[%f, ", tab[i]);
        } else if (i == taille - 1) {
            printf("%f]\n", tab[i]);
        } else {
            printf("%f, ", tab[i]);
        }
    }
}

//b)
void afficheTabIntReverse(int tab[], int taille) {
    for (int i = taille - 1; i >= 0; --i) {
        if (i == taille - 1) {
            printf("[%d, ", tab[i]);
        } else if (i == 0) {
            printf("%d]\n", tab[i]);
        } else {
            printf("%d, ", tab[i]);
        }
    }
}

//ex2
//a)
int somme(int tab[], int taille) {
    int result = 0;
    for (int i = 0; i < taille; ++i) {
        result = result + tab[i];
    }
    return result;
}

//b)
int sommePairs(int tab[], int taille) {
    int result = 0;
    for (int i = 0; i < taille; ++i) {
        if (tab[i] % 2 == 0) {
            result = result + tab[i];
        }
    }
    return result;
}

//c)
int sommeNegatifs(int tab[], int taille) {
    int result = 0;
    for (int i = 0; i < taille; ++i) {
        if (tab[i] < 0) {
            result = result + tab[i];
        }
    }
    return result;
}

//ex3
int plateau(int tab[], int taille) {

    int p = 1;
    int maxP = 1;

    for (int i = 0; i < taille - 1; ++i) {
        if (tab[i] == tab[i + 1]) {
            ++p;
        } else {
            if (p > maxP) {
                maxP = p;
            }
            p = 1;
        }
    }
    return maxP;
}

//ex4
int isSorted(int tab[], int taille) {
    int flags = 0;
    for (int i = 0; i < taille - 1; ++i) {
        if (tab[i] > tab[i + 1]) {
            ++flags;
        }
    }
    if (flags) {
        return 0;
    }
    return 1;
}

//ex5
//a)
int recherche1(int tab[], int taille, int cible) {
    for (int i = 0; i < taille; ++i) {
        if (tab[i] == cible) {
            return i;
        }
    }
    return -1;
}

//b)
int recherche2(int tab[], int start, int end, int cible) {
    if (end >= start) {
        int split = start + (end - start) / 2;

        if (tab[split] == cible) {
            return split;
        }
        if (tab[split] > cible) {
            return recherche2(tab, start, split - 1, cible);
        }
        return recherche2(tab, split + 1, end, cible);
    }
    return -1;
}

//c)
/*
 * recherche2 aura typiquement moins d'iterations que recherche1
 * c'est particulierement interessant quand la taille du tableau est grande
 * pour taille = 12, on compte entre 1 et 12 iterations avec r1
 * pour taille = 12, on compte entre 1 et 4 iterations ((x/2)^2) avec r2
 */

//ex6
void insereElement(float tab[], int taille, float nvElem, int position) {
    float tmp;
    if ((position >= 0) && (position < taille)) {
        afficheTabFloat(tab, taille);

        for (int i = taille - 1; i > position; --i) {
            tmp = tab[i];
            tab[i] = tab[i - 1];
            tab[i - 1] = tmp;
        }
        tab[position] = nvElem;
        afficheTabFloat(tab, taille);

    } else {
        printf("Indice non valide");
    }
}

//exo7
int supprimeElem(float tab[], int tailleUtilisee, int position) {
    if ((position >= 0) && (position < tailleUtilisee)) {
        int nouvelleTaille = tailleUtilisee - 1;
//        afficheTabFloat(tab, tailleUtilisee);

        for (int i = position; i <= nouvelleTaille; ++i) {
            tab[i] = tab[i + 1];
            if (i == nouvelleTaille) {
                tab[i] = -1;
            }
        }
        afficheTabFloat(tab, nouvelleTaille);
    } else {
        printf("Indice non valide");
        return -1;
    }
    return tailleUtilisee - 1;
}

//exo8
void concatenation(float t1[], float t2[], int n1, int n2) {
    printf("__________________________concatenation_________________________\n");
    afficheTabFloat(t1, n1);
    afficheTabFloat(t2, n2);
    int n3 = n1 + n2;
    float t3[n3];
    int currentPos = 0;

    for (int i = 0; i < n1; ++i) {
        t3[currentPos] = t1[i];
        ++currentPos;
    }
    for (int j = 0; j < n2; ++j) {
        t3[currentPos] = t2[j];
        ++currentPos;
    }
    afficheTabFloat(t3, n3);
}

void sortedUnion(float t1[], float t2[], int n1, int n2) {
    printf("___________________________sorted union_____________________________\n");
    afficheTabFloat(t1, n1);
    afficheTabFloat(t2, n2);
    int i, j, k;
    j = k = 0;

    int n3 = n1 + n2;
    float t3[n3];

    for (i = 0; i < n3;) {
        if (j < n1 && k < n2) {
            if (t1[j] < t2[k]) {
                t3[i] = t1[j];
                ++j;
            } else {
                t3[i] = t2[k];
                ++k;
            }
            ++i;
        } else if (j == n1) {
            for (; i < n3;) {
                t3[i] = t2[k];
                ++k;
                ++i;
            }
        } else {
            for (; i < n3;) {
                t3[i]=t1[j];
                ++j;
                ++i;
            }
        }
    }
    afficheTabFloat(t3, n3);
}

int main() {
    int tab[T];
    for (int i = 0; i < T; ++i) {
        tab[i] = rand() % 4;
    }

    float t1[T1];
    for (int i = 0; i < T1; ++i) {
        t1[i] = rand() % 4;
    }
    float t2[T2];
    for (int i = 0; i < T2; ++i) {
        t2[i] = rand() % 4;
    }

    int tabSorted[T] = {0, 0, 2, 4, 5, 12, 34, 61, 62, 78, 86};
    float tabSortedFloat[T] = {0, 0, 2, 4, 5, 12, 34, 61, 62, 78, 86};
    float tsf1[T] = {0, 0, 2, 3, 5, 12, 34, 61, 62, 68, 69};
    float tsf2[T] = {0, 0, 2, 4, 5, 12, 24, 61, 65, 78, 86};

    afficheTabInt(tab, T);
    afficheTabIntReverse(tab, T);

    printf("la somme est : %d\n", somme(tab, T));
    printf("la somme des pairs est : %d\n", sommePairs(tab, T));
    printf("la somme des negatifs est : %d\n", sommeNegatifs(tab, T));

    printf("Le plus long plateau est de : %d\n", plateau(tab, T));

    printf("Le tableau tab est trie : ");
    if (isSorted(tab, T)) {
        printf("VRAI\n");
    } else {
        printf("FAUX\n");
    }

    int cible1 = 2;

    printf("L'entier cible1 %d se trouve en position : %d\n", cible1, recherche1(tab, T, cible1));

    int cible2 = 94;

    printf("L'entier cible2 %d se trouve en position : %d\n", cible2, recherche2(tabSorted, 0, T - 1, cible2));

    float inserted = 3.5;
    insereElement(tabSortedFloat, T, inserted, 5);
    printf("Le tableau de taille initiale %d est maintenant de taille %d\n", T, supprimeElem(tabSortedFloat, T, 3));

    concatenation(t1, t2, T1, T2);
    sortedUnion(tsf1, tsf2, T, T);

    return 0;
}