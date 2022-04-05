/**************************************
* File:     jeopardy_main.c
* Group:    Jeopardy Game
* Authors:  Jacob, Jackson, Annabelle
**************************************/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "jeopardy_questions.h"

#define ROWS 5
#define COLS 6

int mainMenuUserInput(char* type);
bool colSelectValidation(int col);
bool pointSelectValidation(int pointSelect);
void setColor(char* color);
void printBoard();
void clearScreen(); // Code from Prof Marriott's 'movingImage.c' example
int convertPointsSelected(int points);

int main(void)
{
    bool check = true;
    int rowSelected, colSelected, ptsSelected;
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
        do {
            clearScreen();

            setColor("Blue");

            printBoard(arrayPoints, arraySelect);

            colSelected = mainMenuUserInput("Catagory");
            colSelected -= 1;

            ptsSelected = mainMenuUserInput("Points");

        } while (!colSelectValidation(colSelected) || !pointSelectValidation(ptsSelected));

            rowSelected = convertPointsSelected(ptsSelected);

            arraySelect[rowSelected][colSelected] = 1;

            clearScreen();

            getQuestionAnswer(rowSelected, colSelected);
    }
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
    if (strcmp(color, "Blue")) {
        printf("\033[0;33m");
    }
    if (strcmp(color, "Yellow")) {
        printf("\033[0;34m");
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
    printf("   ___                                _       \n"
           "  |_  |                              | |      \n"
           "    | | ___  ___  _ __   __ _ _ __ __| |_   _ \n"
           "    | |/ _ \\/ _ \\| '_ \\ / _` | '__/ _` | | | |\n"
           "/\\__/ /  __/ (_) | |_) | (_| | | | (_| | |_| |\n"
           "\\____/ \\___|\\___/| .__/ \\__,_|_|  \\__,_|\\__, |\n"
           "                 | |                     __/ |\n"
           "                 |_|                    |___/ \n");


    printf("--------------------------------------------\n"
           "CAT1    CAT2    CAT3    CAT4    CAT5    CAT6\n"
           "--------------------------------------------\n\n");
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            if (arraySelect[i][j] == 1) {
                setColor("Yellow");
                printf("%4d    ", arrayPoints[i][j]);
            }
            else {
                setColor("Blue");
                printf("%4d    ", arrayPoints[i][j]);
            }
        }
        printf("\n\n");
    }
    setColor("Blue");
    printf("--------------------------------------------\n");
}

// Clear Game Screen
void clearScreen() {
    printf("\e[2J\e[H");
}
