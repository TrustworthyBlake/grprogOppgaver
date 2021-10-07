#include <stdbool.h>
#include <stdio.h>
#include <string.h>

const char STRLEN = 100;

char *fjernMellomromString(char *str);

int main() {
    int tlfNummer, num;
    bool feil = false;
    char arr[STRLEN], arrUt[STRLEN];

    printf("\nSkriv inn tlfnummer: ");
    scanf("%s", arr);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        switch (arr[i]) {
            case '0':
                strcat(arrUt, "Null");
                break;
            case '1':
                strcat(arrUt, "En");
                break;
            case '2':
                strcat(arrUt, "To");
                break;
            case '3':
                strcat(arrUt, "Tre");
                break;
            case '4':
                strcat(arrUt, "Fire");
                break;
            case '5':
                strcat(arrUt, "Fem");
                break;
            case '6':
                strcat(arrUt, "Seks");
                break;
            case '7':
                strcat(arrUt, "Syv");
                break;
            case '8':
                strcat(arrUt, "Aatte");
                break;
            case '9':
                strcat(arrUt, "Ni");
                break;
            case ' ':
                break;
            case '\0':
                break;
            default:
                printf("\nErr: Illeagal input!\n");
                feil = true;
                break;
        }
        if (feil || arr[i] == '\0') {
            break;
        }
        if (i < strlen(arr)-1 ) strcat(arrUt, "-");
        
    }
    if (!feil) {
        printf("\n%s\n", arrUt);
    }
}

char *fjernMellomromString(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
    return str;
}