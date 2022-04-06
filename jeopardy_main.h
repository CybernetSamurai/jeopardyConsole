#define ROWS 5
#define COLS 6
#define MAX_PTS 9999

bool optionSelectionValidation(int selection);
void addPoints(int teamNumber, int ptsSelected, int selection);
void saveEnteredData(int team, int cat, int point);
void resetBoard(int arrayPoints[ROWS][COLS], int arraySelect[ROWS][COLS]);
int mainMenuUserInput(char* type);
bool colSelectValidation(int col);
bool pointSelectValidation(int points);
void setColor(char* color);
void printBoard(int arrayPoints[ROWS][COLS], int arraySelect[ROWS][COLS]);
void clearScreen(); // Code from Prof Marriott's 'movingImage.c' example
int convertPointsSelected(int points);

#define MAX_STR_LEN 250
#define FILE_NUM 6
#define FILE_LEN 14
#define QUESTION_CNT 5
#define QUESTION_TIME 10
#define BOARD_WIDTH 44

void selectCatagoryFile(int col);
void getQuestionAnswerArray(int col, int row);
void printQuestion(int col, int row);
int printAnswer(int col, int row);
