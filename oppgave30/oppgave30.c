#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tralle {
    bool utlaant;
    char navn[80];
    int tlf;
};

const int
    MAXTRALLER = 30,
    STRLEN = 80;
struct Tralle gTraller[30];
int gAntallUtlaant = 0;

int lesTall(const int min, const int maks);
void lesTekst(char str[]);
void oversikt();
void ledige();
void utlaan();
void innlevering();
void tellOppTraller();
void finnLaaner();
void skrivMeny();
bool lesKommando();
bool sammenlignStr(const char a[], const char b[]);

int main() {
    for (int i = 0; i < MAXTRALLER; i++) {
        gTraller[i].utlaant = false;
    }

    do {
        skrivMeny();
    } while (lesKommando());

    return 0;
}

int lesTall(const int min, const int maks) {
    int tall;
    do {
        scanf("%i", &tall);
    } while (tall < min || tall > maks);
    return tall;
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

void oversikt() {
    if (gAntallUtlaant > 0) {
        for (int i = 0; i < MAXTRALLER; i++) {
            if (gTraller[i].utlaant) {
                printf("\nTralle nr: %i", i + 1);
                printf("\nNavn: %s", gTraller[i].navn);
                printf("\nTlf nr: %i", gTraller[i].tlf);
            }
        }
    } else
        printf("\nIngen traller utlaant.");
}

void ledige() {
    if (gAntallUtlaant <= MAXTRALLER) {
        for (int i = 0; i < MAXTRALLER; i++) {
            if (!gTraller[i].utlaant) {
                printf("\nLedig tralle nr: %i", i + 1);
            }
        }

    } else
        printf("\nAlle traller utlaant.");
}

void utlaan() {
    int tralleNr = 0;
    char tmpStr[STRLEN];

    if (gAntallUtlaant <= MAXTRALLER) {
        printf("\nTralle nr: ");
        tralleNr = lesTall(1, MAXTRALLER) - 1;
        if (!gTraller[tralleNr].utlaant) {
            printf("\nSkriv inn navn: ");
            scanf("%s", gTraller[tralleNr].navn);
            //fgets(gTraller[tralleNr].navn, 256, stdin);
            lesTekst(gTraller[tralleNr].navn);
            printf("\nSkriv inn tlf nr: ");
            gTraller[tralleNr].tlf = lesTall(0, 99999999);
            gTraller[tralleNr].utlaant = true;
            tellOppTraller();
        } else
            printf("\nTralle nr: %i er allerde i bruk!", tralleNr + 1);
    } else
        printf("\nAlle traller utlaant.");
}

void innlevering() {
    int tralleNr = 0;
    if (gAntallUtlaant <= 0) {
        printf("\nIngen traller er utlaant!");
    } else {
        printf("\nSkriv inn tralle nr: ");
        tralleNr = lesTall(1, MAXTRALLER) - 1;
        if (gTraller[tralleNr].utlaant) {
            gTraller[tralleNr].utlaant = false;
            printf("\nLeiers navn: %s", gTraller[tralleNr].navn);
            tellOppTraller();
        } else
            printf("\nTralle er ikke registrert utlaant!");
    }
}

void tellOppTraller() {
    gAntallUtlaant = 0;
    for (int i = 0; i < MAXTRALLER; i++) {
        if (gTraller[i].utlaant) {
            gAntallUtlaant++;
        }
    }
}

void finnLaaner() {
    bool leierMerEnnEn = false;
    char tmpNavn[STRLEN];
    printf("\nSkriv inn navn: ");
    scanf(" %s", tmpNavn);
    lesTekst(tmpNavn);
    for (int i = 0; i < MAXTRALLER; i++) {
        if (sammenlignStr(gTraller[i].navn, tmpNavn)) {
            printf("\nLeier tralle nr: %i", (i + 1));
            leierMerEnnEn = true;
        }
    }
    if (!leierMerEnnEn) {
        printf("\n%s leier ingen traller.", tmpNavn);
    }
}

void skrivMeny() {
    printf("\n");
    printf("\nO = Oversikt over traller.");
    printf("\nL = Ledige traller.");
    printf("\nU = Utlaan av tralle.");
    printf("\nI = Innlevering av tralle.");
    printf("\nF = Finn laaner av tralle.");
    printf("\nA = Avslutt programm.\n");
}

bool lesKommando() {
    char valg;
    bool fortsett = true;
    scanf(" %c", &valg);
    valg = toupper(valg);

    switch (valg) {
        case 'O':
            oversikt();
            break;
        case 'L':
            ledige();
            break;
        case 'U':
            utlaan();
            break;
        case 'I':
            innlevering();
            break;
        case 'F':
            finnLaaner();
            break;
        case 'A':
            fortsett = false;
            break;

        default:
            break;
    }
    return fortsett;
}

bool sammenlignStr(const char a[], const char b[]) {
    bool erLik = true;
    for (int i = 0; i < STRLEN; i++) {
        if (a[i] != b[i]) erLik = false;
        if (a[i] == '\0') break;        
    }
    return erLik;
}