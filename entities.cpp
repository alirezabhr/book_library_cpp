#include <iostream>
#include "entities.h"

#include <ostream>

using namespace std;

Date Date::createDate() {
    int year;
    int month;
    int day;
    string input;
    int inputNum;
    bool isValid;

    while (true) {
        cout << "Enter Year: " << endl;
        getline(cin, input);
        isValid = check_number(input);
        if (!isValid) {
            //system("cls");
            cout << "!! PLEASE ENTER A VALID YEAR !!" << endl;
            continue;
        } else {
            inputNum = stoi(input);
            if (inputNum > 1500 || inputNum < 1360) {
                cout << "!! PLEASE ENTER A YEAR BETWEEN 1360-1500 !!" << endl;
                continue;
            }
            break;
        }
    }
    year = inputNum;

    while (true) {
        cout << "Enter Month: " << endl;
        getline(cin, input);
        isValid = check_number(input);
        if (!isValid) {
            //system("cls");
            cout << "!! PLEASE ENTER A VALID MONTH !!" << endl;
            continue;
        } else {
            inputNum = stoi(input);
            if (inputNum > 12 || inputNum < 1) {
                cout << "!! PLEASE ENTER A MONTH BETWEEN 1-12!!" << endl;
                continue;
            }
            break;
        }
    }
    month = inputNum;

    while (true) {
        cout << "Enter Day: " << endl;
        getline(cin, input);
        isValid = check_number(input);
        if (!isValid) {
            //system("cls");
            cout << "!! PLEASE ENTER A VALID DAY !!" << endl;
            continue;
        } else {
            inputNum = stoi(input);
            if (inputNum > 31 || inputNum < 1) {
                cout << "!! PLEASE ENTER A DAY BETWEEN 1-31!!" << endl;
                continue;
            }
            break;
        }
    }
    day = inputNum;

    return {year, month, day};
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

Date Date::intToDate(int intDate) {
    int date = intDate;
    int day = date % 100;
    date /= 100;
    int month = intDate % 100;
    date /= 100;
    if (date > 1500 || date < 1360) {
        cout << "Bad Int Date!" << endl;
    }
    return {date, month, day};
}

int Date::toInt() {
    int intDate = this->year * 10000 + this->month * 100 + this->day;
    return intDate;
}

ostream &operator<<(ostream &os, const Date &date) {
    os << date.year << "/" << date.month << "/" << date.day;
    return os;
}

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

Book getBook(Adaptor *adaptor, int nameSize, int authorSize, int publisherSize) {
    string name;
    string author;
    string publisher;
    string isbnStr;
    long long isbn;
    bool isValidNum;

    cout << "-----------BOOK FORM-----------" << endl;
    while (true) {
        cout << "enter book name: ";
        getline(cin, name);
        if (name.length() > nameSize) {
            cout << "name is too long\nTRY AGAIN!" << endl;
            continue;
        } else break;
    }
    while (true) {
        cout << "enter book author: ";
        getline(cin, author);
        if (author.length() > authorSize) {
            cout << "book author is too long\nTRY AGAIN!" << endl;
            continue;
        } else break;
    }
    while (true) {
        cout << "enter book publisher: ";
        getline(cin, publisher);
        if (publisher.length() > publisherSize) {
            cout << "book publisher is too long\nTRY AGAIN!" << endl;
            continue;
        } else break;
    }
    while (true) {
        cout << "enter book isbn: ";
        getline(cin, isbnStr);
        isValidNum = check_number(isbnStr);
        if (!isValidNum) {
            //system("cls");
            cout << "!! PLEASE ENTER A VALID BOOK ISBN !!" << endl;
            continue;
        } else {
            isbn = stoll(isbnStr);
            break;
        }
    }

    Book book(adaptor, isbn, name, author, publisher);
//    system("cls");
    return book;
}

Record getLibraryRecord(Adaptor *adaptor) {
    int studentId;
    int bookId;
    string input;
    bool isValidNum;

    Config config = adaptor->getAdpConf();
    Adaptor *stdAdp = Student::getObjectAdaptor(config);
    Adaptor *bookAdp = Book::getObjectAdaptor(config);
    Student tmpStudent(stdAdp);
    Book tmpBook(bookAdp);
    int studentCount = tmpStudent.objectCount();
    int bookCount = tmpBook.objectCount();

    cout << "-----------RECORD FORM-----------" << endl;
    while (true) {
        cout << "enter student id: ";
        getline(cin, input);
        isValidNum = check_number(input);
        if (!isValidNum) {
            //system("cls");
            cout << "!! PLEASE ENTER A VALID STUDENT ID !!" << endl;
            continue;
        } else {
            studentId = stoi(input);
            if (studentId > studentCount || studentId <= 0) {
                cout << "Student With Unique Id '" << studentId << "' Not Found" << endl;
                continue;
            }
            break;
        }
    }
    while (true) {
        cout << "enter book id: ";
        getline(cin, input);
        isValidNum = check_number(input);
        if (!isValidNum) {
            //system("cls");
            cout << "!! PLEASE ENTER A VALID BOOK ID !!" << endl;
            continue;
        } else {
            bookId = stoi(input);
            if (bookId > bookCount || bookId <= 0) {
                cout << "Book With Unique Id '" << bookId << "' Not Found" << endl;
                continue;
            }
            break;
        }
    }
    while (true) {
        cout << "*loan date*" << endl;
        Date loanDate = Date::createDate();
        cout << "*return date*" << endl;
        Date returnDate = Date::createDate();
        if (returnDate.toInt() < loanDate.toInt()) {
            cout << "Dates Are Not Correct!" << endl;
            cout << "Try Another Dates" << endl;
            continue;
        }
        Record record = Record(adaptor, studentId, bookId, loanDate, returnDate);
        //    system("cls");
        return record;
    }
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

bool Student::checkConfigValidation(Config &config) {
    bool isValid = true;

    int thisRecSize = (3 * sizeof(int)) + this->name.size() + this->lastName.size();

    if (config.getStudentRecordMode() == "Fix") {
        if (config.getStudentStringMode() == "Fix") {   // fix rec fix str
            if (thisRecSize > config.getStudentRecordSize()) {
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
        } else { // fix rec dyn str
            if (thisRecSize > config.getStudentRecordSize()) {
                isValid = false;
                cout << "\aYOUR RECORD SIZE IS MORE THAN CONFIG RECORD SIZE!" << endl;
            }
        }
    } else {
        if (config.getStudentStringMode() == "Fix") {   // dyn rec fix str
            if (this->name.size() > config.getStudentNameSize()) {
                isValid = false;
                cout << "\aYOUR NAME IS TOO LONG!" << endl;
            }
            if (this->lastName.size() > config.getStudentLastNameSize()) {
                isValid = false;
                cout << "\aYOUR LAST NAME IS TOO LONG!" << endl;
            }
        } else { // dyn rec dyn str

        }
    }

    return isValid;
}

void Student::printAllObjects() {
    try {
        int objectsCount = this->objectCount();
        cout << "Number Of " << this->objectFileName << "s: " << objectsCount << endl;
        cout << "id: n | STD-NO | STD-NAME | STD-LAST NAME" << endl;

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

    if (conf.getStudentRecordMode() == "Fix" && conf.getStudentStringMode() == "Fix") {
        nameSize = conf.getStudentNameSize();
        lastNameSize = conf.getStudentLastNameSize();
        recordSize = conf.getStudentRecordSize();
    } else if (conf.getStudentRecordMode() == "Fix" && conf.getStudentStringMode() == "Dyn") {
        nameSize = this->name.size();
        lastNameSize = this->lastName.size();
        recordSize = conf.getStudentRecordSize();
    } else if (conf.getStudentRecordMode() == "Dyn" && conf.getStudentStringMode() == "Fix") {
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

    objAdaptor->setRecord(recordSize);
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
                cout << "Enter Student Unique Id: " << endl;
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

    for (int i = 1; i <= index - 1; ++i) {
        this->read(i);
        v1.push_back(*this);
    }

    for (int j = index + 1; j <= objectCount; ++j) {
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

    for (int i = 1; i <= index - 1; ++i) {
        this->read(i);
        v1.push_back(*this);
    }

    for (int j = index + 1; j <= objectCount; ++j) {
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
    os << student.uniqueId << ": " << student.studentID << " | " << student.name << " | " << student.lastName
       << std::endl;
    return os;
}

Adaptor *Student::getObjectAdaptor(Config &config) {
    Adaptor *adaptor;

    if (config.getStudentRecordMode() == "Fix") {
        if (config.getStudentStringMode() == "Fix") {
            adaptor = new FixRecFixStrAdap(config);
        } else {
            adaptor = new FixRecDynStrAdap(config);
        }
    } else {
        if (config.getStudentStringMode() == "Fix") {
            adaptor = new DynRecFixStrAdap(config);
        } else {
            adaptor = new DynRecDynStrAdap(config);
        }
    }

    return adaptor;
}

Book::Book(Adaptor *adaptor, long long isbn, const string &name, const string &author, const string &publisher) {
    this->objAdaptor = adaptor;
    this->objectFileName = constFileName;
    string fileName = this->objectFileName + ".txt";
    this->objAdaptor->setFileName(fileName);
    this->fieldsName = constFieldsName;
    this->isbn = isbn;
    this->name = name;
    this->author = author;
    this->publisher = publisher;
    this->onLoan = 0;
}

Book::Book(Adaptor *adaptor) {
    this->objAdaptor = adaptor;
    this->objectFileName = constFileName;
    string fileName = this->objectFileName + ".txt";
    this->objAdaptor->setFileName(fileName);
    this->fieldsName = constFieldsName;
    this->isbn = 0;
    this->name = "";
    this->author = "";
    this->publisher = "";
    this->onLoan = 0;
}

Adaptor *Book::getObjectAdaptor(Config &config) {
    Adaptor *adaptor;

    if (config.getBookRecordMode() == "Fix") {
        if (config.getBookStringMode() == "Fix") {
            adaptor = new FixRecFixStrAdap(config);
        } else {
            adaptor = new FixRecDynStrAdap(config);
        }
    } else {
        if (config.getBookStringMode() == "Fix") {
            adaptor = new DynRecFixStrAdap(config);
        } else {
            adaptor = new DynRecDynStrAdap(config);
        }
    }

    return adaptor;
}

bool Book::checkConfigValidation(Config &config) {
    bool isValid = true;

    int thisRecSize =
            sizeof(long long) + (3 * sizeof(int)) + this->name.size() + this->author.size() + this->publisher.size() +
            sizeof(int);

    if (config.getBookRecordMode() == "Fix") {
        if (config.getBookStringMode() == "Fix") {   // fix rec fix str
            if (thisRecSize > config.getBookRecordSize()) {
                isValid = false;
                cout << "\aYOUR RECORD SIZE IS MORE THAN CONFIG RECORD SIZE!" << endl;
            }
            if (this->name.size() > config.getBookNameSize()) {
                isValid = false;
                cout << "\aYOUR NAME IS TOO LONG!" << endl;
            }
            if (this->author.size() > config.getBookAuthorSize()) {
                isValid = false;
                cout << "\aYOUR AUTHOR IS TOO LONG!" << endl;
            }
            if (this->publisher.size() > config.getBookPublisherSize()) {
                isValid = false;
                cout << "\aYOUR PUBLISHER IS TOO LONG!" << endl;
            }
        } else { // fix rec dyn str
            if (thisRecSize > config.getBookRecordSize()) {
                isValid = false;
                cout << "\aYOUR RECORD SIZE IS MORE THAN CONFIG RECORD SIZE!" << endl;
            }
        }
    } else {
        if (config.getBookStringMode() == "Fix") {   // dyn rec fix str
            if (this->name.size() > config.getBookNameSize()) {
                isValid = false;
                cout << "\aYOUR NAME IS TOO LONG!" << endl;
            }
            if (this->author.size() > config.getBookAuthorSize()) {
                isValid = false;
                cout << "\aYOUR AUTHOR IS TOO LONG!" << endl;
            }
            if (this->publisher.size() > config.getBookPublisherSize()) {
                isValid = false;
                cout << "\aYOUR PUBLISHER IS TOO LONG!" << endl;
            }
        } else { // dyn rec dyn str

        }
    }

    return isValid;
}

void Book::printAllObjects() {
    try {
        int objectsCount = this->objectCount();
        cout << "Number Of " << this->objectFileName << "s: " << objectsCount << endl;
        cout << "id: n | BOOK-NAME | BOOK-AUTHOR | BOOK-PUBLISHER | ON-LOAN" << endl;

        for (int i = 1; i <= objectsCount; ++i) {
            this->read(i);
            cout << *this;
        }
    } catch (ifstream::failure &exc) {
        cout << "\aERROR: Can't Open This File" << endl;
    }
}

void Book::add() {
    Config conf = objAdaptor->getAdpConf();
    int recordSize;
    const int isbnSize = sizeof(long long);
    int nameSize;
    int authorSize;
    int publisherSize;

    if (conf.getBookRecordMode() == "Fix" && conf.getBookStringMode() == "Fix") {
        nameSize = conf.getBookNameSize();
        authorSize = conf.getBookAuthorSize();
        publisherSize = conf.getBookPublisherSize();
        recordSize = conf.getBookRecordSize();
    } else if (conf.getBookRecordMode() == "Fix" && conf.getBookStringMode() == "Dyn") {
        nameSize = this->name.size();
        authorSize = this->author.size();
        publisherSize = this->publisher.size();
        recordSize = conf.getBookRecordSize();
    } else if (conf.getBookRecordMode() == "Dyn" && conf.getBookStringMode() == "Fix") {
        nameSize = conf.getBookNameSize();
        authorSize = conf.getBookAuthorSize();
        publisherSize = conf.getBookPublisherSize();
        recordSize = isbnSize + sizeof(int) + nameSize + sizeof(int) + authorSize + sizeof(int) + publisherSize +
                     sizeof(int);
    } else {    //Dynamic Record Dynamic String
        nameSize = this->name.size();
        authorSize = this->author.size();
        publisherSize = this->publisher.size();
        recordSize = isbnSize + sizeof(int) + nameSize + sizeof(int) + authorSize + sizeof(int) + publisherSize +
                     sizeof(int);
    }

    bool isValid = checkConfigValidation(conf);
    if (!isValid) {
        cout << "Add Book Finished, Unsuccessfully!" << endl;
        return;
    }

    objAdaptor->setRecord(recordSize);
    objAdaptor->setLongLongField(this->isbn);
    objAdaptor->setIntField(this->onLoan);
    objAdaptor->setField(nameSize, this->name);
    objAdaptor->setField(authorSize, this->author);
    objAdaptor->setField(publisherSize, this->publisher);

    cout << "Book Added Successfully" << endl;
}

vector<int> Book::find(int option) {
    string input;
    int inputNum;
    long long bookIsbn;
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
                cout << "Enter Book Unique Id: " << endl;
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
                cout << "\aBook With Unique Id \'" << inputNum << "\' Does Not Exist!" << endl;
            } else {
                idList.push_back(inputNum);
            }
            return idList;
        case 1: //find by book isbn
            while (true) {
                cout << "Enter Book ISBN: " << endl;
                getline(cin, input);
                isValidNum = check_number(input);
                if (!isValidNum) {
                    //system("cls");
                    cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                    continue;
                } else {
                    bookIsbn = stoll(input);
                    break;
                }
            }
            for (int i = 1; i <= objectsCount; ++i) {
                this->read(i);
                if (this->isbn == bookIsbn) {
                    idList.push_back(i);
                }
            }
            if (idList.empty()) {
                cout << "\aBook With ISBN \'" << bookIsbn << "\' NOT FOUND" << endl;
            }
            return idList;
        case 2: //find by name
            cout << "Enter Book Name: " << endl;
            getline(cin, input);
            for (int i = 1; i <= objectsCount; ++i) {
                this->read(i);
                if (this->name == input) {
                    idList.push_back(i);
                }
            }
            if (idList.empty()) {
                cout << "\aBook With Name \'" << input << "\' NOT FOUND" << endl;
            }
            return idList;
        case 3: //find by author
            cout << "Enter Book Author: " << endl;
            getline(cin, input);
            for (int i = 1; i <= objectsCount; ++i) {
                this->read(i);
                if (this->author == input) {
                    idList.push_back(i);
                }
            }
            if (idList.empty()) {
                cout << "\aBook With Author \'" << input << "\' NOT FOUND" << endl;
            }
            return idList;
        case 4: //find by publisher
            cout << "Enter Book Publisher: " << endl;
            getline(cin, input);
            for (int i = 1; i <= objectsCount; ++i) {
                this->read(i);
                if (this->publisher == input) {
                    idList.push_back(i);
                }
            }
            if (idList.empty()) {
                cout << "\aBook With Publisher \'" << input << "\' NOT FOUND" << endl;
            }
            return idList;
        case 5: //find by student (on Loan)
            while (true) {
                cout << "Enter Student Unique Id: " << endl;
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
                if (this->onLoan == inputNum) {
                    idList.push_back(i);
                }
            }
            if (idList.empty()) {
                cout << "\aStudent With Unique Id \'" << inputNum << "\' Didn't Borrowed Any Book" << endl;
            }
            return idList;
        default:
            return idList;
    }
}

void Book::read(int index) {
    int startIndex = 0;
    int id;
    long long bookIsbn;
    string bookName;
    string bookAuthor;
    string bookPublisher;
    int bookOnLoan;

    try {
        startIndex = objAdaptor->getRecord(index);
    } catch (out_of_range &e) {
        throw e;
    } catch (ifstream::failure &e) {
        throw e;
    }

    id = objAdaptor->getIntField(startIndex);
    bookIsbn = objAdaptor->getLongLongField(startIndex);
    bookOnLoan = objAdaptor->getIntField(startIndex);
    bookName = objAdaptor->getField(startIndex);
    bookAuthor = objAdaptor->getField(startIndex);
    bookPublisher = objAdaptor->getField(startIndex);

    this->uniqueId = id;
    this->isbn = bookIsbn;
    this->onLoan = bookOnLoan;
    this->name = bookName;
    this->author = bookAuthor;
    this->publisher = bookPublisher;
}

void Book::edit(int option, int index) {
    Config config = objAdaptor->getAdpConf();
    string input;
    int inputNum;
    long long inputIsbn;
    bool isValidNum;
    string fileName = objAdaptor->getFileName();

    switch (option) {
        case 1: //edit book isbn
            while (true) {
                cout << "Edit Book ISBN: " << endl;
                getline(cin, input);
                isValidNum = check_number(input);
                if (!isValidNum) {
                    //system("cls");
                    cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                    continue;
                } else {
                    inputIsbn = stoll(input);
                    break;
                }
            }
            this->isbn = inputIsbn;
            break;
        case 2: //edit book name
        {
            cout << "Edit Book Name: " << endl;
            getline(cin, input);
            this->name = input;

        }
            break;
        case 3: //edit book author
        {
            cout << "Edit Book Author: " << endl;
            getline(cin, input);
            this->author = input;
        }
            break;
        case 4: //edit book publisher
        {
            cout << "Edit Book Publisher: " << endl;
            getline(cin, input);
            this->publisher = input;

        }
            break;
        case 5: //edit book onLoan (student id)
            Adaptor *adp = Student::getObjectAdaptor(config);
            Student tmpStudent(adp);
            int studentCount = tmpStudent.objectCount();
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
                    if (inputNum > studentCount || inputNum <= 0) {
                        cout << "!! STUDENT WITH THIS ID DOES NOT EXIST !!" << endl;
                        continue;
                    }
                    break;
                }
            }
            this->onLoan = inputNum;
            break;
    }


    bool isValid = checkConfigValidation(config);
    if (!isValid) {
        cout << "Edit Student Finished, Unsuccessfully!" << endl;
        return;
    }

    int tmpId = this->uniqueId;
    int tmpBookLoan = this->onLoan;
    string tmpBookName = this->name;
    string tmpBookAuthor = this->author;
    string tmpBookPublisher = this->publisher;
    long long tmpBookIsbn = this->isbn;

    int objectCount = this->objectCount();
    vector<Book> v1;
    vector<Book> v2;

    for (int i = 1; i <= index - 1; ++i) {
        this->read(i);
        v1.push_back(*this);
    }

    for (int j = index + 1; j <= objectCount; ++j) {
        this->read(j);
        v2.push_back(*this);
    }

    ofstream outfile;
    outfile.open(fileName, ios::binary | ios::out);
    outfile.close();

    for (Book book1: v1) {
        book1.add();
    }

    this->uniqueId = tmpId;
    this->isbn = tmpBookIsbn;
    this->onLoan = tmpBookLoan;
    this->name = tmpBookName;
    this->author = tmpBookAuthor;
    this->publisher = tmpBookPublisher;
    this->add();

    for (Book book2: v2) {
        book2.add();
    }
}

void Book::deleteObj(int index) {
    string fileName = objAdaptor->getFileName();
    int objectCount = this->objectCount();
    vector<Book> v1;
    vector<Book> v2;

    for (int i = 1; i <= index - 1; ++i) {
        this->read(i);
        v1.push_back(*this);
    }

    for (int j = index + 1; j <= objectCount; ++j) {
        this->read(j);
        v2.push_back(*this);
    }

    ofstream outfile;
    outfile.open(fileName, ios::binary | ios::out);
    outfile.close();

    for (Book book: v1) {
        book.add();
    }

    for (Book book: v2) {
        book.add();
    }
}

const string &Book::getName() const {
    return name;
}

ostream &operator<<(ostream &os, const Book &book) {
    string personName;
    if (book.onLoan == 0) {
        personName = "Un-Borrowed";
    } else {
        Config conf = book.objAdaptor->getAdpConf();
        Adaptor *stdAdp = Student::getObjectAdaptor(conf);
        Student tmpStudent(stdAdp);
        tmpStudent.read(book.onLoan);
        personName = tmpStudent.getName() + " " + tmpStudent.getLastName();
    }

    os << "id: " << book.uniqueId << " | " << book.isbn << " | " << book.name << " | "
       << book.author << " | " << book.publisher << " | " << personName << endl;
    return os;
}

Record::Record(Adaptor *adaptor, int studentId, int bookId, Date loanDate, Date returnDate) {
    this->objAdaptor = adaptor;
    this->objectFileName = constFileName;
    string fileName = this->objectFileName + ".txt";
    this->objAdaptor->setFileName(fileName);
    this->fieldsName = constFieldsName;
    this->studentId = studentId;
    this->bookId = bookId;
    this->intLoanedDate = loanDate.toInt();
    this->intReturnDate = returnDate.toInt();
}

Record::Record(Adaptor *adaptor) {
    this->objAdaptor = adaptor;
    this->objectFileName = constFileName;
    string fileName = this->objectFileName + ".txt";
    this->objAdaptor->setFileName(fileName);
    this->fieldsName = constFieldsName;
    this->studentId = 0;
    this->bookId = 0;
    this->intLoanedDate = 0;
    this->intReturnDate = 0;
}

Adaptor *Record::getObjectAdaptor(Config &config) {
    Adaptor *adaptor;

    if (config.getLibRecRecordMode() == "Fix") {
        if (config.getLibRecStringMode() == "Fix") {
            adaptor = new FixRecFixStrAdap(config);
        } else {
            adaptor = new FixRecDynStrAdap(config);
        }
    } else {
        if (config.getLibRecStringMode() == "Fix") {
            adaptor = new DynRecFixStrAdap(config);
        } else {
            adaptor = new DynRecDynStrAdap(config);
        }
    }

    return adaptor;
}

bool Record::checkConfigValidation(Config &config) {
    bool isValid = true;

    int thisRecSize = 4 * sizeof(int);
    if (thisRecSize > config.getLibRecRecordSize()) {
        cout << "\aYOUR CONFIG RECORD SIZE IS TOO SMALL!" << endl;
        isValid = false;
    }

    return isValid;
}

void Record::printAllObjects() {
    try {
        int objectsCount = this->objectCount();
        cout << "Number Of " << this->objectFileName << "s: " << objectsCount << endl;
        cout << "id: n | STUDENT-NAME | STUDENT-LAST-NAME | BOOK-NAME | LOAN-DATE | RETURN-DATE" << endl;

        for (int i = 1; i <= objectsCount; ++i) {
            this->read(i);
            cout << *this;
        }
    } catch (ifstream::failure &exc) {
        cout << "\aERROR: Can't Open This File" << endl;
    }
}

void Record::add() {
    Config conf = objAdaptor->getAdpConf();
    int recordSize;

    if (conf.getLibRecRecordMode() == "Fix") {
        recordSize = conf.getBookRecordSize();
    } else {
        recordSize = 4 * sizeof(int);
    }

    bool isValid = checkConfigValidation(conf);
    if (!isValid) {
        cout << "Add Record Finished, Unsuccessfully!" << endl;
        return;
    }

    objAdaptor->setRecord(recordSize);
    objAdaptor->setIntField(this->studentId);
    objAdaptor->setIntField(this->bookId);
    objAdaptor->setIntField(this->intLoanedDate);
    objAdaptor->setIntField(this->intReturnDate);

    cout << "Record Added Successfully" << endl;
}

vector<int> Record::find(int option) {
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
                cout << "Enter Record Unique Id: " << endl;
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
                cout << "\aRecord With Unique Id \'" << inputNum << "\' Does Not Exist!" << endl;
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
                if (this->studentId == inputNum) {
                    idList.push_back(i);
                }
            }
            if (idList.empty()) {
                cout << "\aRecord With Student Id \'" << inputNum << "\' NOT FOUND" << endl;
            }
            return idList;
        case 2: //find by book id
            while (true) {
                cout << "Enter Book Id: " << endl;
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
                if (this->bookId == inputNum) {
                    idList.push_back(i);
                }
            }
            if (idList.empty()) {
                cout << "\aRecord With Book Id \'" << inputNum << "\' NOT FOUND" << endl;
            }
            return idList;
        case 3: //find by loaned date
        {
            cout << "Enter Loan Date: " << endl;
            Date date1 = Date::createDate();
            for (int i = 1; i <= objectsCount; ++i) {
                this->read(i);
                if (this->intLoanedDate == date1.toInt()) {
                    idList.push_back(i);
                }
            }
            if (idList.empty()) {
                cout << "\aRecord With Loan Date \'" << date1 << "\' NOT FOUND" << endl;
            }
        }
            return idList;
        case 4: //find by return date
        {
            cout << "Enter Return Date: " << endl;
            Date date2 = Date::createDate();
            for (int i = 1; i <= objectsCount; ++i) {
                this->read(i);
                if (this->intReturnDate == date2.toInt()) {
                    idList.push_back(i);
                }
            }
            if (idList.empty()) {
                cout << "\aRecord With Return Date \'" << date2 << "\' NOT FOUND" << endl;
            }
        }
            return idList;
        default:
            return idList;
    }
}

void Record::read(int index) {
    int startIndex = 0;
    int id;
    int stdId;
    int bkId;
    int loanDate;
    int returnDate;

    try {
        startIndex = objAdaptor->getRecord(index);
    } catch (out_of_range &e) {
        throw e;
    } catch (ifstream::failure &e) {
        throw e;
    }

    id = objAdaptor->getIntField(startIndex);
    stdId = objAdaptor->getIntField(startIndex);
    bkId = objAdaptor->getIntField(startIndex);
    loanDate = objAdaptor->getIntField(startIndex);
    returnDate = objAdaptor->getIntField(startIndex);

    this->uniqueId = id;
    this->studentId = stdId;
    this->bookId = bkId;
    this->intLoanedDate = loanDate;
    this->intReturnDate = returnDate;
}

void Record::edit(int option, int index) {
    Config config = objAdaptor->getAdpConf();
    string input;
    int inputNum;
    bool isValidNum;
    string fileName = objAdaptor->getFileName();

    switch (option) {
        case 1: //edit record student id
        {
            Adaptor *stdAdp = Student::getObjectAdaptor(config);
            Student tmpStudent(stdAdp);
            int studentCount = tmpStudent.objectCount();
            while (true) {
                cout << "Edit Record Student Id: " << endl;
                getline(cin, input);
                isValidNum = check_number(input);
                if (!isValidNum) {
                    //system("cls");
                    cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                    continue;
                } else {
                    inputNum = stoi(input);
                    if (inputNum > studentCount || inputNum <= 0) {
                        cout << "Student With Unique Id '" << inputNum << "' Not Found" << endl;
                        continue;
                    }
                    break;
                }
            }
            this->studentId = inputNum;
        }
            break;
        case 2: //edit record book id
        {
            Adaptor *bookAdp = Book::getObjectAdaptor(config);
            Book tmpBook(bookAdp);
            int bookCount = tmpBook.objectCount();
            while (true) {
                cout << "Edit Record Book Id: " << endl;
                getline(cin, input);
                isValidNum = check_number(input);
                if (!isValidNum) {
                    //system("cls");
                    cout << "!! PLEASE ENTER A VALID NUMBER !!" << endl;
                    continue;
                } else {
                    inputNum = stoi(input);
                    if (inputNum > bookCount || inputNum <= 0) {
                        cout << "Book With Unique Id '" << inputNum << "' Not Found" << endl;
                        continue;
                    }
                    break;
                }
            }
            this->bookId = inputNum;
        }
            break;
        case 3: //edit record loan date
        {
            cout << "Edit Record Loan Date: " << endl;
            Date date1 = Date::createDate();
            this->intLoanedDate = date1.toInt();
        }
            break;
        case 4: //edit record return date
        {
            cout << "Edit Record Return Date: " << endl;
            Date date2 = Date::createDate();
            this->intReturnDate = date2.toInt();
        }
    }


    bool isValid = checkConfigValidation(config);
    if (!isValid) {
        cout << "Edit Student Finished, Unsuccessfully!" << endl;
        return;
    }

    int tmpId = this->uniqueId;
    int tmpRecStdId = this->studentId;
    int tmpRecBookId = this->bookId;
    int tmpRecLoanDate = this->intLoanedDate;
    int tmpRecReturnDate = this->intReturnDate;

    int objectCount = this->objectCount();
    vector<Record> v1;
    vector<Record> v2;

    for (int i = 1; i <= index - 1; ++i) {
        this->read(i);
        v1.push_back(*this);
    }

    for (int j = index + 1; j <= objectCount; ++j) {
        this->read(j);
        v2.push_back(*this);
    }

    ofstream outfile;
    outfile.open(fileName, ios::binary | ios::out);
    outfile.close();

    for (Record record1: v1) {
        record1.add();
    }

    this->uniqueId = tmpId;
    this->studentId = tmpRecStdId;
    this->bookId = tmpRecBookId;
    this->intLoanedDate = tmpRecLoanDate;
    this->intReturnDate = tmpRecReturnDate;
    this->add();

    for (Record record2: v2) {
        record2.add();
    }
}

void Record::deleteObj(int index) {
    Config config = objAdaptor->getAdpConf();
    string fileName = objAdaptor->getFileName();
    int objectCount = this->objectCount();
    vector<Record> v1;
    vector<Record> v2;

    for (int i = 1; i <= index - 1; ++i) {
        this->read(i);
        v1.push_back(*this);
    }

    for (int j = index + 1; j <= objectCount; ++j) {
        this->read(j);
        v2.push_back(*this);
    }

    ofstream outfile;
    outfile.open(fileName, ios::binary | ios::out);
    outfile.close();

    for (Record record1: v1) {
        record1.add();
    }

    for (Record record2: v2) {
        record2.add();
    }
}

ostream &operator<<(ostream &os, const Record &record) {
    Config conf = record.objAdaptor->getAdpConf();

    Adaptor *stdAdp = Student::getObjectAdaptor(conf);
    Student student(stdAdp);
    student.read(record.studentId);
    Adaptor *bookAdp = Book::getObjectAdaptor(conf);
    Book book(bookAdp);
    book.read(record.bookId);

    Date loanDate = Date::intToDate(record.intLoanedDate);
    Date returnDate = Date::intToDate(record.intReturnDate);

    os << "id: " << record.uniqueId << " | " << student.getName() << " | " << student.getLastName() << " | " << book.getName() << " | " << loanDate
       << " | " << returnDate << endl;
    return os;
}
