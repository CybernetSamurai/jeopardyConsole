#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
//#include <stdlib.h>

/* Definition and Prototype Function for jeopardy_main.c */
#define ROWS 5       // Number of Point Selections
#define COLS 6       // Number of Categories
#define MAX_PTS 9999 // Maximum Number of Points a Team can Earn

bool optionSelectionValidation(int selection);
void updatePoints(int teamNumber, int ptsSelected, int selection);
void saveEnteredData(int team, int cat, int point);
void resetBoard(int arrayPoints[ROWS][COLS], int arraySelect[ROWS][COLS]);
int mainMenuUserInput(char* type);
bool colSelectValidation(int col);
bool pointSelectValidation(int points);
void setColor(char* color);
void printBoard(int arrayPoints[ROWS][COLS], int arraySelect[ROWS][COLS]);
void clearScreen(); // Code from Prof Marriott's 'movingImage.c' example
int convertPointsSelected(int points);
void SNC(int input, char* color);
void SSC(char* string, char* toColor, char* outColor);

/* Definition and Prototype Function for jeopardy_questions.c */
#define MAX_STR_LEN 250  // Maximum Length of Questions/Answers
#define FILE_NUM 6       // Number of Category Text Files
#define FILE_LEN 14      // Length of Category Text File Name
#define QUESTION_CNT 5   // Number of Questions per Category Text File
#define QUESTION_TIME 10 // Length of Question Timer
#define BOARD_WIDTH 44   // Length of Game Board for Question Formatting

void selectCatagoryFile(int col);
void getQuestionAnswerArray(int col, int row);
void printQuestion(int col, int row);
int printAnswer(int col, int row);
inline int word_length(const char* input);
void wrap(char* string, const int wrapline);
