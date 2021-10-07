#include <stdio.h>

#define STRLEN 80

struct Person {
    char
        navn[STRLEN],
        skoleklasse;
    int skonummer;
};

int main() {
    struct Person p, *pPeker;
    pPeker = &p;
    char *tmpP, tmp;
    tmpP = &tmp;

    printf("\nNavn: ");
    scanf("%s", pPeker->navn);
    printf("\nKlasse a - h: ");
    do {
        scanf(" %c", tmpP);
    } while (*tmpP < 'A' || *tmpP > 'H' && *tmpP < 'a' || *tmpP > 'h');
    pPeker->skoleklasse = *tmpP;
    printf("\nSko nr: ");
    scanf("%i", &pPeker->skonummer);
    printf("\n%s\n%c\n%i\n", pPeker->navn, pPeker->skoleklasse, pPeker->skonummer);

    return 0;
}