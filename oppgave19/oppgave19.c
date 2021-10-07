#include <stdio.h>

const int
    ARRLEN = 5,
    MAXANTALLINN = 20,
    MAXVERDI = 100,
    MINVERDI = 0;

int main() {
    int
        innTall[MAXANTALLINN],
        arr[] = {0, 0, 0, 0, 0},
        tall,
        teller = 0;

    do {
        //printf("\n%i", teller);
        printf("\nSkriv inn et tall (1 - 100): ");
        scanf("%i", &tall);

        if (tall > MINVERDI && tall < MAXVERDI ) {
            innTall[teller] = tall;
            teller++;
        }
    } while (teller < MAXANTALLINN);

    for (int i = 0; i < MAXANTALLINN; i++) {
        if (innTall[i] <= 20)
        {
            arr[0]++;
        }else if (innTall[i] <= 40)
        {
            arr[1]++;
        }else if (innTall[i] <= 60)
        {
            arr[2]++;
        }else if (innTall[i] <= 80)
        {
            arr[3]++;
        }else if (innTall[i] <= 100)
        {
            arr[4]++;
        }
    }
    printf("\nAntall tall i intervallet 1 - 20: %i", arr[0]);
    printf("\nAntall tall i intervallet 21 - 40: %i", arr[1]);
    printf("\nAntall tall i intervallet 41 - 60: %i", arr[2]);
    printf("\nAntall tall i intervallet 61 - 80: %i", arr[3]);
    printf("\nAntall tall i intervallet 81 - 100: %i", arr[4]);

    return 0;
}