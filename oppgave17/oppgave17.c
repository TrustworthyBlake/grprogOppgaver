#include <stdio.h>

const int
    LOVLIGDIST5 = 500,
    LOVLIGDIST15 = 1500,
    LOVLIGDIST30 = 3000,
    LOVLIGDIST50 = 5000,
    MAXLOPERE = 10,
    ANTTID = 3;             // i.e. minutt::sekund::hundredel

int main() {
    int
        distanse,
        ant500m,
        antLopere,
        tid[10][3],
        tmp,
        j;

    float poeng;

    char restart;

    do {
        restart = 'n';
        do {
            printf("\nSkriv inn distanse: ");
            scanf("%i", &distanse);
        } while (distanse != LOVLIGDIST5 && distanse != LOVLIGDIST15 && distanse != LOVLIGDIST30 && distanse != LOVLIGDIST50);

        ant500m = distanse / LOVLIGDIST5;
        do {
            printf("\nSkriv inn ant lopere (maks %i): ", MAXLOPERE);
            scanf("%i", &antLopere);
        } while (antLopere >= (MAXLOPERE) || antLopere <= 0);

        for (int i = 0; i < antLopere; i++) {
            printf("\nSkriv inn tid til loper %i i minutt::sekund::hundredel: ", i + 1);
            j = 0;
            do {
                scanf("%i", &tid[i][j]);
                if (tid[i][j] >= 0) {
                    j++;
                }
            } while (tid[i][j] < 0 || j < ANTTID);
        }

        for (int i = 0; i < antLopere; i++) {
            poeng = ((tid[i][0] * 60.0f) + tid[i][1] + (tid[i][2] / 100)) / ant500m;
            printf("\nLoper %i har: %.3f poeng.", i + 1, poeng);
        }
        
        printf("\nKjor programmet paa nytt? (j/N): ");
        scanf(" %c", &restart);
    } while (restart == 'j' || restart == 'J');

    return 0;
}