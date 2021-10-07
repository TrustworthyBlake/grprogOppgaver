#include<stdio.h>

int main() {
    
    char tegn1 = 'F', 
        tegn2 = 'H';

    float flyt1 = 15.52f, 
            flyt2 = 451.87f;
    
    printf("%.2f %.2f %c %c\n", flyt2, flyt1, tegn2, tegn1);
    printf("%e\n", flyt2);
    printf("%i %i\n", (int) flyt1, (int) flyt2);
    printf("%i\n", tegn1);
    printf("%i\n", 'b');

    return 0;
}