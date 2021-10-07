#include<stdio.h>

int main() {
    const int ANTALL = 17;

    int tall1 = 15,
        tall2 = 26,
        tall3 = 7,
        svar;

    svar = (tall1 + tall2) * tall2 * ANTALL;
    printf("%i\n", svar);
    svar += tall1;
    printf("%i\n", svar);
    svar -= ANTALL;
    printf("%i\n", svar);

    printf("Tall1 før = %i\n", tall1);
    tall1++; ++tall1; tall1++;
    printf("Tall1 etter = %i\n", tall1);
    printf("Tall2 før = %i\n", tall2);
    tall2--; --tall2; --tall2; tall2--;
    printf("Tall2 etter = %i\n", tall2);
    printf("%i\n", (tall1 * tall2) - ANTALL);

    
    return 0;
}