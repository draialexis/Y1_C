#include <stdio.h>
#include <stdlib.h>

typedef struct maillon {
    float linkVal;
    struct maillon * linkPtr;
} link;

typedef struct listeReels {
    struct maillon * listLinkPtr;
    int listSize;
} lr;

struct listeReels * creerListeReelsVide() {
    lr * emptyList = (lr *) malloc(sizeof(lr));
    lr->listSize = 0;
    return emptyList;
}

int retournerTaille(struct listeReels * pSurListe){
    return pSurListe->listSize;
}

void ajouterReelDebut(struct listeReels * pSurListe, float reel){
    pSurListe->listLinkPtr = (link *) malloc(sizeof(link));
    pSurListe->listLinkPtr->linkVal = reel;
    pSurListe->listSize += 1;
}

void afficherListeReels(struct listeReels * pSurListe) {
    for(int i = 0; i < pSurListe->listSize; ++i) {
        
    }
}

int main() {
    ajouterReelDebut(creerListeReelsVide(), 1.25);
    
    return 0;
}
