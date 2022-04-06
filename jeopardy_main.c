/**************************************
* File:     jeopardy_main.c
* Group:    Jeopardy Game
* Authors:  Jacob, Jackson, Annabelle
**************************************/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "jeopardy_main.h"

void highlightNumber(int input, char* color);

// Global Variables for Team Scores
int Team_One = 0;
int Team_Two = 0;

// Main
int main(void) {
    bool check = true; 
    int rowSelected, colSelected, ptsSelected, timer, teamNumber, selection;
    int arraySelect[ROWS][COLS] = 
    {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    int arrayPoints[ROWS][COLS] = 
    { 
        {200, 200, 200, 200, 200, 200},
        {400, 400, 400, 400, 400, 400},
        {600, 600, 600, 600, 600, 600},
        {800, 800, 800, 800, 800, 800},
        {1000, 1000, 1000, 1000, 1000, 1000}
    };
    while (check) {    
        resetBoard(arrayPoints, arraySelect);
        teamNumber = mainMenuUserInput("Team Select");
        while (!optionSelectionValidation(teamNumber)) {
            resetBoard(arrayPoints, arraySelect);
            teamNumber = mainMenuUserInput("Team Select");
        }

        colSelected = mainMenuUserInput("Catagory");
        colSelected -= 1;
        while (!colSelectValidation(colSelected)) {
            resetBoard(arrayPoints, arraySelect);
            saveEnteredData(teamNumber,0,0);
            colSelected = mainMenuUserInput("Catagory");
            colSelected -= 1;
        }

        ptsSelected = mainMenuUserInput("Points");
        while (!pointSelectValidation(ptsSelected)) {
            resetBoard(arrayPoints, arraySelect);
            saveEnteredData(teamNumber,colSelected + 1,0);
            ptsSelected = mainMenuUserInput("Points");
        }

        rowSelected = convertPointsSelected(ptsSelected);
        if (arraySelect[rowSelected][colSelected] == 0) {
            arraySelect[rowSelected][colSelected] = 1;
            clearScreen();
            printQuestion(colSelected, rowSelected);
            clearScreen();
            selection = printAnswer(colSelected, rowSelected);
            while (!optionSelectionValidation(selection)) {
                clearScreen();
                selection = printAnswer(colSelected, rowSelected);
            }
            updatePoints(teamNumber, ptsSelected, selection);
        }    
    }
}

// add points to team scores
void updatePoints(int teamNumber, int ptsSelected, int selection) {
    if (selection == 1 && teamNumber == 1) {
        Team_One += ptsSelected;
        if (Team_One >= MAX_PTS) {
            Team_One = MAX_PTS;
        }
    }
    else if (selection == 2 && teamNumber == 1) {
        Team_One -= ptsSelected;
    }
    else if (selection == 1 && teamNumber == 2) {
        Team_Two += ptsSelected;
        if (Team_Two >= MAX_PTS) {
            Team_Two = MAX_PTS;
        }
    }
    else if (selection == 2 && teamNumber == 2) {
        Team_Two -= ptsSelected;
    }
}

// Makes board look nicer if input validation fails
void saveEnteredData(int team, int cat, int point) {
    if (team != 0) {
        printf("Team Select: %d\n", team);
    }
    if (cat != 0) {
        printf("Catagory: %d\n", cat);
    }
    if (point != 0) {
        printf("Points: %d\n", point);
    }
}

// Reset Game Board
void resetBoard(int arrayPoints[ROWS][COLS], int arraySelect[ROWS][COLS]) {
    clearScreen();
    setColor("Blue");
    printBoard(arrayPoints, arraySelect);
}

// Validate selection between two options
bool optionSelectionValidation(int selection) {
    bool check = false;
    if (selection == 1 || selection == 2) {
        check = true;
    }
    return check;
}

// Reference used: https://stackoverflow.com/questions/42055482/how-to-reject-letter-when-requesting-int-in-c
// Request User Input for Catagory and Point Values
// If Input != int, Set Default to 0
int mainMenuUserInput(char* type) {
    int value, scanVal;
    printf("%s: ", type);
    scanVal = scanf("%d", &value);
    if (scanVal != 1) {
        getchar();
        value = 0;
    }        
    return value;
}

// Convert User Point Input to Related Row Value
int convertPointsSelected(int points) {
    int row;
    switch (points) {
        case 200:
            row = 0;
            break;
        case 400:
            row = 1;
            break;
        case 600:
            row = 2;
            break;
        case 800:
            row = 3;
            break;
        case 1000:
            row = 4;
            break;
        default:
            printf("Error Converting Points\n");
    }
    return row;
}

// Change Output Colors
// - setColor("Blue") for blue
// - setColor("Yellow") for yellow
void setColor(char* color) {
    if (strcmp(color, "Blue") == 0) {
        printf("\033[0;34m");
    }
    else if (strcmp(color, "Yellow") == 0) {
        printf("\033[0;33m");
    }
    else if (strcmp(color, "White") == 0) {
        printf("\033[0;37m");
    }
    else if (strcmp(color, "Red") == 0) {
        printf("\033[0;31m");
    }
}

// Validate Input Column Value is Legal
bool colSelectValidation(int col) {
    bool check = false;
    int i = 0;
    for (i = 0; i < 6; ++i) {
        if (col == i) check = true;
    }
    return check;
}

// Validate Input Point Value is Legal
bool pointSelectValidation(int points) {
    bool check = false;
    int i = 200;
    for (i = 200; i < 1001; i+=200) {
        if (points == i) check = true;
    }
    return check;
}

// Print Main Game Board
void printBoard(int arrayPoints[ROWS][COLS], int arraySelect[ROWS][COLS]) {
    int i = 0, j = 0;
    // Website: https://textkool.com/en/ascii-art-generator?hl=default&vl=default&font=Doom&text=Jeopardy
    // Font: Doom
    // Character Width/Height: Default
    printf("       ___                                _              \n"
           "      |_  |                              | |             \n"
           "        | | ___  ___  _ __   __ _ _ __ __| |_   _        \n"
           "        | |/ _ \\/ _ \\| '_ \\ / _` | '__/ _` | | | |    \n"
           "    /\\__/ /  __/ (_) | |_) | (_| | | | (_| | |_| |      \n"
           "    \\____/ \\___|\\___/| .__/ \\__,_|_|  \\__,_|\\__, | \n"
           "                     | |                     __/ |       \n"
           "                     |_|                    |___/        \n");
    printf("---------------------------------------------------------\n"
           "          Team One: %04d        Team Two: %04d           \n"
           "---------------------------------------------------------\n"
           " HORROR   ANIMATION   COMEDY   SCI-FI   FANTASY   ACTION \n" //57
           "  [1]        [2]       [3]      [4]       [5]      [6]   \n"
           "---------------------------------------------------------\n\n", Team_One, Team_Two);
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            if (arraySelect[i][j] == 1) {
                setColor("Yellow");
                printf("  %4d    ", arrayPoints[i][j]);
            }
            else {
                setColor("Blue");
                printf("  %4d    ", arrayPoints[i][j]);
            }
        }
        printf("\n\n");
    }
    setColor("Blue");
    printf("---------------------------------------------------------\n"
           " ---------- Team One ["); HLN(1, "Red"); printf("] ------- Team Two ["); HLN(2, "Red"); printf("] ---------- \n"
           "---------------------------------------------------------\n");
}

typedef void highlightNumber(int input, char* color) {
    setColor(color);
    printf("%d", input);
    setColor("Blue");
} HLN;

// Clear Game Screen
void clearScreen() {
    printf("\e[2J\e[H");
}
