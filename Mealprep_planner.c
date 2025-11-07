#include <stdio.h>
#include "opskrift.h"

int main() {
    int budget, tid;
    Opskrift opskrifter[9];

    initOpskrifter(opskrifter, 9);

    printf("Indtast dit budget (kr): ");
    scanf("%d", &budget);
    printf("Indtast hvor lang tid du har til at lave mad (minutter): ");
    scanf("%d", &tid);

    visOpskrifter(opskrifter, 9, budget, tid);

    return 0;
}
