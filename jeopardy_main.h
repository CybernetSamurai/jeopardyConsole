/**************************************
* File:     jeopardy_main.h
* Authors:  Jacob Christensen
**************************************/

#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#define ROWS 5           // Number of Point Option in Game Board
#define COLS 6           // Number of Category Option in Game Board
#define MAX_PTS 9999     // Maximum Number of Points a Team can Earn
#define MAX_STR_LEN 250  // Maximum Length of Questions/Answers
#define FILE_NUM 6       // Number of Category Text Files
#define FILE_LEN 14      // Length of Category Text File Name
#define QUESTION_CNT 5   // Number of Questions per Category Text File
#define QUESTION_TIME 10 // Length of Question Timer
#define BOARD_WIDTH 44   // Length of Game Board for Question/Answer Formatting

/* Prototype Functions for .._questions.c */
void selectCategoryFile(int col);
void getQuestionAnswerArray(int col, int row);
void printQuestion(int col, int row);
int printAnswer(int col, int row);
static inline int word_length(const char* input);
void wrap(char* string, const int wrapline);

/* Prototype Functions for .._board.c */
void clearScreen(); // Code from Prof Marriott's 'movingImage.c' example
void resetBoard(int arrayPoints[ROWS][COLS], int arraySelect[ROWS][COLS]);
void SSC(char* string, char* toColor, char* outColor);
void SNC(int input, char* toColor, char* outColor);
void updatePoints(int teamNumber, int ptsSelected, int selection);
void setColor(char* color);
void printBoard(int arrayPoints[ROWS][COLS], int arraySelect[ROWS][COLS]);

/* Prototype Functions for .._validation.c */
int mainMenuUserInput(char* type);
bool optionSelectionValidation(int selection);
bool colSelectValidation(int col);
bool pointSelectValidation(int points);
void saveEnteredData(int team, int cat, int points);
int convertPointsSelected(int points);

#endif
