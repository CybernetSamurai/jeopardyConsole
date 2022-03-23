#include <stdio.h>

void printQuestion(int row, int col)
{
  int temp;
  char line[1000];
  char fileList[6][10] = {
                            "category1",
                            "category2",
                            "category3",
                            "category4",
                            "category5",
                            "category6"
                         };
  
  //printf("%s\n", fileList[col]);
  //printf("hello world");
  //scanf("%d", &temp);
  FILE *f = fopen(col, "r");
  if (f == NULL) printf("Error opening file.\n");
  char c[1000];
  // reads text until newline is encountered
  fscanf(f, "%s", line);
  printf("%s\n", line);
  fclose(f);
  printf("yes or no");
  scanf("%d", &temp);
}
