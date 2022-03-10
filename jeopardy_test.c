/**************************************
* File:     jeopardy_test.c
* Group:  
* Version:  1.0
**************************************/

#include <stdio.h>

#define ROWS 7
#define COLS 30

void printBoard();
void clearBoard();
void setGreen();
void setRed();

int main(void)
{
   int rowSelect, colSelect;
   char board[ROWS][COLS] = 
   {
     "----------JEOPARDY----------",
     "200    200   200   200   200",
     "400    400   400   400   400",
     "600    600   600   600   600",
     "800    800   800   800   800",
     "1000  1000  1000  1000  1000",
     "----------------------------"
   };
   
   setGreen();
   printBoard(board);
   printf("Enter row: ");
   scanf("%d", &rowSelect);
   printf("Enter col: ");
   scanf("%d", &colSelect);
}

void printBoard(char board[ROWS][COLS])
{
   int i;
   for (i = 0; i < ROWS; i++)
      printf("%s\n", board[i]);
}

void clearBoard()
{
   
}

void setGreen()
{
   printf("\033[0;32m");
}
void setRed()
{
   printf("\033[1;31m");
}
