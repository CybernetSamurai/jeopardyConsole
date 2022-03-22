/**************************************
* File:     jeopardy_main.c
* Group:  
* Version:  1.0
**************************************/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "jeopardy_questions.h"

#define ROWS 5
#define COLS 6

void setBlue();
void setYellow();
void printBoard();
void clearScreen(); // Code from Prof Marriott's 'movingImage.c' example
//void printQuestion();

int main(void)
{
    bool check = true;
    int rowSelect = 100, colSelect = 100, pointSelect = 0;
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
        clearScreen();
        setBlue();
        printBoard(arrayPoints, arraySelect);
        printf("Catagory Num: ");
        scanf("%d", &colSelect);
        colSelect-=1;
        printf("Points: ");
        scanf("%d", &pointSelect);
        switch (pointSelect) {
            case 200:
                rowSelect = 0;
                break;
            case 400:
                rowSelect = 1;
                break;
            case 600:
                rowSelect = 2;
                break;
            case 800:
                rowSelect = 3;
                break;
            case 1000:
                rowSelect = 4;
                break;
            default:
                printf("Error\n");
        }
        arraySelect[rowSelect][colSelect] = 1;
        clearScreen();
        printQuestion(rowSelect, colSelect);
        
    }
}

void setBlue() {
    printf("\033[0;34m");
}

void setYellow() {
    printf("\033[0;33m");
}

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
                setYellow();
                printf("%4d    ", arrayPoints[i][j]);
            }
            else {
                setBlue();
                printf("%4d    ", arrayPoints[i][j]);
            }
        }
        printf("\n\n");
    }
    setBlue();
    printf("--------------------------------------------\n");
}

void clearScreen() {
    printf("\e[2J\e[H");
}

//void printQuestion(int row, int col) {
//    char testQuestion[100] = "What is the meaning of life?";
//    int test;
//    
//    printf(" _____       _                                       \n"
//           "/  __ \\     | |                                     \n"
//           "| /  \\/ __ _| |_ ___  __ _  ___  _ __ _   _         \n"
//           "| |    / _` | __/ _ \\/ _` |/ _ \\| '__| | | |       \n"
//           "| \\__/\\ (_| | ||  __/ (_| | (_) | |  | |_| |        \n"
//           " \\____/\\__,_|\\__\\___|\\__, |\\___/|_|   \\__, |   \n"
//           "                      __/ |            __/ |         \n"
//           "                     |___/            |___/          \n"
//           "     _   _____  _____  _____                         \n"
//           "    | | / __  \\|  _  ||  _  |                       \n"
//           "   / __)`' / /'| |/' || |/' |                        \n"
//           "   \\__ \\  / /  |  /| ||  /| |                      \n"
//           "   (   /./ /___\\ |_/ /\\ |_/ /                      \n"
//           "    |_| \\_____/ \\___/  \\___/                      \n");
//    printf("--------------------------------------------         \n");
//                                            
//                                                       
//                                            
//                                            
//    printf("%s\n", &testQuestion);
//    printf("Yes or no ");
//    scanf("%d", &test);
//}


