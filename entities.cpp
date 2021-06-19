#include <iostream>
#include "entities.h"

using namespace std;

string Object::getObjectFileName() {
    return this->objectFileName;
}

Student::Student(int studentID, const string &name, const string &lastName) : studentID(studentID), name(name),
                                                                              lastName(lastName) {
    this->objectFileName = "students";
}

Student::Student() {
    studentID = 0;
    name = "";
    lastName = "";
    this->objectFileName = "students";
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

Book::Book(int id, const string &name, const string &author) : id(id), name(name), author(author) {
    this->objectFileName = "books";
}

Student getStudent(int nameSz, int lastNameSz) {
    string name;
    string lastName;
    int stdNo;

    cout << "STUDENT FORM" << endl;
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
    cout << "enter student id: ";
    cin >> stdNo;

    Student s(stdNo, name, lastName);
//    system("cls");
    return s;
}
