#include <stdio.h>

void printQuestion(int row, int col)
{
  int temp;
  char line[1000];
  char fileList[6][14] = {
                            "category1.txt",
                            "category2.txt",
                            "category3.txt",
                            "category4.txt",
                            "category5.txt",
                            "category6.txt"
                         };
  
  //printf("%s\n", fileList[col]);
  //printf("hello world");
  //scanf("%d", &temp);
  FILE *f = fopen(fileList[col], "r");
  if (f == NULL) printf("Error opening file.\n");
  char c[1000];
  // reads text until newline is encountered
  fscanf(f, "%s", line);
  printf("%s\n", line);
  fclose(f);
  printf("yes or no");
  scanf("%d", &temp);
}
