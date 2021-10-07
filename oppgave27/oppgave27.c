#include <stdbool.h>
#include <stdio.h>

const int 
    STRLEN = 80,
    MAXPERSONER = 50;

int lesTall(const int min, const int maks);
void lesTekst(char str[]);

struct Person {
    char navn[80];
    int alder;
    float vekt;
};

int main() {
    int 
        ant, 
        i = 0,
        eldstTmp = 0,
        eldst = 0,
        totAlder = 0;
    float 
        gjsnittVekt = 0.0f;
    struct Person person[MAXPERSONER];

    printf("\nHvor mange onsker du aa legge inn?: ");
    ant = lesTall(1, 50);

    do {
        printf("\nSkriv inn navn: ");
        scanf(" %s", person[i].navn);
        lesTekst(person[i].navn);
        printf("\nSkriv inn alder: ");
        person[i].alder = lesTall(0, 150);
        printf("\nSkriv inn vekt: ");
        person[i].vekt = lesTall(1, 500);
        i++;
    } while (i < ant);

    for (int i = 0; i < ant; i++)
    {
        totAlder += person[i].alder;  
        gjsnittVekt += person[i].vekt;
        if (person[i].alder > eldstTmp)
        {
            eldst = i;
            eldstTmp = person[i].alder;
        }
        
    }
    gjsnittVekt = gjsnittVekt / ant;

    printf("\nTotal samlet alder for alle: %i", totAlder);
    printf("\nGjennomsntt vekt: %.f", gjsnittVekt);
    printf("\n\nID nr: %i\nNavn: %s\nAlder: %i\n", eldst + 1, person[eldst].navn, person[eldst].alder);
    
    return 0;
}

int lesTall(const int min, const int maks) {
    int tall;
    do {
        //printf("\nSkriv inn et tall mellom %i - %i: ", min, maks);
        scanf("%i", &tall);
    } while (tall < min || tall > maks);
    return (float)tall;
}

void lesTekst(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
            i++;
        } else {
            printf("\nUlovlig tegn!");
            printf("\nSkriv inn paa nytt: ");
            scanf(" %s", str);
            i = 0;
        }
    }
}