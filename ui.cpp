#include "ui.h"
#include <iostream>
#include <string>
//#include <cstdlib>

using namespace std;


bool check_number(const string &str) {
    for (char i : str) {
        if (isdigit(i) == 0) {
            return false;
        }
    }
    return true;
}

void showMainMenu() {
    string inputNum;
    int inputNumInt;
    bool isValidNum;

    while (true) {
        cout << "1. Add Student\n2. Add Book" << endl;
        cout << "Enter A Number:";

        cin >> inputNum;
        isValidNum = check_number(inputNum);
        if (!isValidNum) {
            system("cls");
            cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
            continue;
        } else {
            inputNumInt = stoi(inputNum);
            if (inputNumInt <= 0 || inputNumInt > 2) {
                system("cls");
                cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                continue;
            }
            break;
        }
    }

    if (inputNumInt == 1) {
        system("cls");
        showAdaptorOptions();
    } else if (inputNumInt == 2) {
        cout << "here 2" << endl;
    } else {
        cout << "not 1 and not 2" << endl;
    }
}


void showAdaptorOptions() {
    string inputNum;
    int inputNumInt;
    bool isValid;
    int recordSize = 0;
    int nameSize = 0;
    int lastNameSize = 0;

    while (true) {
        cout << "Do you want to set a record size?(0 for no/1 for yes)" << endl;
        cout << "Enter A Number (0/1):";
        cin >> inputNum;
        isValid = check_number(inputNum);
        if (!isValid) {
            system("cls");
            cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
            continue;
        } else {
            inputNumInt = stoi(inputNum);
            if (inputNumInt == 0 || inputNumInt == 1) {
                break;
            } else {
                system("cls");
                cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                continue;
            }
        }
    }
    if (inputNumInt == 1) {
        recordSize = getRecordSize();
    }

    while (true) {
        cout << "Do you want to set a name and last name size?(0 for no/1 for yes)" << endl;
        cout << "Enter A Number (0/1):";
        cin >> inputNum;
        isValid = check_number(inputNum);
        if (!isValid) {
            system("cls");
            cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
            continue;
        } else {
            inputNumInt = stoi(inputNum);
            if (inputNumInt == 0 || inputNumInt == 1) {
                break;
            } else {
                system("cls");
                cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                continue;
            }
        }
    }
    if (inputNumInt == 1) {
        nameSize = getNameStrSize();
        lastNameSize = getLastNameStrSize();
    }


    cout << "record size: " << recordSize << "\nname size: " << nameSize << "\nlast name size: " << lastNameSize << endl;
    if (recordSize == 0) {
        if (nameSize == 0 || lastNameSize == 0) {
            cout << "dyn rec dyn str" << endl;
        } else {
            cout << "dyn rec fix str" << endl;
        }
    } else {
        if (nameSize == 0 || lastNameSize == 0) {
            cout << "fix rec dyn str" << endl;
        } else {
            cout << "fix rec fix str" << endl;
        }
    }
}

int getRecordSize() {
    string inputNum;
    int inputNumInt;
    bool isValid;

    while (true) {
        cout << "please enter a size for record? (from 10 to 100)" << endl;
        cout << "Enter A Size:";
        cin >> inputNum;
        isValid = check_number(inputNum);
        if (!isValid) {
            system("cls");
            cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
            continue;
        } else {
            inputNumInt = stoi(inputNum);
            if (inputNumInt >= 10 && inputNumInt <= 100) {
                break;
            } else {
                system("cls");
                cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                continue;
            }
        }
    }
    return inputNumInt;
}

int getNameStrSize() {
    string inputNum;
    int inputNumInt;
    bool isValid;

    while (true) {
        cout << "please enter a size for name? (from 1 to 20)" << endl;
        cout << "Enter A Size:";
        cin >> inputNum;
        isValid = check_number(inputNum);
        if (!isValid) {
            system("cls");
            cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
            continue;
        } else {
            inputNumInt = stoi(inputNum);
            if (inputNumInt >= 1 && inputNumInt <= 20) {
                break;
            } else {
                system("cls");
                cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                continue;
            }
        }
    }
    return inputNumInt;
}

int getLastNameStrSize() {
    string inputNum;
    int inputNumInt;
    bool isValid;

    while (true) {
        cout << "please enter a size for record? (from 1 to 30)" << endl;
        cout << "Enter A Size:";
        cin >> inputNum;
        isValid = check_number(inputNum);
        if (!isValid) {
            system("cls");
            cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
            continue;
        } else {
            inputNumInt = stoi(inputNum);
            if (inputNumInt >= 1 && inputNumInt <= 30) {
                break;
            } else {
                system("cls");
                cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                continue;
            }
        }
    }
    return inputNumInt;
}