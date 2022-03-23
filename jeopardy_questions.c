#include <stdio.h>

void printQuestion(int row, int col) {
   int temp, loop_cnt = 0;
   char line[1000];
   char fileList[6][14] = {
                              "category1.txt",
                              "category2.txt",
                              "category3.txt",
                              "category4.txt",
                              "category5.txt",
                              "category6.txt"
                          };
  
   //fscanf(f, "%[^;]", line);
   //printf("%s\n", line);
   
   // Resource:
   // https://stackoverflow.com/questions/21114591/c-programming-read-specific-line-from-text-file?msclkid=8747c7afaae011eca26a4c7fa106a47d
   FILE *f = fopen(fileList[col], "r");
   if ( f == NULL ) {
      printf("Error opening file.\n");
   }
   else {
      while (fgets(line, sizeof line, f) != NULL) {
         if (loop_cnt == row) {
            fscanf(f, "%[^;]", line);
            printf("%s\n", line);
            //use line or in a function return it
            //in case of a return first close the file with "fclose(file);"
         }
         else {
            ++loop_cnt;
         }
      }
      fclose(f);
   }
   printf("yes or no");
   scanf("%d", &temp);
}
