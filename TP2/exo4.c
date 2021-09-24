#include <stdio.h>

int main(void) {
    int i = 0;
    while (i<=10) {
        printf("i vaut %d\n", i++);// ne pas oublier d'incrémenter la variable
		//...d'itération manuellement dans une boucle while
    }
    return 0;
}