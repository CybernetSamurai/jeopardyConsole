/**************************************
* File:     jeopardy_test.c
* Group:  
* Version:  1.0
**************************************/

#include <stdio.h>
#include <string.h>

#define ROWS 9
#define COLS 50

void printBoard();
void clearBoard();
void setGreen();
void setRed();
void setBlue();
void setYellow();
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
   int i = 0;
   for (i; i < ROWS; ++i)
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
   printf("\033[0;34m");
}

void setYellow()
{
   printf("\033[0;33m");
}

void pointSelect(int row, int col, char board[ROWS][COLS])
{
   int i = 0, j = 0;
   for (i; i < ROWS; ++i)
      if (i == row)
      {
         for (j; j < strlen(board[i]); ++j)
         {
            setYellow();
            printf("%c\n", board[i][j]);
         }
      }
      else
      {
         setBlue();
         printf("%s\n", board[i]);
      }
}
