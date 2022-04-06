
#define ROWS 5
#define COLS 6
#define MAX_PTS 9999

bool optionSelectionValidation();
void addPoints();
bool printAnswerValidation();
void saveEnteredData();
void resetBoard();
int teamSelect();
bool teamSelectValidation();
int mainMenuUserInput(char* type);
bool colSelectValidation(int col);
bool pointSelectValidation(int pointSelect);
void setColor(char* color);
void printBoard();
void clearScreen(); // Code from Prof Marriott's 'movingImage.c' example
int convertPointsSelected(int points);
