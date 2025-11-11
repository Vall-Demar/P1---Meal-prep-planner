#include "opskrift.h"
#include "api.h" 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Funktion til at lave string lowercase
void strToLower(char *s) {
    while (*s) {
        *s = tolower(*s);
        s++;
    }
}

// Initialiser opskrifter med testpriser
void initOpskrifter(Opskrift opskrifter[], int antal) {
    if (antal < 25) return; // vi har 25 opskrifter, index 0..24

    strcpy(opskrifter[0].navn, "Spaghetti Bolognese");
    opskrifter[0].tid = 45;
    strcpy(opskrifter[0].ingredienser,
           "300 g hakket oksekød, 1 dåse hakkede tomater, 1 løg, "
           "2 fed hvidløg, 200 g spaghetti, 1 spsk olie, salt, peber");
    strcpy(opskrifter[0].fremgangsmåde,
           "Steg kød med løg og hvidløg, tilsæt tomater og krydderier. "
           "Kog spaghetti, og server med saucen.");
    opskrifter[0].pris = 50;
    opskrifter[0].portioner = 4;

    strcpy(opskrifter[1].navn, "Grøntsagssuppe");
    opskrifter[1].tid = 30;
    strcpy(opskrifter[1].ingredienser,
           "1 l grøntsagsbouillon, 2 gulerødder, 2 kartofler, "
           "1 porre, 1 spsk olie, salt, peber");
    strcpy(opskrifter[1].fremgangsmåde,
           "Skær grøntsager i tern og svits kort i olie. "
           "Tilsæt bouillon, kog 20 min, blend og smag til.");
    opskrifter[1].pris = 30;
    opskrifter[1].portioner = 4;

    strcpy(opskrifter[2].navn, "Omelet med ost og skinke");
    opskrifter[2].tid = 10;
    strcpy(opskrifter[2].ingredienser,
           "3 æg, 2 spsk mælk, 30 g revet ost, 2 skiver skinke, smør, salt, peber");
    strcpy(opskrifter[2].fremgangsmåde,
           "Pisk æg og mælk, steg på pande i smør, tilsæt ost og skinke, fold omeletten.");
    opskrifter[2].pris = 20;
    opskrifter[2].portioner = 2;

    strcpy(opskrifter[3].navn, "Ristet sandwich med kylling");
    opskrifter[3].tid = 15;
    strcpy(opskrifter[3].ingredienser,
           "2 skiver toastbrød, 100 g kylling, 1 skive ost, 1 skive tomat, smør");
    strcpy(opskrifter[3].fremgangsmåde,
           "Smør brød, læg kylling, tomat og ost imellem, rist til gylden.");
    opskrifter[3].pris = 25;
    opskrifter[3].portioner = 1;

    strcpy(opskrifter[4].navn, "Tacos med oksekød");
    opskrifter[4].tid = 25;
    strcpy(opskrifter[4].ingredienser,
           "300 g hakket oksekød, 1 pakke taco shells, 1 løg, "
           "1 tomat, salat, 1 pose taco krydderi");
    strcpy(opskrifter[4].fremgangsmåde,
           "Steg kød med løg og krydderi, fyld taco shells med salat og tomat.");
    opskrifter[4].pris = 40;
    opskrifter[4].portioner = 3;

     strcpy(opskrifter[5].navn, "Pandekager");
    opskrifter[5].tid = 20;
    strcpy(opskrifter[5].ingredienser,
           "2 æg, 2 dl mælk, 100 g mel, 1 spsk sukker, smør til stegning");
    strcpy(opskrifter[5].fremgangsmåde,
           "Pisk det hele sammen, steg tynde pandekager på pande.");
    opskrifter[5].pris = hentPrisFraAPI(opskrifter[5].navn);
    opskrifter[5].portioner = 4;

    strcpy(opskrifter[6].navn, "Bagte kartofler med fyld");
    opskrifter[6].tid = 60;
    strcpy(opskrifter[6].ingredienser,
           "4 store kartofler, 100 g creme fraiche, 50 g bacon, purløg, salt, peber");
    strcpy(opskrifter[6].fremgangsmåde,
           "Bag kartofler 45 min, fyld med bacon og creme fraiche, drys purløg.");
    opskrifter[6].pris = hentPrisFraAPI(opskrifter[6].navn);
    opskrifter[6].portioner = 4;

    strcpy(opskrifter[7].navn, "Karrysild med rugbrød");
    opskrifter[7].tid = 5;
    strcpy(opskrifter[7].ingredienser,
           "2 stykker sild, 2 skiver rugbrød, 2 spsk karrydressing, løgskiver");
    strcpy(opskrifter[7].fremgangsmåde,
           "Smør rugbrød, læg sild og karrydressing på, pynt med løg.");
    opskrifter[7].pris = hentPrisFraAPI(opskrifter[7].navn);
    opskrifter[7].portioner = 2;

    strcpy(opskrifter[8].navn, "Frugtsalat med yoghurt");
    opskrifter[8].tid = 10;
    strcpy(opskrifter[8].ingredienser,
           "1 banan, 1 æble, 1 appelsin, 2 dl yoghurt, 1 tsk honning");
    strcpy(opskrifter[8].fremgangsmåde,
           "Skær frugt i stykker, bland med yoghurt og honning.");
    opskrifter[8].pris = hentPrisFraAPI(opskrifter[8].navn);
    opskrifter[8].portioner = 2;

    strcpy(opskrifter[9].navn, "Borscht (russisk rødbedesuppe)");
    opskrifter[9].tid = 60;
    strcpy(opskrifter[9].ingredienser,
           "300 g rødbeder, 1 gulerod, 1 løg, 2 kartofler, 1/2 kål, "
           "1 l grøntsagsbouillon, 2 spsk olie, 2 spsk creme fraiche");
    strcpy(opskrifter[9].fremgangsmåde,
           "Skræl og riv grøntsager. Svits løg og gulerod i olie, "
           "tilsæt rødbeder, kartofler og kål. Hæld bouillon i og kog 40 min. "
           "Server med en klat creme fraiche.");
    opskrifter[9].pris = hentPrisFraAPI(opskrifter[9].navn);
    opskrifter[9].portioner = 4;

    strcpy(opskrifter[10].navn, "Pelmeni (russiske dumplings)");
    opskrifter[10].tid = 50;
    strcpy(opskrifter[10].ingredienser,
           "200 g hakket oksekød, 200 g hakket svinekød, 1 løg, "
           "300 g mel, 1 æg, 1 dl vand, salt, peber, smør til servering");
    strcpy(opskrifter[10].fremgangsmåde,
           "Lav dej af mel, æg og vand. Rul tyndt ud og skær små cirkler. "
           "Bland kød, løg, salt og peber, læg lidt fyld i hver cirkel og fold sammen. "
           "Kog i saltet vand i ca. 8 min, server med smør eller creme fraiche.");
    opskrifter[10].pris = hentPrisFraAPI(opskrifter[10].navn);
    opskrifter[10].portioner = 4;

    strcpy(opskrifter[11].navn, "Olivier salat");
    opskrifter[11].tid = 25;
    strcpy(opskrifter[11].ingredienser,
           "3 kartofler, 2 gulerødder, 3 æg, 100 g ærter, 100 g skinke, "
           "3 spsk mayonnaise, salt, peber");
    strcpy(opskrifter[11].fremgangsmåde,
           "Kog kartofler, gulerødder og æg. Skær i tern, bland med ærter, "
           "skinke og mayonnaise. Smag til med salt og peber.");
    opskrifter[11].pris = hentPrisFraAPI(opskrifter[11].navn);
    opskrifter[11].portioner = 4;

    strcpy(opskrifter[12].navn, "Blini (russiske pandekager)");
    opskrifter[12].tid = 30;
    strcpy(opskrifter[12].ingredienser,
           "2 æg, 3 dl mælk, 150 g mel, 1 tsk sukker, 1 knivspids salt, smør til stegning");
    strcpy(opskrifter[12].fremgangsmåde,
           "Pisk æg, mælk, mel, sukker og salt. Steg små pandekager på pande. "
           "Server med smør, syltetøj eller creme fraiche.");
    opskrifter[12].pris = hentPrisFraAPI(opskrifter[12].navn);
    opskrifter[12].portioner = 4;

    strcpy(opskrifter[13].navn, "Kartoshka (russiske kagekugler)");
    opskrifter[13].tid = 20;
    strcpy(opskrifter[13].ingredienser,
           "200 g kiks, 100 g kondenseret mælk, 2 spsk kakao, 50 g smør");
    strcpy(opskrifter[13].fremgangsmåde,
           "Knus kiksene, bland med kakao, smør og kondenseret mælk. "
           "Form kugler og sæt på køl i 1 time.");
    opskrifter[13].pris = hentPrisFraAPI(opskrifter[13].navn);
    opskrifter[13].portioner = 6;

    strcpy(opskrifter[14].navn, "Syrniki (russiske hytteost-pandekager)");
    opskrifter[14].tid = 25;
    strcpy(opskrifter[14].ingredienser,
           "250 g hytteost, 1 æg, 2 spsk sukker, 3 spsk mel, olie til stegning");
    strcpy(opskrifter[14].fremgangsmåde,
           "Bland hytteost, æg, sukker og mel. Form små flade kager og steg på pande i olie. "
           "Server med syltetøj eller creme fraiche.");
    opskrifter[14].pris = hentPrisFraAPI(opskrifter[14].navn);
    opskrifter[14].portioner = 3;

     strcpy(opskrifter[15].navn, "Laks med grøntsager");
    opskrifter[15].tid = 35;
    strcpy(opskrifter[15].ingredienser,
           "200 g laks, 150 g broccoli, 100 g gulerødder, 1 spsk olie, salt, peber, citronsaft");
    strcpy(opskrifter[15].fremgangsmåde,
           "Steg laksen let i olie, damp grøntsagerne. Server med citronsaft.");
    opskrifter[15].pris = hentPrisFraAPI(opskrifter[15].navn);
    opskrifter[15].portioner = 2;

    strcpy(opskrifter[16].navn, "Bøf med kartofler");
    opskrifter[16].tid = 50;
    strcpy(opskrifter[16].ingredienser,
           "2 bøffer á 200 g, 400 g kartofler, 50 g smør, salt, peber");
    strcpy(opskrifter[16].fremgangsmåde,
           "Steg bøfferne efter ønsket stegegrad. Kog eller steg kartoflerne, server med smør.");
    opskrifter[16].pris = hentPrisFraAPI(opskrifter[16].navn);
    opskrifter[16].portioner = 2;

    strcpy(opskrifter[17].navn, "Sushi bowl");
    opskrifter[17].tid = 40;
    strcpy(opskrifter[17].ingredienser,
           "150 g sushi-ris, 100 g laks, 1 avocado, agurk, sojasovs, sesamfrø");
    strcpy(opskrifter[17].fremgangsmåde,
           "Kog risene, skær grøntsager og fisk i skiver. Anret i skål, dryp sojasovs og drys sesam.");
    opskrifter[17].pris = hentPrisFraAPI(opskrifter[17].navn);
    opskrifter[17].portioner = 2;

    strcpy(opskrifter[18].navn, "Stegt kylling med ris");
    opskrifter[18].tid = 45;
    strcpy(opskrifter[18].ingredienser,
           "2 kyllingebryst, 150 g ris, 100 g broccoli, 1 spsk olie, krydderier");
    strcpy(opskrifter[18].fremgangsmåde,
           "Steg kylling i olie med krydderier, kog ris og damp broccoli. Server sammen.");
    opskrifter[18].pris = hentPrisFraAPI(opskrifter[18].navn);
    opskrifter[18].portioner = 2;

    strcpy(opskrifter[19].navn, "Oksekød i wok");
    opskrifter[19].tid = 30;
    strcpy(opskrifter[19].ingredienser,
           "200 g oksekød, 150 g blandede grøntsager, 1 spsk sojasovs, olie til stegning");
    strcpy(opskrifter[19].fremgangsmåde,
           "Steg oksekød hurtigt i wok, tilsæt grøntsager og sojasovs. Server straks.");
    opskrifter[19].pris = hentPrisFraAPI(opskrifter[19].navn);
    opskrifter[19].portioner = 2;

    strcpy(opskrifter[20].navn, "Kyllingesalat deluxe");
    opskrifter[20].tid = 20;
    strcpy(opskrifter[20].ingredienser,
           "150 g kylling, blandet salat, avocado, 1 spsk olie, salt, peber, nødder");
    strcpy(opskrifter[20].fremgangsmåde,
           "Steg kylling, bland med salat, avocado og nødder. Dryp olie og krydderier over.");
    opskrifter[20].pris = hentPrisFraAPI(opskrifter[20].navn);
    opskrifter[20].portioner = 2;

    strcpy(opskrifter[21].navn, "Burger med pommes");
    opskrifter[21].tid = 35;
    strcpy(opskrifter[21].ingredienser,
           "2 bøffer, burgerboller, salat, tomat, 200 g pommes frites, ketchup");
    strcpy(opskrifter[21].fremgangsmåde,
           "Steg bøfferne og varm bollerne. Server med salat, tomat og pommes frites.");
    opskrifter[21].pris = hentPrisFraAPI(opskrifter[21].navn);
    opskrifter[21].portioner = 2;

    strcpy(opskrifter[22].navn, "Luksus steak med sauce");
    opskrifter[22].tid = 60;
    strcpy(opskrifter[22].ingredienser,
           "300 g steak, 50 g smør, peber, salt, 50 ml rødvinssauce");
    strcpy(opskrifter[22].fremgangsmåde,
           "Steg steak i smør, krydr med salt og peber. Server med rødvinssauce.");
    opskrifter[22].pris = hentPrisFraAPI(opskrifter[22].navn);
    opskrifter[22].portioner = 1;

    strcpy(opskrifter[23].navn, "Krabbe salat");
    opskrifter[23].tid = 30;
    strcpy(opskrifter[23].ingredienser,
           "150 g krabbe, blandet salat, avocado, 1 spsk mayonnaise, citron");
    strcpy(opskrifter[23].fremgangsmåde,
           "Bland krabbe med salat og avocado. Tilsæt mayonnaise og citron.");
    opskrifter[23].pris = hentPrisFraAPI(opskrifter[23].navn);
    opskrifter[23].portioner = 2;

    strcpy(opskrifter[24].navn, "Caviar deluxe");
    opskrifter[24].tid = 15;
    strcpy(opskrifter[24].ingredienser,
           "50 g kaviar, ristet brød, smør, citron");
    strcpy(opskrifter[24].fremgangsmåde,
           "Smør brød, læg kaviar på og pynt med citron.");
    opskrifter[24].pris = hentPrisFraAPI(opskrifter[24].navn);
    opskrifter[24].portioner = 1;
}

// Returnerer antal matchende ingredienser mellem bruger og opskrift
int antalMatchendeIngredienser(const char *harIngredienser, const char *opskriftIngredienser) {
    int count = 0;
    char kopi[200], bruger[200];
    strcpy(kopi, opskriftIngredienser);
    strcpy(bruger, harIngredienser);

    strToLower(kopi);
    strToLower(bruger);

    char *del = strtok(kopi, ",");
    while (del != NULL) {
        while (*del && (isspace(*del) || isdigit(*del))) del++; // fjern tal og whitespace
        if (*del && strstr(bruger, del) != NULL) {
            count++;
        }
        del = strtok(NULL, ",");
    }
    return count;
}

// Vis opskrifter prioriteret efter flest match og laveste pris (maks. 4)
void visOpskrifter(Opskrift opskrifter[], int antal, int budget, int tid, int ønskedePortioner, const char *harIngredienser) {
    Opskrift temp;
    int match[antal];

    // Beregn antal match
    for (int i = 0; i < antal; i++) {
        match[i] = antalMatchendeIngredienser(harIngredienser, opskrifter[i].ingredienser);
    }

    // Sortér: flest match først, laveste pris næste
    for (int i = 0; i < antal - 1; i++) {
        for (int j = 0; j < antal - i - 1; j++) {
            int totalPrisJ = opskrifter[j].pris * ønskedePortioner / opskrifter[j].portioner;
            int totalPrisJP1 = opskrifter[j + 1].pris * ønskedePortioner / opskrifter[j + 1].portioner;

            if (match[j] < match[j + 1] || (match[j] == match[j + 1] && totalPrisJ > totalPrisJP1)) {
                temp = opskrifter[j];
                opskrifter[j] = opskrifter[j + 1];
                opskrifter[j + 1] = temp;

                int t = match[j];
                match[j] = match[j + 1];
                match[j + 1] = t;
            }
        }
    }

    // Vis maks 4 opskrifter, selvom match = 0
    int viste = 0;
    for (int i = 0; i < antal && viste < 4; i++) {
        int totalPris = opskrifter[i].pris * ønskedePortioner / opskrifter[i].portioner;
        if (totalPris <= budget && opskrifter[i].tid <= tid) {
            printf("\nOpskrift: %s\n", opskrifter[i].navn);
            printf("Pris for %d portioner: %d kr\n", ønskedePortioner, totalPris);
            printf("Tid: %d minutter\n", opskrifter[i].tid);
            printf("Ingredienser: %s\n", opskrifter[i].ingredienser);
            printf("Fremgangsmåde: %s\n", opskrifter[i].fremgangsmåde);
            printf("Standard portioner: %d\n", opskrifter[i].portioner);
            printf("Matchende ingredienser: %d\n", match[i]);
            viste++;
        }
    }

    if (viste == 0) {
        printf("\nIngen opskrifter passer på dit budget og tid.\n");
    }
}
