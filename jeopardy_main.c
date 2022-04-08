/**************************************
* File:     jeopardy_main.c
* Group:    Jeopardy Game
* Authors:  Jacob, Jackson, Annabelle
**************************************/

#include "jeopardy_main.h"

// Main Function
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
        teamNumber = mainMenuUserInput("Team Select: ");
        while (!optionSelectionValidation(teamNumber)) {
            resetBoard(arrayPoints, arraySelect);
            teamNumber = mainMenuUserInput("Team Select: ");
        }
        colSelected = mainMenuUserInput("Catagory: ");
        colSelected -= 1;
        while (!colSelectValidation(colSelected)) {
            resetBoard(arrayPoints, arraySelect);
            saveEnteredData(teamNumber,0,0);
            colSelected = mainMenuUserInput("Catagory: ");
            colSelected -= 1;
        }
        ptsSelected = mainMenuUserInput("Points: ");
        while (!pointSelectValidation(ptsSelected)) {
            resetBoard(arrayPoints, arraySelect);
            saveEnteredData(teamNumber,colSelected + 1,0);
            ptsSelected = mainMenuUserInput("Points: ");
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
