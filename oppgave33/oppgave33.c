#include <stdio.h>

int finnLengde(const char* tp);
char* finnLengsteTekst(const char* tp, const char* tp2);

int main() {
    char arr[] = {"sadsad"}, arr2[] = {"jeg er den lengste"};
    char* pkr;
    printf("\n%i\n", finnLengde(arr));
    pkr = finnLengsteTekst(arr, arr2);
    printf("\n%s\n", pkr);
    //printf("\n\n%s\n\n", finnLengsteTekst(arr, arr2));
    return 0;
}

int finnLengde(const char* tp) {
    int i = 0;
    while (*tp != '\0') {
        i++;
        tp++;
    }
    return i;
}

char* finnLengsteTekst(const char* tp, const char* tp2) {
    return (finnLengde(tp) < finnLengde(tp2)) ? tp2 : tp; 
}