#include <stdio.h>

void printQuestion(int row, int col)
{
  char fileList[6][10] = {
                            "category1",
                            "category2",
                            "category3",
                            "category4",
                            "category5",
                            "category6"
                         };
  //char cat;
  printf("%s\n", fileList[col - 1]);
  //FILE* f = fopen(cat, "r");
  //if (f == NULL)
  //  printf("Error opening file.\n");
}
