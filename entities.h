#ifndef BOOKS_LIBRARY_ENTITIES_H
#define BOOKS_LIBRARY_ENTITIES_H

#include <iostream>
#include "adaptors.h"

class Student;

class Object {
protected:
    int uniqueId;
    Adaptor *objAdaptor;
    string objectFileName;
    vector<string> fieldsName;
public:
    string getObjectFileName();
    const vector<string> &getFieldsName() const;
    int objectCount();
    virtual void printAllObjects() = 0;
    virtual bool checkConfigValidation(Config &config) = 0;
    virtual void add() = 0;
    virtual vector<int> find(int option) = 0;
    virtual void read(int index) = 0;
    virtual void edit(int option, int index) = 0;
    virtual void deleteObj(int index) = 0;
};

class Student: public Object{
    int studentID;
    string name;
    string lastName;
    const string constFileName = "Student";
    const vector<string> constFieldsName = {"Id", "Name", "Last Name"};
public:
    Student(Adaptor *adaptor, int studentID, const string &name, const string &lastName);
    Student(Adaptor *adaptor);

    bool checkConfigValidation(Config &config) override;
    void printAllObjects() override;
    void add() override;
    vector<int> find(int option) override;
    void read(int index) override;
    void edit(int option, int index) override;
    void deleteObj(int index) override;
    int getStudentId();
    string getName();
    string getLastName();
    friend ostream &operator<<(ostream &os, const Student &student);
};

class Book: public Object{
    int isbn;
    string name;
    string author;
    string publisher;
    int onLoan = 0; // 0 if nobody loan this book, or student id if someone loan it
    const string constFileName = "Book";
    const vector<string> constFieldsName = {"ISBN", "Name", "Author", "Publisher", "Student"};
public:
    Book(Adaptor *adaptor, int isbn, const string &name, const string &author, const string &publisher);
    Book(Adaptor *adaptor);

    bool checkConfigValidation(Config &config) override;
    void printAllObjects() override;
    void add() override;
    vector<int> find(int option) override;
    void read(int index) override;
    void edit(int option, int index) override;
    void deleteObj(int index) override;

    friend ostream &operator<<(ostream &os, const Book &book);
};

Student getStudent(Adaptor *adaptor, int nameSize, int lastNameSize);

bool check_number(const string &str);

#endif //BOOKS_LIBRARY_ENTITIES_H
