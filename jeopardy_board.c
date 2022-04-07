#include "jeopardy_main.h"

// Global Variables Defining Team Scores
int Team_One = 0;
int Team_Two = 0;

// Clear Game Screen
void clearScreen() {
    printf("\e[2J\e[H");
}

// Clear Screen/Reset Game Board
void resetBoard(int arrayPoints[ROWS][COLS], int arraySelect[ROWS][COLS]) {
    clearScreen();
    setColor("B");
    printBoard(arrayPoints, arraySelect);
}

// Shorthand for Switch String Color
void SSC(char* string, char* toColor, char* outColor) {
    setColor(toColor);
    printf(string);
    setColor(outColor);
}

// Shorthand for Switch Number Color
void SNC(int input, char* color) {
    setColor(color);
    printf("%d", input);
    setColor("B");
}

// Add or Subtract Points from Selected Team Score
void updatePoints(int teamNumber, int ptsSelected, int selection) {
    // Team One Selected & Question Correct
    if (selection == 1 && teamNumber == 1) {
        Team_One += ptsSelected;
        if (Team_One >= MAX_PTS) {
            Team_One = MAX_PTS;
        }
    }
    // Team One Selected & Question Incorrect
    else if (selection == 2 && teamNumber == 1) {
        Team_One -= ptsSelected;
    }
    // Team Two Selected & Question Correct
    else if (selection == 1 && teamNumber == 2) {
        Team_Two += ptsSelected;
        if (Team_Two >= MAX_PTS) {
            Team_Two = MAX_PTS;
        }
    }
    // Team Two Selected & Question Incorrect
    else if (selection == 2 && teamNumber == 2) {
        Team_Two -= ptsSelected;
    }
}

/*****************************
* Change Print Output Colors:
* B for blue
* Y for yellow
* W for white
* R for red
* C for cyan
*****************************/
void setColor(char* color) {
    if (strcmp(color, "B") == 0) {
        printf("\033[0;34m");
    }
    else if (strcmp(color, "Y") == 0) {
        printf("\033[0;33m");
    }
    else if (strcmp(color, "W") == 0) {
        printf("\033[0;37m");
    }
    else if (strcmp(color, "R") == 0) {
        printf("\033[0;31m");
    }
    else if (strcmp(color, "C") == 0) {
        printf("\033[0;36m");
    }
}

// Print Main Game Board
void printBoard(int arrayPoints[ROWS][COLS], int arraySelect[ROWS][COLS]) {
    int i = 0, j = 0;
    // Website: https://textkool.com/en/ascii-art-generator?hl=default&vl=default&font=Doom&text=Jeopardy
    // Font: Doom
    // Character Width/Height: Default
    printf("=========================================================\n");
    printf("=========================================================\n");
    setColor("Y");
    printf("       ___                                _              \n"
           "      |_  |                              | |             \n"
           "        | | ___  ___  _ __   __ _ _ __ __| |_   _        \n"
           "        | |/ _ \\/ _ \\| '_ \\ / _` | '__/ _` | | | |    \n"
           "    /\\__/ /  __/ (_) | |_) | (_| | | | (_| | |_| |      \n"
           "    \\____/ \\___|\\___/| .__/ \\__,_|_|  \\__,_|\\__, | \n"
           "                     | |                     __/ |       \n"
           "                     |_|                    |___/        \n");
    setColor("B");
    printf("=========================================================\n");
    printf(" -------- "); setColor("C"); printf("Team One: "); setColor("Y"); printf("%5d", Team_One); setColor("B"); 
        printf(" ------ "); setColor("C"); printf("Team Two: "); setColor("Y"); printf("%5d", Team_Two); setColor("B"); printf(" ------- \n");
    printf("=========================================================\n");
    setColor("Y");
    printf(" HORROR   ANIMATION   COMEDY   SCI-FI   FANTASY   ACTION \n"); //57
    setColor("B");
    printf("  ["); SNC(1, "C"); printf("]        ["); SNC(2, "C"); printf("]       ["); SNC(3, "C");
           printf("]      ["); SNC(4, "C"); printf("]       ["); SNC(5, "C"); printf("]      ["); SNC(6, "C"); printf("]   \n");
    printf("=========================================================\n\n");
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            if (arraySelect[i][j] == 1) {
                setColor("Y");
                printf("  %4d    ", arrayPoints[i][j]);
            }
            else {
                setColor("B");
                printf("  %4d    ", arrayPoints[i][j]);
            }
        }
        printf("\n\n");
    }
    setColor("Blue");
    printf("=========================================================\n");
    printf(" ---------- "); setColor("C"); printf("Team One ["); SNC(1, "C"); printf("] ------- Team Two ["); SNC(2, "C"); printf("] ---------- \n");
    printf("=========================================================\n");
}
