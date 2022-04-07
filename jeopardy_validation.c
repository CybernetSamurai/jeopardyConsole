// Reference used: https://stackoverflow.com/questions/42055482/how-to-reject-letter-when-requesting-int-in-c
// Request User Input for Catagory and Point Values
// If Input != int, Set Default to 0
int mainMenuUserInput(char* type) {
    int value, scanVal;
    printf("%s: ", type);
    setColor("W");
    scanVal = scanf("%d", &value);
    setColor("B");
    if (scanVal != 1) {
        getchar();
        value = 0;
    }        
    return value;
}

// Validate selection between two options
bool optionSelectionValidation(int selection) {
    bool check = false;
    if (selection == 1 || selection == 2) {
        check = true;
    }
    return check;
}

// Validate Input Column Value is Legal
bool colSelectValidation(int col) {
    bool check = false;
    int i = 0;
    for (i = 0; i < 6; ++i) {
        if (col == i) check = true;
    }
    return check;
}

// Validate Input Point Value is Legal
bool pointSelectValidation(int points) {
    bool check = false;
    int i = 200;
    for (i = 200; i < 1001; i+=200) {
        if (points == i) check = true;
    }
    return check;
}
