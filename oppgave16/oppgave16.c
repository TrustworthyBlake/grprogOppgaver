#include <ctype.h>
#include <stdio.h>

const int
    MINVERDI = 1,
    MAXVERDI = 10000,
    TALLLEN = 5,
    CHARLEN = 10;

int main() {
    int
        arr[5],
        tall,
        i = 0;
    char
        txtArr[10],
        tmp;

    do {
        printf("\nSkriv inn et tall: ");
        scanf("%i", &tall);
        if (tall >= MINVERDI && tall <= MAXVERDI) {
            arr[i] = tall;
            i++;
        } else
            printf("\nUlovlig tall! Maa vaare mellom %i og %i", MINVERDI, MAXVERDI);

    } while (i < TALLLEN);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("\n%i", arr[i]);
    }

    i = 0;
    do {
        printf("\nSkriv inn en bokstav: ");
        scanf(" %c", &tmp);

        if (tmp >= 'A' && tmp <= 'Z' || tmp >= 'a' && tmp <= 'z') {
            txtArr[i] = toupper(tmp);
            i++;
        } else
            printf("\nUlovlig tegn!");
    } while (i < CHARLEN);

    for (int i = 0; i < sizeof(txtArr) / sizeof(txtArr[0]); i++) {
        printf("\n%c", txtArr[i]);
    }

    return 0;
}