#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

char* GenerateWord();
void PrintLogo();
void VisibleWord(char*, char*, bool, int);
void PrintHangman(int, char*);
int CheckLetter(char*, char*);


//Valitse sana randomilla listasta ja palauta se funktiosta
char* GenerateWord() {
    char *listasanoja[10] = {"VALTAVA", "PYRAMIDI", "KUUSIKULMIO", "KORVAT", "PALMU", "ENNEUNI", "VAIHTEISTO", "RAHKAPULLA", "MAGNEETTI", "JOHDOT"};
    srand(time(NULL));
    int randomindex = (rand() % (9 - 0 + 1)) + 0;
    //printf("%d", randomindex);
    //printf("\n%s", listasanoja[randomindex]);
    return listasanoja[randomindex];
}

// Logo
void PrintLogo() {
    printf("#   #   #   #   #  ###  #   #   #   #   #  \n");
    printf("#   #  # #  ##  # #   # ## ##  # #  ##  #  \n");
    printf("##### ##### # # # #     # # # ##### # # #  \n");
    printf("#   # #   # #  ## #  ## #   # #   # #  ##  \n");
    printf("#   # #   # #   #  ###  #   # #   # #   #  \n");
}

// Tarkista onko kirjain sopiva tai onko se syötetty aiemmin
int CheckLetter(char *kirjain, char *kirjainJono) {
    for (int i = 0; i<=strlen(kirjainJono); i++) {
        if (*kirjain == kirjainJono[i]) {
            return 1;
        }
    }
    return 0;
}

//Tulosta näkyvä sana tai tyhjät merkit
void VisibleWord(char *ptrWord, char *printedWord, bool format, int hitIndex) {
    int wordLength = strlen(ptrWord)*2;                             //Lasketaan sanan pituus
    char shownWord[30] = "";
    //printf("\n%d", strlen(ptrWord));

    // Ennen arvausta printedWord merkkijonoon alustetaan oikea määrä "_ "-merkkejä 
    if (format == true) {
        for (int i = 0; i<wordLength; i++) {
            if (i%2 == 0) {
                shownWord[i] = '_';
            }
            else
                shownWord[i] = ' ';
        }
        strcpy(printedWord, shownWord);
    }

    // Ei ole alustus
    else {
        // hitIndex arvolla katsotaan mikä merkkijonon merkeistä muutetaan, jos arvo on -1 niin mitään ei muuteta (väärä arvaus)
        if (hitIndex != -1) {
            printedWord[hitIndex*2] = ptrWord[hitIndex];
        }
    }
    //strcpy(printedWord, shownWord);
    //printf("\n%s\n", printedWord);
}

//Tulosta hirsipuu
void PrintHangman(int virheidenMaara, char *teksti) {
    switch (virheidenMaara) {
        case 0:
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n            %s", teksti);
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            break;
        case 1:
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n            %s", teksti);
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n============");
            printf("\n============");
            break;
        case 2:
            printf("\n");
            printf("\n  +         ");
            printf("\n  |         ");
            printf("\n  |         %s", teksti);
            printf("\n  |         ");
            printf("\n  |         ");
            printf("\n  |         ");
            printf("\n============");
            printf("\n============");
            break;
        case 3:
            printf("\n");
            printf("\n  +----+    ");
            printf("\n  |         ");
            printf("\n  |         %s", teksti);
            printf("\n  |         ");
            printf("\n  |         ");
            printf("\n  |         ");
            printf("\n============");
            printf("\n============");
            break;
        case 4:
            printf("\n");
            printf("\n  +----+    ");
            printf("\n  |    |    ");
            printf("\n  |         %s", teksti);
            printf("\n  |         ");
            printf("\n  |         ");
            printf("\n  |         ");
            printf("\n============");
            printf("\n============");
            break;
        case 5:
            printf("\n");
            printf("\n  +----+    ");
            printf("\n  |    |    ");
            printf("\n  |    o    %s", teksti);
            printf("\n  |         ");
            printf("\n  |         ");
            printf("\n  |         ");
            printf("\n============");
            printf("\n============");
            break;
        case 6:
            printf("\n");
            printf("\n  +----+    ");
            printf("\n  |    |    ");
            printf("\n  |    o    %s", teksti);
            printf("\n  |    |    ");
            printf("\n  |         ");
            printf("\n  |         ");
            printf("\n============");
            printf("\n============");
            break;
        case 7:
            printf("\n");
            printf("\n  +----+    ");
            printf("\n  |    |    ");
            printf("\n  |    o    %s", teksti);
            printf("\n  |   /|    ");
            printf("\n  |         ");
            printf("\n  |         ");
            printf("\n============");
            printf("\n============");
            break;
        case 8:
            printf("\n");
            printf("\n  +----+    ");
            printf("\n  |    |    ");
            printf("\n  |    o    %s", teksti);
            printf("\n  |   /|\\  ");
            printf("\n  |         ");
            printf("\n  |         ");
            printf("\n============");
            printf("\n============");
            break;
        case 9:
            printf("\n");
            printf("\n  +----+    ");
            printf("\n  |    |    ");
            printf("\n  |    o    %s", teksti);
            printf("\n  |   /|\\  ");
            printf("\n  |   /     ");
            printf("\n  |         ");
            printf("\n============");
            printf("\n============");
            break;
        case 10:
            printf("\n");
            printf("\n  +----+                  ");
            printf("\n  |    |    HÄVISIT PELIN!");
            printf("\n  |    o    ");
            printf("\n  |   /|\\  <- SINÄ       ");
            printf("\n  |   / \\                ");
            printf("\n  |                       ");
            printf("\n============              ");
            printf("\n|          |              ");
            break;
    }
}

void main() {
    char arvaus;
    char tulostusrivi[30] = "";
    char joSyotetyt[30] = "";
    int virheita = 0;
    bool voitto = false;
    bool osuma = false;
    int osumia = 0;
    int index = 0;
    char teksti[15] = "";

    PrintLogo();

    // Vaihe 1: Valitse sana luettelosta randomilla
    char* sana = GenerateWord();
    //printf("\n%s", sana);

    // Vaihe 2: Tulosta "_" jokaista sanan merkkiä kohti ja lisää välit
    VisibleWord(sana, tulostusrivi, true, -1);
    //VisibleWord(sana, &tulostusrivi[0], true, -1);            //Toimii myös
    printf("\n%s", tulostusrivi);

    // Vaihe 3: Tulosta tyhjä kenttä
    PrintHangman(virheita, teksti);

    //Game Loop
    while ( voitto == false && virheita < 10 ) {

        // Vaihe 4: Pelaaja arvaa kirjaimen
        printf("\nSyötä kirjain: ");
        scanf(" %c", &arvaus);                  //välimerkki ennen %c jotta vältytään \n jäämistä lukumuistiin

        // Vaihe 4.1: Verrataan arvoja jo syötettyihin ja jos on sama merkki uudestaan niin lisätään virheitä yhdellä
        if (CheckLetter(&arvaus, joSyotetyt) == 1) {
            printf("Syötit saman merkin %c toistamiseen. \n", arvaus);
            //printf("%s", joSyotetyt);
        }
        else {
            joSyotetyt[index] = arvaus;        // Lisätään syötetty merkki joSyotetyt merkkijonoon
            //printf("%s", joSyotetyt);
            index++;

            // Vaihe 5: Vertaa syötettyä kirjainta sanan kaikkiin merkkeihin (case insensitive)
            //          Jos kirjain löytyy sanasta, niin näytä se
            //          Jos kirjainta ei löydy sanasta, lisää virheitä yhdellä
            for (int i = 0; i<strlen(sana); i++) {
                if (tolower((int) arvaus) == tolower(sana[i])) {
                    osuma = true;
                    osumia++;
                    VisibleWord(sana, tulostusrivi, false, i);
                    
                }
                //printf("\nOnko sama: %c == %c", arvaus, sana[i]);
            }
        }

        
        // Tarkistetaan tuliko osumia, jos ei niin lisätään virheitä
        if (osuma == false) {
            VisibleWord(sana, tulostusrivi, false, -1);
            virheita++;
        }
        else {
            osuma = false;
        }
        // Jos osumien määrä on sama kuin sanan pituus niin voitto
        if (osumia == strlen(sana)) {
            voitto = true;
            strcpy(teksti, "Voitit Pelin");
        }
        printf("\n%s", tulostusrivi);

        // Vaihe 3: Tulosta hirsipuun vaihe
        PrintHangman(virheita, teksti);
        
    }
}

// TODO: 
// 1) Ota muistiin syötetyt kirjaimet jotta samaa kirjainta ei voi syöttää montaa kertaa (se lisää osumia joka kerralla muutoin)
// 2) Ääkkösten kösittely
// 3) Näytä jo syötetyt kirjaimet ja oliko ne osumia vai ei (BONUS)