/**************************************
* File:     jeopardy_test.c
* Group:  
* Version:  1.0
**************************************/

#include <stdio.h>

#define ROWS 7
#define COLS 30

void printBoard();

int main(void)
{
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
   
   printBoard(board);
}

void printBoard(char board[ROWS][COLS])
{
   int i;
   for (i = 0; i < ROWS; i++)
      printf("%s\n", board[i]);
}
