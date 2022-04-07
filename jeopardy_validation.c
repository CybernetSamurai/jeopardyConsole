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

