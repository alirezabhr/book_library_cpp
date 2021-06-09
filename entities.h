#ifndef BOOKS_LIBRARY_ENTITIES_H
#define BOOKS_LIBRARY_ENTITIES_H

#include <iostream>
#include "adaptors.h"

class Student;

class File {
    Adaptor *fAdapt;
    char *charFile;
public:
    File(Adaptor *fAdapt);

    void write(const Student& s);
    void read(int index, Student &s);
    void append(char *data);
};

class Student{
    int studentID;
    std::string name;
    std::string lastName;
public:
    Student(int studentID, const std::string &name, const std::string &lastName);

//    Student(const Student &s) {
//        studentID = s.studentID;
//        name = s.name;
//        lastName = s.lastName;
//    }

    friend std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << "studentID: " << student.studentID << " name: " << student.name << " lastName: " << student.lastName << std::endl;
        return os;
    }
};

class Book{
    int id;
    std::string name;
    std::string author;
public:
    Book(int id, const std::string &name, const std::string &author);
};

Student get_student(int nameSize, int lastNameSize);

#endif //BOOKS_LIBRARY_ENTITIES_H
