#include "jeopardy_main.h"

// Global Variables for Functions
char line_list[QUESTION_CNT][MAX_STR_LEN];
char QuestionAnswer[2][MAX_STR_LEN];

// Select Category File
// File IO Reference Used: https://stackoverflow.com/questions/21114591/c-programming-read-specific-line-from-text-file?msclkid=8747c7afaae011eca26a4c7fa106a47d
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
    char path[] = "Jeopardy_Categories/";
    // Define Path for File IO
    strcat(path, file_list[col]);
    FILE* f = fopen(path, "r");
    // Open Category File, Save Each Line to List
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
    //String Containting Question and Answer Separated by Semicolon
    char fullString[MAX_STR_LEN];
    strcpy(fullString, line_list[row]);
    // Empty String for Question
    char question[MAX_STR_LEN];
    //strcpy(question, "");
    // Empty String for Answer
    char answer[MAX_STR_LEN];
    //strcpy(answer, "");
    // Nullify question/answer Strings
    
    for (i = 0; i < MAX_STR_LEN; ++i) {
        question[i] = 0;
        answer[i] = 0;
    }
    
    // Save the "Question" Part of the Line in Seperate Variable
    while (fullString[i] != ';') {
        question[i] = fullString[i];
        ++i;
    }
    question[i] = '\0';
    ++i; // Skip the Semicolon
    // Save the "Answer" Part of the LIne in Seperate Varaiable
    while (fullString[i] != '\0') {
        answer[j] = fullString[i];
        ++i;
        ++j;
    }
    answer[i] = '\0';
    strcpy(QuestionAnswer[0], question);
    strcpy(QuestionAnswer[1], answer);
}

// Print Corresponding Question
void printQuestion(int col, int row) {
    int i, timer = QUESTION_TIME;
    for (i = 0; i < QUESTION_TIME; ++i) {
        getQuestionAnswerArray(col, row);
        setColor("C");
        printf("Timer");
        setColor("B");
        printf(": ");
        setColor("Y"); printf("%01d\n", timer); setColor("B");
        printf("============================================\n");
        printf(" ------------------------------------------ \n");
        printf("============================================\n\n\n\n\n");
        setColor("Y");
        wrap(QuestionAnswer[0], BOARD_WIDTH);
        printf("%s\n", QuestionAnswer[0]);
        setColor("B");
        printf("\n\n\n\n\n============================================\n");
        printf(" ------------------------------------------ \n");
        printf("============================================\n");
        sleep(1);
        --timer;
        clearScreen();
    }
}

// Print Corresponding Answer 
int printAnswer(int col, int row) {
    int selection;
    getQuestionAnswerArray(col, row);
    printf("\n============================================\n");
    printf(" ------------------------------------------ \n");
    printf("============================================\n\n\n\n\n");
    setColor("Y");
    wrap(QuestionAnswer[1], BOARD_WIDTH);
    printf("%s\n", QuestionAnswer[1]);
    setColor("B");
    printf("\n\n\n\n============================================\n");
    printf(" ----- "); setColor("C"); printf("Correct"); setColor("B"); printf(" ["); setColor("C"); printf("1"); setColor("B");
        printf("] ---- "); setColor("C"); printf("Incorrect"); setColor("B"); printf(" ["); setColor("C"); printf("2"); setColor("B");
        printf("] ----- \n");
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
