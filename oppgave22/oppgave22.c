#include <stdio.h>

void lagFirkant(int bredde, int hoyde);

int main() {
    int b, h;
    char restart;
    do
    {
        printf("\nSkriv inn bredde og hoyde: ");
        scanf("%i %i", &b, &h);
        lagFirkant(b, h);
        printf("\nKjor programmet paa nytt? (j/N): ");
        scanf(" %c", &restart);
    } while (restart == 'j' || restart == 'J');
    
    return 0;
}

void lagFirkant(int bredde, int hoyde) {
    for (int i = 0; i < hoyde; i++) {
        if (i == 0 || i + 1 == hoyde) {
            for (int j = 0; j < bredde; j++) {
                printf("*");
            }
        } else {
            for (int k = 0; k < bredde; k++) {
                if (k == 0 || k + 1 == bredde) {
                    printf("*");
                } else
                    printf(" ");
            }
        }
        printf("\n");
    }
}