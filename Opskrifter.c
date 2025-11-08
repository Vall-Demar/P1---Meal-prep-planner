#include "opskrift.h"
#include "api.h"
#include <stdio.h>
#include <string.h>

void initOpskrifter(Opskrift opskrifter[], int antal) {
    if (antal < 9) return;

    strcpy(opskrifter[0].navn, "Kylling i karry");
    opskrifter[0].tid = 60;
    strcpy(opskrifter[0].ingredienser, "Kylling, karry, ris, grøntsager");
    strcpy(opskrifter[0].fremgangsmåde, "Steg kylling, tilsæt karry og grøntsager, server med ris");
    opskrifter[0].pris = hentPrisFraAPI(opskrifter[0].navn);

    strcpy(opskrifter[1].navn, "Bøf med kartofler");
    opskrifter[1].tid = 50;
    strcpy(opskrifter[1].ingredienser, "Bøf, kartofler, salat");
    strcpy(opskrifter[1].fremgangsmåde, "Steg bøf, kog kartofler, server med salat");
    opskrifter[1].pris = hentPrisFraAPI(opskrifter[1].navn);

    strcpy(opskrifter[2].navn, "Lasagne");
    opskrifter[2].tid = 45;
    strcpy(opskrifter[2].ingredienser, "Pasta, kød, ost, tomatsauce");
    strcpy(opskrifter[2].fremgangsmåde, "Læg lag af pasta, kød og ost, bag i ovn");
    opskrifter[2].pris = hentPrisFraAPI(opskrifter[2].navn);

    strcpy(opskrifter[3].navn, "Rugbrød med æg");
    opskrifter[3].tid = 10;
    strcpy(opskrifter[3].ingredienser, "2 skiver rugbrød, 2 æg, smør");
    strcpy(opskrifter[3].fremgangsmåde, "Kog æggene, smør rugbrød, læg æg på");
    opskrifter[3].pris = hentPrisFraAPI(opskrifter[3].navn);

    strcpy(opskrifter[4].navn, "Smoothie bowl");
    opskrifter[4].tid = 15;
    strcpy(opskrifter[4].ingredienser, "Banan, bær, mælk, granola");
    strcpy(opskrifter[4].fremgangsmåde, "Blend banan, bær og mælk, hæld i skål, top med granola");
    opskrifter[4].pris = hentPrisFraAPI(opskrifter[4].navn);

    strcpy(opskrifter[5].navn, "Hurtig omelet");
    opskrifter[5].tid = 12;
    strcpy(opskrifter[5].ingredienser, "2 æg, lidt mælk, salt, peber");
    strcpy(opskrifter[5].fremgangsmåde, "Pisk æg og mælk, steg på pande 5-7 min");
    opskrifter[5].pris = hentPrisFraAPI(opskrifter[5].navn);

    strcpy(opskrifter[6].navn, "Salat med tun");
    opskrifter[6].tid = 10;
    strcpy(opskrifter[6].ingredienser, "1 dåse tun, salatmix, tomat, agurk, dressing");
    strcpy(opskrifter[6].fremgangsmåde, "Bland ingredienser i skål, tilsæt dressing");
    opskrifter[6].pris = hentPrisFraAPI(opskrifter[6].navn);

    strcpy(opskrifter[7].navn, "Ristet sandwich");
    opskrifter[7].tid = 12;
    strcpy(opskrifter[7].ingredienser, "2 skiver brød, ost, skinke, smør");
    strcpy(opskrifter[7].fremgangsmåde, "Smør brød, læg ost og skinke imellem, rist på pande");
    opskrifter[7].pris = hentPrisFraAPI(opskrifter[7].navn);

    strcpy(opskrifter[8].navn, "Hurtig suppe");
    opskrifter[8].tid = 15;
    strcpy(opskrifter[8].ingredienser, "1 dåse tomater, 1 løg, 1 bouillonterning, krydderier");
    strcpy(opskrifter[8].fremgangsmåde, "Kog løg, tilsæt tomater og bouillon, blend til suppe");
    opskrifter[8].pris = hentPrisFraAPI(opskrifter[8].navn);
}

void visOpskrifter(Opskrift opskrifter[], int antal, int budget, int tid) {
    // Filter og sorter fra dyrest til billigst
    Opskrift temp;
    // Bubble sort baseret på pris
    for(int i=0; i<antal-1; i++) {
        for(int j=0; j<antal-i-1; j++) {
            if(opskrifter[j].pris < opskrifter[j+1].pris) {
                temp = opskrifter[j];
                opskrifter[j] = opskrifter[j+1];
                opskrifter[j+1] = temp;
            }
        }
    }

    int fundet = 0;
    for(int i=0; i<antal; i++) {
        if(opskrifter[i].pris <= budget && opskrifter[i].tid <= tid) {
            printf("\nOpskrift: %s\n", opskrifter[i].navn);
            printf("Pris: %d kr\n", opskrifter[i].pris);
            printf("Tid: %d minutter\n", opskrifter[i].tid);
            printf("Ingredienser: %s\n", opskrifter[i].ingredienser);
            printf("Fremgangsmåde: %s\n", opskrifter[i].fremgangsmåde);
            fundet = 1;
        }
    }
    if(!fundet) {
        printf("\nIngen opskrifter passer til dit budget og tid.\n");
    }
}





