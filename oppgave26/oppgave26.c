#include <stdio.h>

struct Dato {
    int dag, maaned, aar;
};

int main() {
    struct Dato dato, dato2;

    printf("\nSkriv inn dag::maaned::aar: ");
    scanf("%i%i%i", &dato.dag, &dato.maaned, &dato.aar);
    printf("\n2 Skriv inn dag::maaned::aar: ");
    scanf("%i%i%i", &dato2.dag, &dato2.maaned, &dato2.aar);

    if(dato.aar == dato2.aar) printf("\nDatoene er like\n");
    else if(dato.aar < dato2.aar) printf("\n%i\n", dato.aar);
    else printf("\n%i\n", dato2.aar);
}
