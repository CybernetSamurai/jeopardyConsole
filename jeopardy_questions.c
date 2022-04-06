// File IO Reference Used:
// https://stackoverflow.com/questions/21114591/c-programming-read-specific-line-from-text-file?msclkid=8747c7afaae011eca26a4c7fa106a47d

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "jeopardy_main.h"

char line_list[QUESTION_CNT][MAX_STR_LEN];
char QuestionAnswer[2][MAX_STR_LEN];

// Select Catagory File
void selectCategoryFile(int col) {
    int i = 0;
    char line[MAX_STR_LEN];
    char file_list[FILE_NUM][FILE_LEN] = {
        "category1.txt",
        "category2.txt",
        "category3.txt",
        "category4.txt",
        "category5.txt",
        "category6.txt"
    };
    FILE* f = fopen(file_list[col], "r");
    // Open File, Save Each Line to List
    if ( f == NULL ) {
        printf("Error opening file.\n");
    }
    else {
        while (fgets(line, MAX_STR_LEN, f) != NULL) {
            strcpy(line_list[i], line);
            ++i;
        }
        fclose(f);
    }
}

// Select Correct Question From Catagory File
void getQuestionAnswerArray(int col, int row) {
    int i = 0, j = 0;
    selectCategoryFile(col);
    //QuestionAnswer;
    char fullString[MAX_STR_LEN]; //string containting question and answer separated by semicolon
    char question[MAX_STR_LEN];
    char answer[MAX_STR_LEN];
    strcpy(fullString, line_list[row]);
    // Save the "Question" Part of the Line in Seperate Variable
    while (fullString[i] != ';') {
        question[i] = fullString[i];
        ++i;
    }
    ++i; // Skip the Semicolon when itterating through chars
    // Save the "Answer" Part of the LIne in Seperate Varaiable
    while (fullString[i] != '\0') {
        answer[j] = fullString[i];
        ++i;
        ++j;
    }
    strcpy(QuestionAnswer[0], question);
    strcpy(QuestionAnswer[1], answer);
}

// Print Corresponding Question
void printQuestion(int col, int row) {
    int i, timer = QUESTION_TIME;
    for (i = 0; i < QUESTION_TIME; ++i) {
        getQuestionAnswerArray(col, row);
        printf("Timer: %01d\n", timer);
        printf("--------------------------------------------\n\n\n\n\n");
        printf("%s\n", QuestionAnswer[0]);
        printf("\n\n\n\n\n--------------------------------------------\n\n");
        sleep(1);
        --timer;
        clearScreen();
    }
        //printf("Press ENTER to see answer... ");
        //getchar();
        //getchar();
}

// Print Corresponding Answer 
int printAnswer(int col, int row) {
    int selection;
    getQuestionAnswerArray(col, row);
    printf("\n--------------------------------------------\n\n\n\n\n");
    printf("%s\n", QuestionAnswer[1]);
    printf("\n\n\n\n--------------------------------------------\n"
           " ----- Correct [1] ---- Incorrect [2] ----- \n"
           "--------------------------------------------\n");
    selection = mainMenuUserInput("Make Selection");
    return selection;
}

// Formats output within 44 sized desired space
// Type 0 == Question
// Type 1 == Answer
/*
void outputFormat(int col, int row, int type) {
    int i = 0, j = 0, k = 0, l = 0;
    getQuestionAnswerArray(col, row);
    char Question[MAX_STR_LEN];
    strcpy(Question, QuestionAnswer[0]);
    char Answer[MAX_STR_LEN];
    strcpy(Answer, QuestionAnswer[1]);

    while (Question[i] != '\0') {
        if (Question[i] == ' ') {
            j = i % BOARD_WIDTH;
            l = i + 1;
            while (Question[l] != ' ') {
                if (j == BOARD_WIDTH)  {
                    printf("%c", Question[i]);
                    printf("\n");
                    k = 0;
                    i += 1;
                    break;
                }
                ++l;
                ++j;
            }
        }
        if (k == BOARD_WIDTH) {
            printf("%c", Question[i]);
            printf("\n");
            k = 0;
        }
        else {
            printf("%c", Question[i]);
        }
        ++k;
        ++i;
    }    
}
*/
