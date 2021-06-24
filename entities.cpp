#include <iostream>
#include "entities.h"

using namespace std;

string Object::getObjectFileName() {
    return this->objectFileName;
}

const vector<string> &Object::getFieldsName() const {
    return fieldsName;
}

int Object::objectCount() {
    int objectsCount = 0;
    try {
        while (true) {
            this->read(objectsCount + 1);
            objectsCount++;
        }
    } catch (out_of_range &e) {
        return objectsCount;
    } catch (fstream::failure &e) {
        throw e;
    }
}

void Object::printAllObjects() {
    try {
        int objectsCount = this->objectCount();
        cout << "number of " << this->objectFileName << " : " << objectsCount << endl;

        for (int i = 1; i <= objectsCount; ++i) {
            this->read(i);
            cout << *(Student *) this;
        }
    } catch (ifstream::failure &exc) {
        cout << "\aERROR: Can't Open This File" << endl;
    }
}

Student::Student(Adaptor *adaptor, int studentID, const string &name, const string &lastName) : studentID(studentID),
                                                                                                name(name),
                                                                                                lastName(lastName) {
    this->objAdaptor = adaptor;
    this->objectFileName = constFileName;
    string fileName = this->objectFileName + ".txt";
    this->objAdaptor->setFileName(fileName);
    this->fieldsName = constFieldsName;
}

Student::Student(Adaptor *adaptor) {
    studentID = 0;
    name = "";
    lastName = "";
    this->objAdaptor = adaptor;
    this->objectFileName = constFileName;
    string fileName = this->objectFileName + ".txt";
    this->objAdaptor->setFileName(fileName);
    this->fieldsName = constFieldsName;
}

void Student::add() {
    Config conf = objAdaptor->getAdpConf();
    int recordSize;
    int id = this->studentID;
    int idSize = sizeof(int);
    int nameSize;
    int lastNameSize;

    if (conf.getRecordMode() == "Fix" && conf.getStringMode() == "Fix") {
        nameSize = conf.getStudentNameSize();
        lastNameSize = conf.getStudentLastNameSize();
        recordSize = conf.getRecordSize();
    } else if (conf.getRecordMode() == "Fix" && conf.getStringMode() == "Dyn") {
        nameSize = this->name.size();
        lastNameSize = this->lastName.size();
        recordSize = conf.getRecordSize();
    } else if (conf.getRecordMode() == "Dyn" && conf.getStringMode() == "Fix") {
        nameSize = conf.getStudentNameSize();
        lastNameSize = conf.getStudentLastNameSize();
        recordSize = idSize + sizeof(int) + nameSize + sizeof(int) + lastNameSize;
    } else {    //Dynamic Record Dynamic String
        nameSize = this->name.size();
        lastNameSize = this->lastName.size();
        recordSize = idSize + sizeof(int) + nameSize + sizeof(int) + lastNameSize;
    }

    objAdaptor->setRecSize(recordSize);

    objAdaptor->setRecord();
    objAdaptor->setIntField(id);
    objAdaptor->setField(nameSize, this->name);
    objAdaptor->setField(lastNameSize, this->lastName);
}

vector<int> Student::find(int option) {
    string input;
    int inputNum;
    bool isValidNum;
    vector<int> idList;
    int objectsCount;

    try {
        objectsCount = this->objectCount();
    } catch (fstream::failure &exp) {
        cout << "\aERROR: Can't Open This File" << endl;
        return {};
    }


    switch (option) {
        case 1: //find by id
            while (true) {
                cout << "Enter Student Id: " << endl;
                getline(cin, input);
                isValidNum = check_number(input);
                if (!isValidNum) {
                    //system("cls");
                    cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                    continue;
                } else {
                    inputNum = stoi(input);
                    break;
                }
            }
            for (int i = 1; i <= objectsCount; ++i) {
                this->read(i);
                if (this->studentID == inputNum) {
                    idList.push_back(i);
                }
            }
            if (idList.empty()) {
                cout << "\aStudent With Id \'" << inputNum << "\' NOT FOUND" << endl;
            }
            return idList;
        case 2: //find by name
            cout << "Enter Student Name: " << endl;
            getline(cin, input);
            for (int i = 1; i <= objectsCount; ++i) {
                this->read(i);
                if (this->name == input) {
                    idList.push_back(i);
                }
            }
            if (idList.empty()) {
                cout << "\aStudent With Name \'" << input << "\' NOT FOUND" << endl;
            }
            return idList;
        case 3: //find by last name
            cout << "Enter Student Last Name: " << endl;
            getline(cin, input);
            for (int i = 1; i <= objectsCount; ++i) {
                this->read(i);
                if (this->lastName == input) {
                    idList.push_back(i);
                }
            }
            if (idList.empty()) {
                cout << "\astudent with id \'" << input << "\' NOT FOUND" << endl;
            }
            return idList;
        default:
            return idList;
    }
}

void Student::read(int index) {
    int startIndex = 0;
    int stdId;
    string stdName;
    string stdLastName;

    try {
        startIndex = objAdaptor->getRecord(index);
    } catch (out_of_range &e) {
        throw e;
    } catch (ifstream::failure &e) {
        throw e;
    }

    stdId = objAdaptor->getIntField(startIndex);
    stdName = objAdaptor->getField(startIndex);
    stdLastName = objAdaptor->getField(startIndex);

    this->studentID = stdId;
    this->name = stdName;
    this->lastName = stdLastName;
}

void Student::edit(int option, int index) {
    string input;
    int inputNum;
    bool isValidNum;
    int startIndex;
    int newRecSize;

    try {
        startIndex = objAdaptor->getRecord(index);
    } catch (out_of_range &e) {
        throw e;
    } catch (ifstream::failure &e) {
        throw e;
    }

    switch (option) {
        case 1: //edit student id
            while (true) {
                cout << "Edit Student Id: " << endl;
                getline(cin, input);
                isValidNum = check_number(input);
                if (!isValidNum) {
                    //system("cls");
                    cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                    continue;
                } else {
                    inputNum = stoi(input);
                    break;
                }
            }
            objAdaptor->editIntField(startIndex, inputNum);
            break;
        case 2: //edit student name
        {
            cout << "Edit Student Name: " << endl;
            getline(cin, input);
            if (objAdaptor->getAdpConf().getStringMode() == "Dyn") {
                newRecSize = sizeof(int) + sizeof(int) + input.size() + sizeof(int) + lastName.size();
                objAdaptor->editIntField(startIndex-8, newRecSize);
            }
            startIndex += sizeof(int); //size of student id field
            int nameSize = objAdaptor->getIntField(startIndex);
            objAdaptor->editField(startIndex, nameSize, input);
        }
            break;
        case 3: //edit student last name
            cout << "Edit Student Last Name: " << endl;
            getline(cin, input);
            if (objAdaptor->getAdpConf().getStringMode() == "Dyn") {
                newRecSize = sizeof(int) + sizeof(int) + name.size() + sizeof(int) + input.size();
                objAdaptor->editIntField(startIndex-8, newRecSize);
            }
            startIndex = startIndex + sizeof(int) + sizeof(int) + name.size();
            int nameSize = objAdaptor->getIntField(startIndex);
            objAdaptor->editField(startIndex, nameSize, input);
            break;
    }
}

int Student::getStudentId() {
    return studentID;
}

string Student::getName() {
    return name;
}

string Student::getLastName() {
    return lastName;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << student.studentID << " | " << student.name << " | " << student.lastName << std::endl;
    return os;
}

Book::Book(int id, const string &name, const string &author) : id(id), name(name), author(author) {
    this->objectFileName = "books";
}

Student getStudent(Adaptor *adaptor, int nameSz, int lastNameSz) {
    string name;
    string lastName;
    string stdNoStr;
    int stdNo;
    bool isValidNum;

    cout << "-----------STUDENT FORM-----------" << endl;
    cout << "name SZ: " << nameSz << "last name SZ: " << lastNameSz << endl;
    while (true) {
        cout << "enter student name: ";
        getline(cin, name);
        cout << "name length" << name.length() << endl;
        if (name.length() > nameSz) {
            cout << "name is too long\nTRY AGAIN!" << endl;
            continue;
        } else break;
    }
    while (true) {
        cout << "enter student last name: ";
        getline(cin, lastName);
        cout << "last name length" << lastName.length() << endl;
        if (lastName.length() > lastNameSz) {
            cout << "last name is too long\nTRY AGAIN!" << endl;
            continue;
        } else break;
    }
    while (true) {
        cout << "enter student id: ";
        getline(cin, stdNoStr);
        isValidNum = check_number(stdNoStr);
        if (!isValidNum) {
            //system("cls");
            cout << "!! PLEASE ENTER A VALID STUDENT ID !!" << endl;
            continue;
        } else {
            stdNo = stoi(stdNoStr);
            break;
        }
    }

    Student s(adaptor, stdNo, name, lastName);
//    system("cls");
    return s;
}

bool check_number(const string &str) {
    if (str.empty()) return false;
    for (char i : str) {
        if (isdigit(i) == 0) {
            return false;
        }
    }
    return true;
}