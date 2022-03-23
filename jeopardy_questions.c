#include <stdio.h>

void printQuestion(int row, int col) {
   int temp, loop_cnt = 0;
   char line_max[1000];
   char fileList[6][14] = {
                              "category1.txt",
                              "category2.txt",
                              "category3.txt",
                              "category4.txt",
                              "category5.txt",
                              "category6.txt"
                          };
  
  //if (f == NULL) printf("Error opening file.\n");
  //fscanf(f, "%[^;]", line);
  //printf("%s\n", line);
  
   FILE *f = fopen(fileList[col], "r");
   if ( f == NULL ) {
      printf("Error opening file.\n");
   }
   else {
      while (fgets(line_max, 1000, f) != NULL) {
         if (loop_cnt == row) {
             printf("%s\n", line_max);
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
