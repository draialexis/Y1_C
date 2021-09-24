#include <stdio.h>

int main() {

    float x, y, z;
    z = 0;
    y = 0;
    x = 0;

    printf("Donnez trois nombres a virgules:\n");
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &z);

    float avg;
    int avg_timesHund;
    float avg_twoDec;
    avg = (x + y + z) / 3;
    avg_timesHund = ((x + y + z) * 100) / 3;
    avg_twoDec = avg_timesHund / 100.0;

    printf("La moyenne est %f.\n", avg);
    printf("La moyenne est : %f\n", avg_twoDec);
    printf("La moyenne avec deux chiffres apres la virgule est %0.2f\n", avg);
    fflush(stdin);
    return 0;
}