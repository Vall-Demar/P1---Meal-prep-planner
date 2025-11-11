#include "api.h"
#include <string.h>

int hentPrisFraAPI(const char *navn) {
    if (strcmp(navn, "Rugbrød med æg") == 0) return 5;
    if (strcmp(navn, "Smoothie bowl") == 0) return 15;
    if (strcmp(navn, "Hurtig omelet") == 0) return 10;
    if (strcmp(navn, "Salat med tun") == 0) return 20;
    if (strcmp(navn, "Pasta med pesto") == 0) return 25;
    if (strcmp(navn, "Ristet sandwich") == 0) return 15;
    if (strcmp(navn, "Hurtig suppe") == 0) return 18;
    if (strcmp(navn, "Grøntsagswrap") == 0) return 12;
    if (strcmp(navn, "Yoghurt med frugt") == 0) return 8;
    if (strcmp(navn, "Bøf med kartofler") == 0) return 80;
    if (strcmp(navn, "Laks med grøntsager") == 0) return 120;
    if (strcmp(navn, "Pizza Margherita") == 0) return 50;
    if (strcmp(navn, "Sushi bowl") == 0) return 100;
    if (strcmp(navn, "Stegt kylling med ris") == 0) return 60;
    if (strcmp(navn, "Oksekød i wok") == 0) return 40;
    if (strcmp(navn, "Kyllingesalat deluxe") == 0) return 35;
    if (strcmp(navn, "Burger med pommes") == 0) return 90;
    if (strcmp(navn, "Luksus steak med sauce") == 0) return 400;
    if (strcmp(navn, "Krabbe salat") == 0) return 150;
    if (strcmp(navn, "Caviar deluxe") == 0) return 300;
    return 0;
}

