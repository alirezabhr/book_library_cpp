#ifndef BOOKS_LIBRARY_ENTITIES_H
#define BOOKS_LIBRARY_ENTITIES_H

#include <iostream>
#include "adaptors.h"

class Student;

class Object {
protected:
    Adaptor *objAdaptor;
    string objectFileName;
    vector<string> fieldsName;
public:
    string getObjectFileName();
    const vector<string> &getFieldsName() const;
    int objectCount();
    void printAllObjects();
    virtual void add() = 0;
    virtual vector<int> find(int option) = 0;
    virtual void read(int index) = 0;
    virtual void edit(int index) = 0;
};

class Student: public Object{
    int studentID;
    string name;
    string lastName;
    const string constFileName = "students";
    const vector<string> constFieldsName = {"student id", "student name", "student last name"};
public:
    Student(Adaptor *adaptor, int studentID, const string &name, const string &lastName);
    Student(Adaptor *adaptor);

    void add() override;
    vector<int> find(int option) override;
    void read(int index) override;
    void edit(int index) override;
    int getStudentId();
    string getName();
    string getLastName();
    friend ostream &operator<<(ostream &os, const Student &student);
};

class Book: public Object{
    int id;
    string name;
    string author;
public:
    Book(int id, const string &name, const string &author);
};

Student getStudent(Adaptor *adaptor, int nameSize, int lastNameSize);

bool check_number(const string &str);

#endif //BOOKS_LIBRARY_ENTITIES_H
