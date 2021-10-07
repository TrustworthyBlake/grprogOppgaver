#include <stdio.h>

int main() {
    for (int i = 1; i <= 100; i++) {
        printf("%i", i);
        if (i % 2 == 0 && i != 1) {
            printf(" partall ");
        } else
            printf(" oddetall ");

        if (i % 5 == 0) {
            printf("\n");
        }
    }

    return 0;
}