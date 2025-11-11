#include <stdio.h>
#include <string.h>
#include "opskrift.h"

int main() {
    int budget, tid, ønskedePortioner;
    char harIngredienser[200];
    Opskrift opskrifter[50];

    initOpskrifter(opskrifter, 50);

    printf("Indtast dit budget (kr): ");
    scanf("%d", &budget);
    printf("Indtast hvor lang tid du har til at lave mad (minutter): ");
    scanf("%d", &tid);
    printf("Hvor mange portioner vil du lave? ");
    scanf("%d", &ønskedePortioner);
    getchar(); // fanger newline

    printf("Skriv hvilke ingredienser du allerede har (adskilt med komma): ");
    fgets(harIngredienser, sizeof(harIngredienser), stdin);
    harIngredienser[strcspn(harIngredienser, "\n")] = '\0'; // fjern newline

    visOpskrifter(opskrifter, 25, budget, tid, ønskedePortioner, harIngredienser);

    return 0;
}
