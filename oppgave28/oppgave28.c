#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Ansatt {
    int ansattNr;
    char navn[80];
    float lonn;
};

void skriv(int nr, struct Ansatt anst);

int main() {
    struct Ansatt ansatt, ansatt2, ansattTmp;
    ansatt.ansattNr = 102;
    strcpy(ansatt.navn, "Tore Paa Sporet");
    ansatt.lonn = 550;

    printf("\nSkriv ansatt nr: ");
    scanf("%i", &ansatt2.ansattNr);
    printf("\nSkriv navn: ");
    scanf(" %s", ansatt2.navn);
    printf("\nSkriv inn lonn: ");
    scanf("%f", &ansatt2.lonn);

    skriv(1, ansatt);
    skriv(2, ansatt2);

    ansattTmp = ansatt;
    ansatt = ansatt2;
    ansatt2 = ansattTmp;

    skriv(1, ansatt);
    skriv(2, ansatt2);
}

void skriv(int nr, struct Ansatt anst) {
    printf("\n%i", nr);
    printf("\n%i", anst.ansattNr);
    printf("\n%s", anst.navn);
    printf("\n%f\n", anst.lonn);
}