#include <stdio.h>

void skrivTid(int time, int min, int sek);  // Prototype

int main() {
    skrivTid(11, 9, 6);
    skrivTid(0,24,59);
    return 0;
}

void skrivTid(int time, int min, int sek) {
    if (time <= 9) {
        printf("0%i::", time);
    }else printf("%i::", time);

    if (min <= 9) {
        printf("0%i::", min);
    }else printf("%i::", min);

    if (sek <= 9) {
        printf("0%i\n", sek);
    }else printf("%i\n", sek);

    int totSek = (time * 3600) + (min * 60) + sek;
    printf("Totalt i sekunder: %i\n", totSek);
}