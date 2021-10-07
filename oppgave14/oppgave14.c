#include<stdio.h>

void oppgave14();
void oppgave14_alt();

int main() {
    
    //oppgave14();
    oppgave14_alt();


    return 0;
}

void oppgave14(){
    int heltall[100], 
        i = 0, 
        input = 0, 
        antall = 0;

    float gjsnitt = 0.f, 
        totalsum = 0.f;

    do
    {
        printf("\nSkriv inn et heltall (avsluttes med 0 eller negativt tall): ");
        scanf("%i", &input);
        if (input > 0)
        {
            heltall[i] = input;
            i++;
        }      

    } while (input > 0);
    
    //antall = sizeof(heltall)/sizeof(heltall[0]);
    antall = i;

    for (int x = 0; x < antall; x++)
    {
       totalsum += heltall[x];
    }
     
    gjsnitt = totalsum / antall;

    printf("\nAntall elementer lest inn = %i", antall);
    printf("\nSummen av alle tallene er = %.2f", totalsum);
    printf("\nGjennomsnittet av alle tallene er = %.2f\n", gjsnitt);
}

void oppgave14_alt(){
    int totsum = 0, 
        antall, 
        tall;
    float gjsnitt;

    do
    {
        printf("\nSkriv inn et heltall (avsluttes med 0 eller negativt tall): ");
        scanf("%i", &tall);
        if (tall > 0)
        {
            totsum += tall;
            antall++;
        }        
    } while (tall > 0);

    gjsnitt = (float)totsum / antall;
    
    printf("\nAntall elementer lest inn = %i", antall);
    printf("\nSummen av alle tallene er = %i", totsum);
    printf("\nGjennomsnittet av alle tallene er = %.2f\n", gjsnitt);
}