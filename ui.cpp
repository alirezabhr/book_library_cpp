#include "ui.h"

using namespace std;

#define MAX_MENU_OPTIONS 9


int showMainMenu() {    //return int number from [1(add student), 2(all students), ...]
    string inputNum;
    int inputNumInt;
    bool isValidNum;
    vector<int> size_vector;

    //system("cls");
    while (true) {
        cout << "----------Main Menu----------" << endl;
        cout << "1. Add Student\n2. All Students\n3. Find Student\n4. Edit Student\n5. Add Book\n6. All Books\n7. Find Book\n8. Edit Book\n9. Exit" << endl;
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

    for (int i = 0; i < fields.size(); ++i) {
        cout << i+1 << ". " << object.getObjectFileName() << fields.at(i) << endl;
    }

    while (true) {
        cout << "Find " << object.getObjectFileName() << " By:" << endl;
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

int editObjectMenu(Object& object) {
    vector<string> fields = object.getFieldsName();
    string inputNumStr;
    int inputNum = 0;
    bool isValidNum;

    for (int i = 0; i < fields.size(); ++i) {
        cout << i+1 << ". " << fields.at(i) << endl;
    }

    while (true) {
        cout << "Edit " << object.getObjectFileName() << " By:" << endl;
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