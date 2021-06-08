#ifndef BOOKS_LIBRARY_ENTITIES_H
#define BOOKS_LIBRARY_ENTITIES_H

#include <iostream>
#include "adaptors.h"


class Student{
    int studentID;
    string name;
    string lastName;
public:
    Student(int studentID, const string &name, const string &lastName);

//    Student(const Student &s) {
//        studentID = s.studentID;
//        name = s.name;
//        lastName = s.lastName;
//    }

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "studentID: " << student.studentID << " name: " << student.name << " lastName: " << student.lastName << endl;
        return os;
    }
};

class Book{
    int id;
    string name;
    string author;
public:
    Book(int id, const string &name, const string &author) : id(id), name(name), author(author) {}
};

#endif //BOOKS_LIBRARY_ENTITIES_H
