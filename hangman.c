#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>

char* GenerateWord();
void PrintLogo();
void VisibleWord(char*, char*, bool, int);
void PrintHangman(int, char*);
int CheckLetter(wchar_t*, wchar_t*);


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
int CheckLetter(wchar_t *kirjain, wchar_t *kirjainJono) {
    //wprintf(L"%d\n", *kirjain);
    if(*kirjain == L'\n' || *kirjain == L'\r') {
            *kirjain = L'\0';
    }
    // ÄÄkkösten käsittely
    if (*kirjain > 130) {
        if (*kirjain == 132 || *kirjain == 142) {
            //Kirjain ä
            *kirjain = L'ä';
        }
        else if (*kirjain == 148 || *kirjain == 153) {
            //Kirjain ö
            *kirjain = L'ö';
        }
        else if (*kirjain == 134 || *kirjain == 143) {
            //Kirjain å
            *kirjain = L'å';
        }
    }
    // Tarkista onko kirjain jo aiemmin syötetty
    for (int i = 0; i<=wcslen(kirjainJono); i++) {
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
    wchar_t arvaus;
    char tulostusrivi[30] = "";
    wchar_t joSyotetyt[30] = L"";
    int virheita = 0;
    bool voitto = false;
    bool osuma = false;
    int osumia = 0;
    int index = 0;
    char teksti[15] = "";
    int merkkiarvo = 0;

    // Määritetään locale niin ääkköset näkyy terminaalissa oikein
    setlocale(LC_ALL, "fi-FI.utf-8");
    if(setlocale(LC_ALL, "fi-FI.utf-8") == NULL){
        perror("setlocale failed");
        exit(1);
    }
    PrintLogo();

    // Vaihe 1: Valitse sana luettelosta randomilla
    char* sana = GenerateWord();

    // Vaihe 2: Tulosta "_" jokaista sanan merkkiä kohti ja lisää välit
    VisibleWord(sana, tulostusrivi, true, -1);
    printf("\n%s", tulostusrivi);

    // Vaihe 3: Tulosta tyhjä kenttä
    PrintHangman(virheita, teksti);

    //Game Loop
    while ( voitto == false && virheita < 10 ) {

        // Vaihe 4: Pelaaja arvaa kirjaimen
        printf("\nSyötä kirjain: ");
        scanf(" %c", &arvaus);                  //välimerkki ennen %c jotta vältytään \n jäämistä lukumuistiin
        
        merkkiarvo = CheckLetter(&arvaus, joSyotetyt);

        // Vaihe 4.2: Verrataan arvoja jo syötettyihin
        // jos on sama merkki uudestaan niin ei lisätä sitä syötettyihin eikä lisätä indexiä
        // ei myöskään käydä vertaamassa sitä sanan kirjaimiin tai lisätä osumia
        if (merkkiarvo == 1) {
            wprintf(L"\nSyötit saman merkin %lc toistamiseen. ", arvaus);
        }

        // jos ei ole sama merkki niin lisätään se syötettyihin ja lisätään indexiä
        else if (merkkiarvo == 0) {
            joSyotetyt[index] = arvaus;
            //wprintf(L"\nSyötetyt kirjaimet: %ls", joSyotetyt);
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
// 1) Ääkkösten kösittely
// 2) Tiedostosta sanojen haku (BONUS)