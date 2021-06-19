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

void showMainMenu() {
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
    } else if (inputNumInt == 2) {
        cout << "here 2" << endl;
    } else {
        cout << "not 1 and not 2" << endl;
    }
}

Config getAdaptorOptions() {
    vector<string> lines;
    vector<string> tmp;
    vector<string> commands;
    string line;
    Config config;

    ifstream infile;
    infile.open("config.txt");

    while (getline(infile, line)) {
        if (line.empty()) {
            continue;
        }
        if (line.at(0) == '#') {
            continue;
        }
        lines.push_back(line);
    }

    for (auto &it : lines) {
        tmp = myTokenize(it);
        commands.push_back(tmp.at(0));
        commands.push_back(tmp.at(1));
    }

    for (int i=0; i<commands.size(); i+=2) {
        string cmd1 = commands.at(i);
        string cmd2 = commands.at(i+1);
        config.setFields(cmd1, cmd2);
    }

    return config;
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

vector<string> myTokenize(string line) {
    string delimiter = " = ";
    vector<string> v1;

    int pos = 0;
    string token;
    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        v1.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    v1.push_back(line);

    return v1;
}

Config::Config() {
    recordSize = 0;
    studentNameSize = 0;
    studentLastNameSize = 0;
}

const string &Config::getRecordMode() const {
    return recordMode;
}

const string &Config::getStringMode() const {
    return stringMode;
}

int Config::getRecordSize() const {
    return recordSize;
}

int Config::getStudentNameSize() const {
    return studentNameSize;
}

int Config::getStudentLastNameSize() const {
    return studentLastNameSize;
}

void Config::setFields(const std::string& field, const std::string& value) {
    if (field == "RECORD_MODE") {
        if (value == "Fix") {
            this->recordMode = value;
        } else if (value == "Dyn") {
            this->recordMode = value;
        } else {
            cout << "wrong record mode in configurations!!!" << endl;
        }
    } else if (field == "STRING_MODE") {
        if (value == "Fix") {
            this->stringMode = value;
        } else if (value == "Dyn") {
            this->stringMode = value;
        } else {
            cout << "wrong string mode in configurations!!!" << endl;
        }
    } else if (field == "RECORD_SIZE") {
        if (this->recordMode == "Dyn") {
            this->recordSize = -1;
        } else {
            this->recordSize = stoi(value);
        }
    } else if (field == "STD_NAME_SIZE") {
        if (this->stringMode == "Dyn") {
            this->studentNameSize = -1;
        } else {
            this->studentNameSize = stoi(value);
        }
    } else if (field == "STD_LAST_NAME_SIZE") {
        if (this->stringMode == "Dyn") {
            this->studentLastNameSize = -1;
        } else {
            this->studentLastNameSize = stoi(value);
        }
    } else {
        cout << "WRONG CONFIGURATION KEY!" << endl;
    }
}
