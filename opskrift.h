#ifndef OPSKRIFT_H
#define OPSKRIFT_H

typedef struct {
    char navn[50];
    int tid;           // minutter
    char ingredienser[200];
    char fremgangsmåde[300];
    int pris;           // kr
} Opskrift;

void initOpskrifter(Opskrift opskrifter[], int antal);
void visOpskrifter(Opskrift opskrifter[], int antal, int budget, int tid);

#endif
