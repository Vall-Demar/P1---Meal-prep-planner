#include "api.h"
#include <string.h>

int hentPrisFraAPI(const char *navn) {
    if (strcmp(navn, "Spaghetti Bolognese") == 0) return 60;
    if (strcmp(navn, "Grøntsagssuppe") == 0) return 35;
    if (strcmp(navn, "Omelet med ost og skinke") == 0) return 25;
    if (strcmp(navn, "Ristet sandwich med kylling") == 0) return 30;
    if (strcmp(navn, "Tacos med oksekød") == 0) return 50;
    if (strcmp(navn, "Pandekager") == 0) return 40;
    if (strcmp(navn, "Bagte kartofler med fyld") == 0) return 45;
    if (strcmp(navn, "Karrysild med rugbrød") == 0) return 28;
    if (strcmp(navn, "Frugtsalat med yoghurt") == 0) return 30;
    if (strcmp(navn, "Borscht (russisk rødbedesuppe)") == 0) return 45;
    if (strcmp(navn, "Pelmeni (russiske dumplings)") == 0) return 55;
    if (strcmp(navn, "Olivier salat") == 0) return 40;
    if (strcmp(navn, "Blini (russiske pandekager)") == 0) return 35;
    if (strcmp(navn, "Kartoshka (russiske kagekugler)") == 0) return 25;
    if (strcmp(navn, "Syrniki (russiske hytteost-pandekager)") == 0) return 30;
    if (strcmp(navn, "Laks med grøntsager") == 0) return 120;
    if (strcmp(navn, "Bøf med kartofler") == 0) return 150;
    if (strcmp(navn, "Pizza Margherita") == 0) return 100;
    if (strcmp(navn, "Sushi bowl") == 0) return 200;
    if (strcmp(navn, "Stegt kylling med ris") == 0) return 130;
    if (strcmp(navn, "Oksekød i wok") == 0) return 140;
    if (strcmp(navn, "Kyllingesalat deluxe") == 0) return 110;
    if (strcmp(navn, "Burger med pommes") == 0) return 160;
    if (strcmp(navn, "Luksus steak med sauce") == 0) return 400;
    if (strcmp(navn, "Krabbe salat") == 0) return 350;
    if (strcmp(navn, "Caviar deluxe") == 0) return 380;

    return 0;
}

