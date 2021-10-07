#include<stdio.h>

int main(){
    int tall1, 
    tall2, 
    tall3, 
    sum, 
    kvadratSum;
    
    float flyt1, 
    flyt2, 
    gjsnittSum, 
    gjsnittKvadrat;

    tall1 = 10,
    tall2 = 20,
    tall3 = 30;
    flyt1 = 1.5,
    flyt2 = 2.5;

    sum = tall1 + tall2 + tall3;
    printf("%i + %i + %i = %i\n", tall1, tall2, tall3, sum);
    gjsnittSum = sum / 3.0f;
    printf("Gjennomsnitt sum = %f\n", gjsnittSum);
    kvadratSum = (tall1 * tall1) + (tall2 * tall2) + (tall3 * tall3);
    printf("Kvadrat sum int = %i\n", kvadratSum);
    gjsnittKvadrat = kvadratSum / 3.0f;
    printf("Gjennomsnitt kvadrat sum = %f\n", gjsnittKvadrat);
    printf("Gjennomsnitt av flyt1 og flyt2 = %f\n", (flyt1 + flyt2) / 2.0f); // Så lenge regnestykket består av en float kan man dele med int.
}