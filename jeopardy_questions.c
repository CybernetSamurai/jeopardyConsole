#include <stdio.h>

void printQuestion(int row, int col)
{
  int temp, loop_cnt = 0, line_number;
  char line_max[5];
  char fileList[6][14] = {
                            "category1.txt",
                            "category2.txt",
                            "category3.txt",
                            "category4.txt",
                            "category5.txt",
                            "category6.txt"
                         };
  
  if (f == NULL) printf("Error opening file.\n");
  // reads text until newline is encountered
  fscanf(f, "%[^;]", line);
  printf("%s\n", line);
  fclose(f);
  printf("yes or no");
  scanf("%d", &temp);
  
  lineNumber = x;
  
  FILE *f = fopen(fileList[col], "r");
  if ( f != NULL )
  {
      while (fgets(line_max, 6, f) != NULL) /* read a line */
      {
          if (loop_cnt == line_number)
          {
            printf("%s\n", line_max);
              //use line or in a function return it
              //in case of a return first close the file with "fclose(file);"
          }
          else
          {
              ++loop_cnt;
          }
      }
      fclose(file);
  }
  else
  {
      //file doesn't exist
    printf("Error opening file.\n")
  }
}
