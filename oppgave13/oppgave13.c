#include<stdio.h>

int main () {

    const int HOYDE = 4;
    const float PI = 3.141593;
    int radius = 0;
    float volum = 0.f;

    printf("Skriv inn radius (5-20): ");
    scanf("%i", &radius);
    if (radius >= 5 && radius <= 20)
    {
        //grunnflate = PI * HOYDE
        for (int i = 1; i <= radius; i++)
        {
            volum = PI * (i * i) * HOYDE;
            printf("Volum = %f ved radius = %i\n", volum, i);
        }
        
    }else printf("Nein! 5 - 20\n");    

    return 0;
}