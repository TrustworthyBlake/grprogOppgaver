#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ARRLEN = 20;
char randomizeChar();

int main() {
    int arr[ARRLEN];
    int *arrPeker;
    arrPeker = &arr[0];
    char str[ARRLEN], *strPeker, *strPekerCopy;
    strPeker = &str[0];
    strPekerCopy = strPeker;
    srand(time(NULL));

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {  // Fyller opp arr
        arr[i] = i + 5;
    }
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {  // Skriver ut verdier fra arr
        printf("\nU / peker: %i", arr[i]);
    }
    printf("\n\n");
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        *arrPeker = 2 * *arrPeker;
        arrPeker++;
    }

    for (int i = sizeof(arr) / sizeof(int); i > 0; i--) {  // Skriver ut verdier fra arr
        arrPeker--;
        printf("\nM / peker: %i", *arrPeker);
    }
    printf("\n\n");

    for (int i = 0; i < sizeof(str) / sizeof(char); i++) {
        str[i] = randomizeChar();
    }

    for (int i = 0; i < sizeof(str) / sizeof(char); i++) {
        printf("\n%c", str[i]);
    }
    printf("\n\n");

    while (*strPeker != '\0') {
        if (*strPeker == 'C') {
            *strPeker = 'X';
        } else if (*strPeker == 'E') {
            *strPeker = '8';
        }
        strPeker++;
    }
    strPeker = strPekerCopy;
    while (*strPeker != '\0')
    {
        printf("\n%c", *strPeker);
        strPeker++;
    }
    printf("\n\n");
    
}

char randomizeChar() {
    char x;
    int max = 4, min = 0;
    int r = rand() % ((max + 1) - min) + min;

    switch (r) {
        case 0:
            x = 'A';
            break;
        case 1:
            x = 'B';
            break;
        case 2:
            x = 'C';
            break;
        case 3:
            x = 'D';
            break;
        case 4:
            x = 'E';
            break;

        default:
            printf("\nSum ting went wong");
            break;
    }
    return x;
}