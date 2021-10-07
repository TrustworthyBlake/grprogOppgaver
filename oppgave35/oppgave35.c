#include <stdio.h>
#include <stdlib.h>

const int ALLOC_SZ = 25;

int main() {
    int *numsPtr;
    char *strPtr;
    numsPtr = (int*)malloc(ALLOC_SZ * sizeof(int));
    strPtr = (char*)malloc(ALLOC_SZ * sizeof(char));

    if (numsPtr == NULL) {
        printf("\nError mem alloc! Exiting\n");
        exit(0);
    }

    for (int i = 0; i < ALLOC_SZ; i++) {
        //*numsPtr = i;
        //numsPtr++;
        numsPtr[i] = i + 1;
    }

    for (int i = 0; i <= ALLOC_SZ; i++) {
        //numsPtr--;
        //printf("\n%i", *numsPtr);
        printf("\n%i\n", numsPtr[i]);
    }
    free(numsPtr);
    for (int i = 0; i < ALLOC_SZ - 1; i++) {
        strPtr[i] = (char) ('A' + i);
    }
    strPtr[ALLOC_SZ - 1] = '\0';
    
    printf("\n%s\n", strPtr);
    free(strPtr);
    return 0;
}