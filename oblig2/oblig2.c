/**
  *   Program losning paa Oblig 2, grprog Host 2021.
  * 
  *   Programmet holder styr over banene i en frisbeegolfpark. 2 baner er lagt inn.
  *   Programmet lar brukeren legge til en ny bane med relevante data for banen,
  *   skrive ut alle baner samt all tilhorende data for hver bane og 
  *   avslutte programmet.
  * 
  *   @file         oblig2.c
  *   @date         29.09.2021
  *   @version      v1
  *   @author       Andreas Blakli
  */

#include <ctype.h>  // toupper
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>  // atoi
#include <string.h>  // strcpy

const int
    MAXBANER = 18,             ///< Makes antall baner
    STRLEN = 100,              ///< Maks tekstlengde
    ANTEKSISTERENDEBANER = 2;  ///< Antall baner som eksisterer fra for

void skrivMeny();
bool lesKommando(char baneStr[MAXBANER][STRLEN], int *baneLen,
                 int *banePar, int *antBaner, bool *baneOB);
void lesTekst(char *str);
void leggTilBane(char baneStr[MAXBANER][STRLEN], int *baneLen,
                 int *banePar, int *antBaner, bool *baneOB);
void skrivUtAlleBaner(char baneStr[MAXBANER][STRLEN], int *baneLen,
                      int *banePar, int *antBaner, bool *baneOB);

/**
 * Hovedprogrammet:
 */
int main() {
    char
        baneBeskrivelse[MAXBANER][STRLEN];  // Beskrivelse av banene
    int
        baneLengde[MAXBANER],  // Banens lengde i meter
        banePar[MAXBANER],     // Forventet antall kast(par) for hver enkelt bane
        antallBaner = 0;       // Antall regisrerte baner
    bool
        baneOB[MAXBANER],  // Har banen OB (out of bounds)
        fortsett;          // Fortsett programmet

    // Legger inn data for de 2 eksisterende banene
    for (int i = 0; i < ANTEKSISTERENDEBANER; i++) {
        if (i == 0) {
            strcpy(baneBeskrivelse[i], "foo");
            baneOB[i] = true;
        } else {
            strcpy(baneBeskrivelse[i], "bar");
            baneOB[i] = false;
        }
        baneLengde[i] = 25 * (i + 1);
        banePar[i] = 2 * (i + 1);
        antallBaner++;
    }
    // Lokka gaar helt til fortsett er false
    do {
        skrivMeny();
        fortsett = lesKommando(baneBeskrivelse, baneLengde,
                               banePar, &antallBaner, baneOB);
    } while (fortsett);

    return 0;
}

/**
 * Skriver meny valg i console / terminal.
 */
void skrivMeny() {
    printf("\n\nL = Legg til bane");
    printf("\nS = Se alle baner");
    printf("\nQ = Avslutt programmet\n");
}

/**
 * Leser inn brukervalg, aktiverer korresponderende
 * funksjoner baser paa brukervalg.
 * 
 * @param baneStr - 2D char array
 * @param baneLen - Peker til bane lengde array
 * @param banePar - Peker til bane par array
 * @param antBaner - Peker til antall baner
 * @param baneOB - Peker til out of bounds array
 * 
 * @return true eller false
 */
bool lesKommando(char baneStr[MAXBANER][STRLEN], int *baneLen,
                 int *banePar, int *antBaner, bool *baneOB) {
    char valg;
    bool fortsett = true;

    fgets(&valg, STRLEN, stdin);
    valg = toupper(valg);
    // Switchen styrer hvilken funksjon som blir "called" basert paa valg variablen
    switch (valg) {
        // Legg til bane
        case 'L':
            leggTilBane(baneStr, baneLen, banePar, antBaner, baneOB);
            break;
        // Skriv ut all data om alle baner
        case 'S':
            skrivUtAlleBaner(baneStr, baneLen, banePar, antBaner, baneOB);
            break;
        // Avslutt programmet
        case 'Q':
            printf("\nAvslutter programmet");
            fortsett = false;
            break;
        default:
            printf("\nUlovlig kommando!");
            break;
    }
    return fortsett;
}

/**
 * Sjekker string/char array for ulovlige tegn, hvis ulovlig
 * blir bruker bedt om aa skrive det inn paa nytt.
 * 
 * @param str - Peker til string / char array
 */
void lesTekst(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        // char er A til z ,-. 0 til 9 og mellomrom
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z'
                        || str[i] >= ',' && str[i] <= '9' || str[i] == ' ') {
            i++;
        } else {
            printf("\nUlovlig tegn!");
            printf("\nSkriv inn paa nytt: ");
            fgets(str, STRLEN, stdin);
            str[strcspn(str, "\n")] = '\0';
            i = 0;
        }
    }
}

/**
 * Legger til bane, bruker bes om aa skrive inn bane data,
 * innlest data blir lagt i sin korresponderende array.
 * 
 * @param baneStr - 2D char array
 * @param baneLen - Peker til bane lengde array
 * @param banePar - Peker til bane par array
 * @param antBaner - Peker til antall baner
 * @param baneOB - Peker til out of bounds array
 */
void leggTilBane(char baneStr[MAXBANER][STRLEN], int *baneLen,
                 int *banePar, int *antBaner, bool *baneOB) {
    char
        str[STRLEN],
        valg;
    int num;
    // Sjekker om maks antall baner er registert
    if (*antBaner < MAXBANER) {
        // Ber bruker om lengde paa bane, gaar helt til tall er >= 0
        do {
            printf("\nSkriv inn lengde paa bane nr.%i: ", *antBaner + 1);
            fgets(str, STRLEN, stdin);
            num = atoi(str);
        } while (str == 0 || num < 0);
        // Hvis tallet ikke er 0
        if (num != 0) {
            // Legger til lengden i array
            baneLen[*antBaner] = num;
            // Ber bruker om par paa banen, gaar helt til et lovlig
            //                      tall mellom 2 og 8 blir lest inn
            do {
                printf("\nSkriv inn par paa banen (2-8): ");
                fgets(str, STRLEN, stdin);
                num = atoi(str);
            } while (str == 0 || num < 2 || num > 9);
            // Legger til ant par i array
            banePar[*antBaner] = num;
            // Spor bruker om banen har OB, gaar helt til lest
            //                          inn char j/J eller n/N
            do {
                printf("\nHar banen out of bounds? (j/N): ");
                fgets(&valg, STRLEN, stdin);
                valg = toupper(valg);
                if (valg != 'J' && valg != 'N') {
                    printf("\nUlovlig tegn!");
                }
                if (valg == 'J') {
                    baneOB[*antBaner] = true;
                } else if (valg == 'N')
                    baneOB[*antBaner] = false;
            } while (valg != 'J' && valg != 'N');
            // Bruker bes om beskrivelse paa banen
            printf("\nSkriv inn bane beskrivelse: ");
            fgets(str, STRLEN, stdin);
            str[strcspn(str, "\n")] = '\0';
            // Caller lesTekst aa sjekker for ulovlige tegn
            lesTekst(str);
            // Legger inn stringen i baneBeskrivelse array'en
            strcpy(baneStr[*antBaner], str);
            *antBaner += 1;
        } else
            printf("\nBane lengde 0, gaar tilbake til meny");
    } else
        printf("\nMaks antall baner er registrert!");
}

/**
 * Skriver ut all data registret paa hver bane, totalt antall registrerte baner
 * og hvor mange kast for aa havne paa par til terminal/console.
 * 
 * @param baneStr - 2D char array
 * @param baneLen - Peker til bane lengde array
 * @param banePar - Peker til bane par array
 * @param antBaner - Peker til antall baner
 * @param baneOB - Peker til out of bounds array
 */
void skrivUtAlleBaner(char baneStr[MAXBANER][STRLEN], int *baneLen,
                      int *banePar, int *antBaner, bool *baneOB) {
    int antKast = 0;  // For summen for aa havne paa par

    // Gaar gjennom hver bane aa skriver ut all relevant data
    for (int i = 0; i < *antBaner; i++) {
        printf("\n\nBane nr.%i", i + 1);
        printf("\nLengde paa bane: %i", baneLen[i]);
        printf("\nPar: %i", banePar[i]);
        // Hvis out of bounds er i bruk paa banen
        if (baneOB[i]) {
            printf("\nMed OB");
        } else
            printf("\nUten OB");
        printf("\nBeskrivelse: %s", baneStr[i]);
        antKast += banePar[i];
    }
    printf("\n\nAntall baner: %i", *antBaner);
    printf("\nFor aa havne paa par brukes %i kast.", antKast);
}
