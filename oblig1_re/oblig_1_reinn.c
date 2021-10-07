/**
  *   Program losning paa Oblig 1, reinnlevering grprog Host 2021.
  *
  *   Programmet leser inn tittel, antall sider og sjanger for 2 boker
  *   naar brukeren er ferdig med aa skrive inn informasjon om bokene skrives
  *   disse dataene ut pluss bok id/nr til console / terminal.
  * 
  *   @file         oblig_1_reinn.c
  *   @date         23.09.2021
  *   @version      v2
  *   @author       Andreas Blakli
  */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>     // atoi
#include <string.h>     // strcspn

const int
    STRLEN = 100,     ///<  Maks tekst lengde / storrelse som brukes i array
    MAXANTBOKER = 2;  ///<  Maks antall boker
                      // Oppgaven ber om 2 boker, kan endres til et annet tall for
                      //       aa lese inn flere boker
                      //  NB!!! Da maa char bok1 bok2 array'ene endres
/**
 *  Hovedprogrammet:
 */
int main() {
    char
        bok1[STRLEN],  // Tittel paa boker
        bok2[STRLEN],
        sjanger[MAXANTBOKER],
        tmp[STRLEN],  // For sjanger char, toupper()
        restart;

    int
        sider[MAXANTBOKER],
        totBoker,
        totSider;

    do {
        totBoker = 0;  // Initialiserer verdiene til 0 pga. do lokka
        totSider = 0;
        restart = 'n';

        for (int i = 0; i < MAXANTBOKER; i++) {  // For lokke for innlesning av bok data
            printf("\nSkriv inn tittel paa bok %i: ", i + 1);
            if (i < 1) {                     // Gjort på denne maaten fordi oppgaven
                                             //      spesifikt ber om 2 array'er
                fgets(bok1, STRLEN, stdin);  // Legger inn string til char array bok1
                bok1[strcspn(bok1, "\n")] = '\0'; // Fjerner newLine fra char arr
            } else
                fgets(bok2, STRLEN, stdin);  // Legger inn string til char array bok2
                bok2[strcspn(bok2, "\n")] = '\0'; // Fjerner newLine fra char arr
            do {                             // Looper helt til sider ikke er null
                printf("\nSkriv inn antall sider boken har: ");
                fgets(tmp, STRLEN, stdin);  // Leser inn string til tmp char array
                sider[i] = atoi(tmp);       // Gjør om string til int, legger inn
                                            //             i sider array
            } while (sider[i] == 0);
            printf("\nSkriv inn sjanger(B = Biografi, F = Fiksjon, T = Thriller): ");
            fgets(tmp, STRLEN, stdin);     // Leser inn string til tmp char array
            sjanger[i] = toupper(tmp[0]);  // Gjor om til stor bokstav, legges inn i
                                           //      sjanger array
        }

        for (int i = 0; i < MAXANTBOKER; i++) {  // For lokke for printing av data som ble
                                                 //      lest inn
            printf("\n\nBok %i:", i + 1);
            if (i < 1) {  // Printer ut tittel paa bok basert på
                          //      verdien til i
                printf("\nTittel: %s", bok1);
            } else
                printf("\nTittel: %s", bok2);
            printf("\nAntall sider: %i", sider[i]);  // Printer ut ant sider
            printf("\nSjanger: %c", sjanger[i]);     // Printer ut sjanger til bok
            totBoker++;                              // Adderes med 1 for hver gang lokka
                                                     //      kjores
            totSider += sider[i];                    // Adderer nummeret til totSider hver
                                                     //      gang lokka kjorer
        }
        printf("\n\nBoker lest: %i", totBoker);       // Printer ut total antall av boker
                                                      //      lagt inn
        printf("\nSider lest totalt: %i", totSider);  // Printer ut total antall av sider
                                                      //      for alle bokene

        printf("\n\nKjor programmet på nytt? (j/N): ");
        fgets(&restart, STRLEN, stdin);

    } while (restart == 'j' || restart == 'J');  // Kjorer igjen hvis restart er j
                                                 //      eller J
    return 0;
}
