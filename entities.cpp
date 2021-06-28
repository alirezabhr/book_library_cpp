#include <iostream>
#include "entities.h"

#include <ostream>

using namespace std;

Student getStudent(Adaptor *adaptor, int nameSz, int lastNameSz) {
    string name;
    string lastName;
    string stdNoStr;
    int stdNo;
    bool isValidNum;

    cout << "-----------STUDENT FORM-----------" << endl;
    while (true) {
        cout << "enter student name: ";
        getline(cin, name);
        if (name.length() > nameSz) {
            cout << "name is too long\nTRY AGAIN!" << endl;
            continue;
        } else break;
    }
    while (true) {
        cout << "enter student last name: ";
        getline(cin, lastName);
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

void Student::printAllObjects() {
    try {
        int objectsCount = this->objectCount();
        cout << "Number Of " << this->objectFileName << "s: " << objectsCount << endl;

        for (int i = 1; i <= objectsCount; ++i) {
            this->read(i);
            cout << *this;
        }
    } catch (ifstream::failure &exc) {
        cout << "\aERROR: Can't Open This File" << endl;
    }
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

    bool isValid = checkConfigValidation(conf);
    if (!isValid) {
        cout << "Add Student Finished, Unsuccessfully!" << endl;
        return;
    }

    objAdaptor->setRecSize(recordSize);

    objAdaptor->setRecord();
    objAdaptor->setIntField(id);
    objAdaptor->setField(nameSize, this->name);
    objAdaptor->setField(lastNameSize, this->lastName);

    cout << "Student Added Successfully" << endl;
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
        case 0: //find by unique id
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

            if (inputNum > objectsCount || inputNum <= 0) {
                cout << "\aStudent With Unique Id \'" << inputNum << "\' Does Not Exist!" << endl;
            } else {
                idList.push_back(inputNum);
            }
            return idList;
        case 1: //find by student id
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
    int id;
    string stdName;
    string stdLastName;

    try {
        startIndex = objAdaptor->getRecord(index);
    } catch (out_of_range &e) {
        throw e;
    } catch (ifstream::failure &e) {
        throw e;
    }

    id = objAdaptor->getIntField(startIndex);
    stdId = objAdaptor->getIntField(startIndex);
    stdName = objAdaptor->getField(startIndex);
    stdLastName = objAdaptor->getField(startIndex);

    this->uniqueId = id;
    this->studentID = stdId;
    this->name = stdName;
    this->lastName = stdLastName;
}

void Student::edit(int option, int index) {
    Config config = objAdaptor->getAdpConf();
    string input;
    int inputNum;
    bool isValidNum;
    string fileName = objAdaptor->getFileName();

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
            this->studentID = inputNum;
            break;
        case 2: //edit student name
        {
            cout << "Edit Student Name: " << endl;
            getline(cin, input);
            this->name = input;

        }
            break;
        case 3: //edit student last name
            cout << "Edit Student Last Name: " << endl;
            getline(cin, input);
            this->lastName = input;
            break;
    }


    bool isValid = checkConfigValidation(config);
    if (!isValid) {
        cout << "Edit Student Finished, Unsuccessfully!" << endl;
        return;
    }

    int tmpId = this->uniqueId;
    int tmpStdId = this->studentID;
    string tmpStdName = this->name;
    string tmpStdLastName = this->lastName;

    int objectCount = this->objectCount();
    vector<Student> v1;
    vector<Student> v2;

    for (int i = 1; i <= index-1; ++i) {
        this->read(i);
        v1.push_back(*this);
    }

    for (int j = index+1; j <= objectCount; ++j) {
        this->read(j);
        v2.push_back(*this);
    }

    ofstream outfile;
    outfile.open(fileName, ios::binary | ios::out);
    outfile.close();

    for (Student std: v1) {
        std.add();
    }

    this->uniqueId = tmpId;
    this->studentID = tmpStdId;
    this->name = tmpStdName;
    this->lastName = tmpStdLastName;
    this->add();

    for (Student std: v2) {
        std.add();
    }
}

void Student::deleteObj(int index) {
    string fileName = objAdaptor->getFileName();
    int objectCount = this->objectCount();
    vector<Student> v1;
    vector<Student> v2;

    for (int i = 1; i <= index-1; ++i) {
        this->read(i);
        v1.push_back(*this);
    }

    for (int j = index+1; j <= objectCount; ++j) {
        this->read(j);
        v2.push_back(*this);
    }

    ofstream outfile;
    outfile.open(fileName, ios::binary | ios::out);
    outfile.close();

    for (Student std: v1) {
        std.add();
    }

    for (Student std: v2) {
        std.add();
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
    os << student.uniqueId << ": " << student.studentID << " | " << student.name << " | " << student.lastName << std::endl;
    return os;
}

bool Student::checkConfigValidation(Config &config) {
    bool isValid = true;

    int thisRecSize = (3* sizeof(int)) + this->name.size() + this->lastName.size();

    if (config.getRecordMode() == "Fix"){
        if (config.getStringMode() == "Fix"){   // fix rec fix str
            if (thisRecSize > config.getRecordSize()) {
                isValid = false;
                cout << "\aYOUR RECORD SIZE IS MORE THAN CONFIG RECORD SIZE!" << endl;
            }
            if (this->name.size() > config.getStudentNameSize()) {
                isValid = false;
                cout << "\aYOUR NAME IS TOO LONG!" << endl;
            }
            if (this->lastName.size() > config.getStudentLastNameSize()) {
                isValid = false;
                cout << "\aYOUR LAST NAME IS TOO LONG!" << endl;
            }
        } else{ // fix rec dyn str
            if (thisRecSize > config.getRecordSize()) {
                isValid = false;
                cout << "\aYOUR RECORD SIZE IS MORE THAN CONFIG RECORD SIZE!" << endl;
            }
        }
    } else{
        if (config.getStringMode() == "Fix"){   // dyn rec fix str
            if (this->name.size() > config.getStudentNameSize()) {
                isValid = false;
                cout << "\aYOUR NAME IS TOO LONG!" << endl;
            }
            if (this->lastName.size() > config.getStudentLastNameSize()) {
                isValid = false;
                cout << "\aYOUR LAST NAME IS TOO LONG!" << endl;
            }
        } else{ // dyn rec dyn str

        }
    }

    return isValid;
}

Book::Book(Adaptor *adaptor, int isbn, const string &name, const string &author, const string &publisher){
    this->objAdaptor = adaptor;
    this->objectFileName = constFileName;
    string fileName = this->objectFileName + ".txt";
    this->objAdaptor->setFileName(fileName);
    this->fieldsName = constFieldsName;
    this->isbn = isbn;
    this->name = name;
    this->author = author;
    this->publisher = publisher;
}

Book::Book(Adaptor *adaptor){
    Book(adaptor, 0, "", "", "");
}

bool Book::checkConfigValidation(Config &config) {
    return false;
}

void Book::printAllObjects() {

}

void Book::add() {

}

vector<int> Book::find(int option) {
    return vector<int>();
}

void Book::read(int index) {

}

void Book::edit(int option, int index) {

}

void Book::deleteObj(int index) {

}

ostream &operator<<(ostream &os, const Book &book) {
    string personName;
    if (book.onLoan == 0) {
        personName = "Un-Borrowed";
    } else {
        Student tmpStudent(book.objAdaptor);
        tmpStudent.read(book.onLoan);
        personName = tmpStudent.getName() + " " + tmpStudent.getLastName();
    }

    os << "id: " << book.uniqueId << " | " << book.isbn << " | " << book.name << " | "
       << book.author << " | " << book.publisher << " | " <<  personName;
    return os;
}
