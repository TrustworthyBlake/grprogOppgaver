#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXANTALL = 100;

int hentVerdi(int tall[], int numOfElem, int* ptrMin, int* ptrMax);

int main() {
    int min, max;

    int innTall[MAXANTALL];
    int i = 0;
    char tmp[MAXANTALL], *ptr;

    do {
        printf("\nSkriv inn tall (n/N for stop): ");
        scanf("%s", tmp);
        //if()
        innTall[i] = strtol(tmp, &ptr, 10);
        i++;

    } while (tmp[0] != 'n' &&  tmp[0] != 'N');

    hentVerdi(innTall, i-1, &min, &max);

    printf("\nMinsteverdi = %i\nStorsteverdi = %i\n", min, max);

    return 0;
}

int hentVerdi(int tall[], int numOfElem, int * ptrMin, int * ptrMax) {
    int min = tall[0], max = 0;
    for (int i = 0; i < numOfElem; i++) {
        printf("\n%i", i);
        if (min > tall[i]) {
            min = tall[i];
            *ptrMin = min;
        }
        if (max < tall[i]) {
            max = tall[i];
            *ptrMax = max;
        }
    }
}