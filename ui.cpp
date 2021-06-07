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
            if (inputNumInt <= 0 || inputNumInt >= 2) {
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
        cout << "2" << endl;
    } else {
        cout << "not 1 and not 2" << endl;
    }
}


