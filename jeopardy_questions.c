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
        printf("Timer: "); setColor("Yellow"); printf("%01d\n", timer); setColor("Blue");
        printf("============================================\n\n\n\n\n");
        setColor("Yellow");
        wrap(QuestionAnswer[0], BOARD_WIDTH);
        printf("%s\n", QuestionAnswer[0]);
        setColor("Blue");
        printf("\n\n\n\n\n============================================\n"
               "--------------------------------------------\n"
               "============================================\n");
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
    printf("\n============================================\n\n\n\n\n");
    wrap(QuestionAnswer[1], BOARD_WIDTH);
    printf("%s\n", QuestionAnswer[1]);
    printf("\n\n\n\n============================================\n");
    printf(" ----- Correct [1] ---- Incorrect [2] ----- \n");
    printf("============================================\n");
    selection = mainMenuUserInput("Make Selection");
    return selection;
}

// Formats output within 44 sized desired space
// Reference: https://stackoverflow.com/questions/22582989/word-wrap-program-c
inline int word_length(const char* input) {
    int tempindex=0;
    while (input[tempindex] != ' ' && input[tempindex] != 0 && input[tempindex] != '\n') {
        ++tempindex;
    }
    return tempindex;
}
void wrap(char* string, const int wrapline) {
    int index = 0;
    int curlinelen = 0;
    while (string[index] != '\0') {
        if (string[index] == '\n') {
            curlinelen=0;
        }
        else if (string[index] == ' ') {
            if (curlinelen + word_length(&string[index + 1]) >= wrapline) {
                string[index] = '\n';
                curlinelen = 0;
            }
        }
        curlinelen++;
        index++;
    }
}
