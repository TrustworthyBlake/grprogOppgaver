#include <stdio.h>
#include <stdlib.h>

struct VarData {
    int
        dagNr,
        minTemp,
        maxTemp,
        nedbor;
    struct VarData *neste;
};

const int STRLEN = 80;

void lesData(FILE *innfil, struct VarData *dataPtr, struct VarData *dataListe, struct VarData *siste);
void visData(struct VarData *data);
void frigjorData(struct VarData *data, struct VarData *helperPtr);

int main() {
    FILE *innfil;
    innfil = fopen("meteorolog.dta", "r");
    struct VarData
        dataPtr,
        helperPtr,
        dataListe,
        siste;

    if (innfil != NULL) {
        lesData(innfil, &dataPtr, &dataListe, &siste);
    } else
        printf("\nFant ikke filen!");

    //helperPtr = dataPtr;
    while (&dataPtr != NULL) {
        visData(&dataPtr);
    }
    dataPtr = helperPtr;
    frigjorData(&dataPtr, &helperPtr);

    fclose(innfil);

    return 0;
}

void lesData(FILE *innfil, struct VarData *dataPtr, struct VarData *dataListe, struct VarData *siste) {
    dataListe = NULL;
    siste = NULL;
    int count = 0;
    int dag;
    fscanf(innfil, "%i", &dag);
    while (!feof(innfil)) {
        dataPtr = (struct VarData*)malloc(sizeof(struct VarData));
        dataPtr->neste = NULL;
        dataPtr->dagNr = dag;
        fscanf(innfil, "%i", &dataPtr->minTemp);
        fscanf(innfil, "%i", &dataPtr->maxTemp);
        fscanf(innfil, "%i", &dataPtr->nedbor);
        if (dataListe == NULL) {
            siste = dataPtr;
            dataListe = siste;
        } else {
            siste->neste = dataPtr;
            siste = dataPtr;
        }
        fscanf(innfil, "%i", &dag);
        count++;
    }
    printf("\n%i\n", count);
    *dataPtr = *dataListe;
    //return *dataPtr;

    /*

    while (dataPtr != NULL) {
        visData(dataPtr);        
        dataPtr = dataPtr->neste;  // Går til neste i lista
    }

    dataPtr = dataListe;
    // Frigjør all allokert minne
    while (dataPtr != NULL) {
        slettes = dataPtr;
        dataPtr = dataPtr->neste;
        free(slettes);
    }*/
}

void dataUtregning(struct VarData *dataPtr) {
}

void visData(struct VarData *data) {
    printf("\nDag: %i minTemp: %i maxTemp: %i nedbor: %i", data->dagNr, data->minTemp, data->maxTemp, data->nedbor);
}

void frigjorData(struct VarData *data, struct VarData *helperPtr) {
    // Frigjør all allokert minne
    while (data != NULL) {
        helperPtr = data;
        data = data->neste;
        free(helperPtr);
    }
}