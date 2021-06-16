#ifndef BOOKS_LIBRARY_ENTITIES_H
#define BOOKS_LIBRARY_ENTITIES_H

#include <iostream>

class Student;

class Object {
    virtual void write() = 0;
    virtual void read() = 0;
};

class Student{
    int studentID;
    std::string name;
    std::string lastName;
public:
    Student(int studentID, const std::string &name, const std::string &lastName);
    Student();

    int getStudentId();

    std::string getName();

    std::string getLastName();

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

Student getStudent(int nameSize, int lastNameSize);

#endif //BOOKS_LIBRARY_ENTITIES_H
