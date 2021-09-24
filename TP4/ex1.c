#include <stdio.h>
#include <string.h>

//TP4ex1

int main(int argc, char* argv[])
{
    int i;
    int somme = 0;
    printf("Valeur de argc: %d\n", argc);
    for (i=0; i<argc; i++)
    {
        printf("Argu. n° %d: %s (nb de chars: %d)\n", i, argv[i], (int)strlen(argv[i]));
        if (i >= 1) {
            somme = somme + atoi(argv[i]);
        }
    }
    printf("somme: %d\n", somme);
    return 0;
}
