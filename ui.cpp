#include "ui.h"

using namespace std;


bool check_number(const string &str) {
    for (char i : str) {
        if (isdigit(i) == 0) {
            return false;
        }
    }
    return true;
}

vector<int> showMainMenu() {
    string inputNum;
    int inputNumInt;
    bool isValidNum;
    vector<int> size_vector;

    system("cls");
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
        size_vector = showAdaptorOptions();
        return size_vector;
    } else if (inputNumInt == 2) {
        cout << "here 2" << endl;
    } else {
        cout << "not 1 and not 2" << endl;
    }
}


vector<int> showAdaptorOptions() {
    string inputNum;
    int inputNumInt;
    bool isValid;
    int recordSize = 0;
    int nameSize = 0;
    int lastNameSize = 0;
    int optionType;

    while (true) {
        system("cls");
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
        system("cls");
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

    system("cls");
    cout << "record size: " << recordSize << "\nname size: " << nameSize << "\nlast name size: " << lastNameSize << endl;
    if (recordSize == 0) {
        if (nameSize == 0 || lastNameSize == 0) {
            cout << "dyn rec dyn str" << endl;
            optionType = 1;
        } else {
            cout << "dyn rec fix str" << endl;
            optionType = 2;
        }
    } else {
        if (nameSize == 0 || lastNameSize == 0) {
            cout << "fix rec dyn str" << endl;
            optionType = 3;
        } else {
            cout << "fix rec fix str" << endl;
            optionType = 4;
        }
    }
    vector<int> v1;
    v1.push_back(optionType);
    v1.push_back(recordSize);
    v1.push_back(nameSize);
    v1.push_back(lastNameSize);

    return v1;
}

int getRecordSize() {
    string inputNum;
    int inputNumInt;
    bool isValid;

    while (true) {
        system("cls");
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
        system("cls");
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
        system("cls");
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