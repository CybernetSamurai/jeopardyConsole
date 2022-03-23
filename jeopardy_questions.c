// Resource:
// https://stackoverflow.com/questions/21114591/c-programming-read-specific-line-from-text-file?msclkid=8747c7afaae011eca26a4c7fa106a47d

#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 250

void printQuestion(int row, int col) {
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
   
   printf("%s\n", line_list[row]);
   printf("yes or no");
   scanf("%d", &temp);
}
