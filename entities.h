#ifndef BOOKS_LIBRARY_ENTITIES_H
#define BOOKS_LIBRARY_ENTITIES_H

#include <iostream>
#include "adaptors.h"

class Student;

class Object {
protected:
    Adaptor *objAdaptor;
    std::string objectFileName;
public:
   std::string getObjectFileName();
   virtual void add() = 0;
};

class Student: public Object{
    int studentID;
    std::string name;
    std::string lastName;
public:
    Student(Adaptor *adaptor, int studentID, const std::string &name, const std::string &lastName);
    Student(Adaptor *adaptor);

    void add() override;
    int getStudentId();
    std::string getName();
    std::string getLastName();
    friend std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << "studentID: " << student.studentID << " name: " << student.name << " lastName: " << student.lastName << std::endl;
        return os;
    }
};

class Book: public Object{
    int id;
    std::string name;
    std::string author;
public:
    Book(int id, const std::string &name, const std::string &author);
};

Student getStudent(Adaptor *adaptor, int nameSize, int lastNameSize);

#endif //BOOKS_LIBRARY_ENTITIES_H
