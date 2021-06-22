#include "ui.h"

using namespace std;

#define MAX_MENU_OPTIONS 7


int showMainMenu() {    //return int number from [1(add student), 2(all students), ...]
    string inputNum;
    int inputNumInt;
    bool isValidNum;
    vector<int> size_vector;

    //system("cls");
    while (true) {
        cout << "----------Main Menu----------" << endl;
        cout << "1. Add Student\n2. All Students\n3. Find Student\n4. Add Book\n5. All Books\n6. Find Book\n7. Exit" << endl;
        cout << "Enter A Number:";

        getline(cin, inputNum);
        isValidNum = check_number(inputNum);
        if (!isValidNum) {
            //system("cls");
            cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
            continue;
        } else {
            inputNumInt = stoi(inputNum);
            if (inputNumInt <= 0 || inputNumInt > MAX_MENU_OPTIONS) {
                //system("cls");
                cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                continue;
            }
            break;
        }
    }

    //system("cls");
    return inputNumInt;
}

int getRecordSize() {
    string inputNum;
    int inputNumInt;
    bool isValid;

    while (true) {
        //system("cls");
        cout << "please enter a size for record? (from 10 to 100)" << endl;
        cout << "Enter A Size:";
        cin >> inputNum; //need change --> getline(cin, inputNumStr);
        isValid = check_number(inputNum);
        if (!isValid) {
            //system("cls");
            cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
            continue;
        } else {
            inputNumInt = stoi(inputNum);
            if (inputNumInt >= 10 && inputNumInt <= 100) {
                break;
            } else {
                //system("cls");
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
        //system("cls");
        cout << "please enter a size for name? (from 1 to 20)" << endl;
        cout << "Enter A Size:";
        cin >> inputNum; //need change --> getline(cin, inputNumStr);
        isValid = check_number(inputNum);
        if (!isValid) {
            //system("cls");
            cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
            continue;
        } else {
            inputNumInt = stoi(inputNum);
            if (inputNumInt >= 1 && inputNumInt <= 20) {
                break;
            } else {
                //system("cls");
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
        //system("cls");
        cout << "please enter a size for record? (from 1 to 30)" << endl;
        cout << "Enter A Size:";
        cin >> inputNum; //need change --> getline(cin, inputNumStr);
        isValid = check_number(inputNum);
        if (!isValid) {
            //system("cls");
            cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
            continue;
        } else {
            inputNumInt = stoi(inputNum);
            if (inputNumInt >= 1 && inputNumInt <= 30) {
                break;
            } else {
                //system("cls");
                cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                continue;
            }
        }
    }
    return inputNumInt;
}

int findObjectMenu(Object& object) {
    vector<string> fields = object.getFieldsName();
    string inputNumStr;
    int inputNum = 0;
    bool isValidNum;

    cout << "find " << object.getObjectFileName() << " by:" << endl;
    for (int i = 0; i < fields.size(); ++i) {
        cout << i+1 << ". " << fields.at(i) << endl;
    }

    while (true) {
        getline(cin, inputNumStr);
        isValidNum = check_number(inputNumStr);
        if (!isValidNum) {
            //system("cls");
            cout << "!! PLEASE ENTER A VALID STUDENT ID !!" << endl;
            continue;
        } else {
            inputNum = stoi(inputNumStr);
            if (inputNum >= 1 && inputNum <= fields.size()) {
                break;
            } else {
                //system("cls");
                cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                continue;
            }
        }
    }

    return inputNum;
}