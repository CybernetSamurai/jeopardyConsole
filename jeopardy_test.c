/**************************************
* File:     jeopardy_test.c
* Group:  
* Version:  1.0
**************************************/

#include <stdio.h>

#define ROWS 9
#define COLS 50

void printBoard();
void clearBoard();
void setGreen();
void setRed();
void setBlue();
void pointSelect();

int main(void)
{
   int rowSelect = 0, colSelect = 0;
   char board[ROWS][COLS] = 
   {
     "----------------JEOPARDY----------------",
     "CAT1     CAT2     CAT3     CAT4     CAT5",
     "----------------------------------------",
     "200      200      200      200      200",
     "400      400      400      400      400",
     "600      600      600      600      600",
     "800      800      800      800      800",
     "1000    1000     1000     1000     1000",
     "----------------------------------------"
   };
   
   setBlue();
   printBoard(board);
   printf("Enter row: ");
   scanf("%d", &rowSelect);
   printf("Enter col: ");
   scanf("%d", &colSelect);
   pointSelect(rowSelect, colSelect, board);
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

void setBlue()
{
   printf("\033[0;35m");
}

void pointSelect(int row, int col, char board[ROWS][COLS])
{
   printf("%s\n", board[row]);
}
