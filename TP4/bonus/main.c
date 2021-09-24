#include <stdio.h>
#include "stringy.h"
#include <string.h>
#include <time.h>

int main() {
    //////////////////////////////////////////////////////////////////////////////
    /*strlen clone*/
    char sentenceA[] = "Hallo, World!";
    char sentenceB[] = "Hello, World!";
    float temps;

    clock_t begin = clock();
    for (int i = 0; i < 10000000; ++i) {
        strlen_y(sentenceA);
    }
    clock_t end = clock();
    temps = (float) (end - begin) / CLOCKS_PER_SEC;

    printf("strlen_y took %f seconds to iterate 10,000,000 times.\n", temps);
    //////////////////////////////////////////////////////////////////////////////
    begin = clock();
    for (int i = 0; i < 10000000; ++i) {
        strlen(sentenceA);
    }
    end = clock();
    temps = (float) (end - begin) / CLOCKS_PER_SEC;

    printf("strlen took %f seconds to iterate 10,000,000 times.\n", temps);
    //////////////////////////////////////////////////////////////////////////////
    /*strcmp clone*/
    begin = clock();
    for (int i = 0; i < 10000000; ++i) {
        strcmp_y(sentenceA, sentenceB);
    }
    end = clock();
    temps = (float) (end - begin) / CLOCKS_PER_SEC;

    printf("strcmp_y took %f seconds to iterate 10,000,000 times.\n", temps);
    //////////////////////////////////////////////////////////////////////////////
    begin = clock();
    for (int i = 0; i < 10000000; ++i) {
        strcmp(sentenceA, sentenceB);
    }
    end = clock();
    temps = (float) (end - begin) / CLOCKS_PER_SEC;

    printf("strcmp took %f seconds to iterate 10,000,000 times.\n", temps);

    //////////////////////////////////////////////////////////////////////////////
    /*strcpy clone*/
    char sentenceCpy[20] = "what";
    begin = clock();
    for (int i = 0; i < 10000000; ++i) {
        strcpy_y(sentenceCpy, sentenceB);
    }
    end = clock();
    temps = (float) (end - begin) / CLOCKS_PER_SEC;

    printf("strcpy_y took %f seconds to iterate 10,000,000 times.\n", temps);
    //////////////////////////////////////////////////////////////////////////////
    begin = clock();
    for (int i = 0; i < 10000000; ++i) {
        strcpy(sentenceCpy, sentenceB);
    }
    end = clock();
    temps = (float) (end - begin) / CLOCKS_PER_SEC;

    printf("strcpy took %f seconds to iterate 10,000,000 times.\n", temps);
    //////////////////////////////////////////////////////////////////////////////
    /*strcat clone*/
    char sentenceCat1[10000] = "_";
    char sentenceCat2[10000] = "-";
    begin = clock();
    for (int i = 0; i < 9999; ++i) {
        strcat_y(sentenceCat1, sentenceCat2);
    }
    end = clock();
    temps = (float) (end - begin) / CLOCKS_PER_SEC;

    printf("strcat_y took %f seconds to iterate 9999 times.\n", temps);
    //////////////////////////////////////////////////////////////////////////////
    char sentenceCat3[10000] = "_";
    begin = clock();
    for (int i = 0; i < 9999; ++i) {
        strcat(sentenceCat3, sentenceCat2);
    }
    end = clock();
    temps = (float) (end - begin) / CLOCKS_PER_SEC;

    printf("strcat took %f seconds to iterate 9999 times.\n", temps);
    return 0;
}
