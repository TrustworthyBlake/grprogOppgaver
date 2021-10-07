#include<stdio.h>

int main() {
    
    int tall1[5],
        tall2[] = {6, 2, 10, 12, 19, 3, 7};

    char tekst[5],
        navn[] = {"Lars Hansen"},
        adresse[] = {"Ringgata 111"};

    tall1[0] = 13;
    tall1[1] = 67;

    tall1[2] = tall1[0] + tall1[1];
    printf("%i\n", tall1[2]);
    tall1[2] /= 2; 
    printf("%i\n", tall1[2]);
    tall1[3] = tall2[0] + tall2[1] + tall2[2] + tall2[3];
    tall1[4] = tall2[4] + tall2[5] + tall2[6];
    printf("%i %i\n", tall1[3], tall1[4]);
    tall1[2]++; tall1[2]++; tall1[2]++; tall1[2]++; 
    printf("%i\n", tall1[2]);

    tekst[1] = 'A';
    tekst[3] = 'E';

    tekst[0] = navn[5];
    tekst[2] = navn[0];

    printf("Kua har %c%c%c%c\n", tekst[0],tekst[1],tekst[2],tekst[3]);
    printf("%c%c%c\n", adresse[9], adresse[10], adresse[11]);
    printf("%s\n", navn);
    printf("%s\n", adresse);
    
    return 0;
}