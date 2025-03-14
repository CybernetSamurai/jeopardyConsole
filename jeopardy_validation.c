/**************************************
* File:     jeopardy_validation.c
* Authors:  Jacob Christensen
**************************************/

#include "jeopardy_main.h"

// Reference used: https://stackoverflow.com/questions/42055482/how-to-reject-letter-when-requesting-int-in-c
// Request User Input for Catagory and Point Values
// If Input != int, Set Default to 0
int mainMenuUserInput(char* type) {
    int value, scanVal;
    SSC(type, "C", "W");
    scanVal = scanf("%d", &value);
    if (scanVal != 1) {
        getchar();
        value = 0;
    }        
    return value;
}

// Validate Selection Between Two Options (1 or 2)
bool optionSelectionValidation(int selection) {
    bool check = false;
    if (selection == 1 || selection == 2) {
        check = true;
    }
    return check;
}

// Validate User Input Column Value
bool colSelectValidation(int col) {
    bool check = false;
    int i = 0;
    for (i = 0; i < 6; ++i) {
        if (col == i) check = true;
    }
    return check;
}

// Validate User Input Point Value
bool pointSelectValidation(int points) {
    bool check = false;
    int i = 200;
    for (i = 200; i < 1001; i+=200) {
        if (points == i) check = true;
    }
    return check;
}

// Remembers Previous User Input if Validation Fails
void saveEnteredData(int team, int cat, int points) {
    if (team != 0) {
        SSC("Team Select: ", "C", "W");
        printf("%d\n", team);
        setColor("B");
    }
    if (cat != 0) {
        SSC("Catagory: ", "C", "W");
        printf("%d\n", cat);
        setColor("B");
    }
    if (points != 0) {
        SSC("Points: ", "C", "W");
        printf("%d\n", points);
        setColor("B");
    }
}

// Convert User Input Point Value to Related Row Value
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
