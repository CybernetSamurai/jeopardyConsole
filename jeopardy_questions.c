// File IO Reference Used:
// https://stackoverflow.com/questions/21114591/c-programming-read-specific-line-from-text-file?msclkid=8747c7afaae011eca26a4c7fa106a47d

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_LEN 250

char** QuestionAnswer(int row, int col) {
    int temp, loop_cnt = 0;
    char line[MAX_STR_LEN];
    char line_list[5][MAX_STR_LEN];
    char file_list[6][14] = {
        "category1.txt",
        "category2.txt",
        "category3.txt",
        "category4.txt",
        "category5.txt",
        "category6.txt"
    };
   
    FILE *f = fopen(file_list[col], "r");

    // Open File, Save Each Line to List
    if ( f == NULL ) {
        printf("Error opening file.\n");
    }
    else {
        while (fgets(line, MAX_STR_LEN, f) != NULL) {
            strcpy(line_list[loop_cnt], line);
            ++loop_cnt;
         }
         fclose(f);
    }
   
    int i = 0, j = 0;
    char fullString[MAX_STR_LEN]; 
    strcpy(fullString, line_list[row]);
    char question[MAX_STR_LEN];
    char answer[MAX_STR_LEN];
    
    // Save the "Question" Part of the Line in Seperate Variable
    while (fullString[i] != ';') {
        question[i] = fullString[i];
        ++i;
    }

    ++i; // Skip the Semicolon

    // Save the "Answer" Part of the LIne in Seperate Varaiable
    while (fullString[i] != '\0') {
        answer[j] = fullString[i];
        ++i;
        ++j;
    }

    char** QuestionAnswer;
    QuestionAnswer = (char**)malloc(2 * sizeof(char *));
    for (i = 0; i < 2; ++i) {
        *QuestionAnswer = (char*)malloc(100 * sizeof(char));
    }

    strcpy(QuestionAnswer[0], question);
    strcpy(QuestionAnswer[1], answer);

    //printf("%s\n", question);
    //printf("%s\n", answer);
    printf("%s\n", QuestionAnswer[0]);
    printf("%s\n", QuestionAnswer[1]);

   // return QuestionAnswerPtr;
  
    printf("yes or no");
    scanf("%d", &temp);
}
