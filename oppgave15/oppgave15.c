#include<stdio.h>

int main( ) {

    int tall1, tall2;
    char x;

    do
    {
        printf("\nSkriv inn to heltall: ");
        scanf("%i %i", &tall1, &tall2);
        printf("\n%i + %i = %i", tall1, tall2, tall1 + tall2);
        printf("\n%i - %i = %i", tall1, tall2, tall1 - tall2);
        printf("\n%i * %i = %i", tall1, tall2, tall1 * tall2);
        printf("\nOnsker du å gjore operasjonen en gang til? (j/N): ");
        scanf(" %c", &x);
    } while (x != 'n' && x != 'N');    

    return 0;
}