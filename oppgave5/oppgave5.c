#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

void oppgave5a();   // Funksjon prototype
void oppgave5b();   // Funksjon prototype
int * toArray(int number);

int main(){
    printf("oppgave 5\n");

    int x = -10;
    int tmpx = -x;
    printf("Tall= %d\n", tmpx);

    // Starter (caller) funksjonene
    oppgave5a();
    oppgave5b();
    return 0;
}

void oppgave5a(){
    int lengde, hoyde, bredde;
    lengde = 8;
    hoyde = 12;
    bredde = 16;

    int volum = lengde * hoyde * bredde;    // Regner ut volumet
    printf("Oppgave 5a\n");
    printf("Volumet av prismen er = %d \n", volum); // Printer ut verdien
}

void oppgave5b(){
    const int num = 19600406;
    const int finnNum = 1960;

    int tempNum = num >= 0 ? num : -num;    // Ternary operator, hvis num er negativt så blir det gjort om til posetivt.
    int tempNumFinn;
    bool harFunnet = false;

    printf("Oppgave 5b\n");
    int *numOfElements, *numOfElements2;
    int *p, *p2;
    p, numOfElements = toArray(num);
    p2, numOfElements2 = toArray(finnNum);

    //int numOfElements = sizeof(p)/sizeof(p[0]);

    for (int i = 0; i < &numOfElements; ++i)
    {
        printf("%i\n", numOfElements);
    }
    

    /*

    while (tempNum != 0 && !harFunnet)
    {
        tempNumFinn = tempNum % 10;
        tempNum = tempNum / 10;

        if (tempNumFinn == finnNum)
        {
            printf("Tallet: %d inneholder nummeret: %d\n", num, finnNum);
            harFunnet = true;
        }
        
    }
    if (!harFunnet)
    {
        printf("Tallet: %d inneholder ikke nummeret: %d\n", num, finnNum);
    }
        */

}

int * toArray(int number)
{
    int n = log10(number) + 1;
    int i;
    int numOfElements = 0;
    int *numberArray = calloc(n, sizeof(int));
    for ( i = 0; i < n; ++i, number /= 10 )
    {
        numberArray[i] = number % 10;
        printf("arr pos= %i val= %i\n", i, numberArray[i]);
    }
    numOfElements = sizeof(numberArray)/sizeof(numberArray[0]);
    return numberArray, numOfElements;
}