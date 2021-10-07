#include<stdio.h>

int main() {

    int x = 2;
    float y = 15.66;
    char z = 'X';
    const char TEKST[] = {"Biggus Dickus"};
    char str[100];

    /*printf("char var z = %c\n", z);
    printf("Skriv inn en bokstav: \n");
    z = getchar();
    printf("char var z = %c\n", z);*/
    printf("Skriv noe: ");
    fgets(str, sizeof(str), stdin);
    printf("%i\n", (int) sizeof(str));
    printf("Du skrev: %s\n", str);
    printf("float var y = %.2f and str contains = %s\n", y, str);
    printf("Skriv inn string og float: ");
    scanf("%s %f", str, &y);
    printf("\nDu skrev: %s og satt float y til = %.2f\n", str, y);

    return 0;
}