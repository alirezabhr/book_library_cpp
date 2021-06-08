#include <iostream>
#include "entities.h"

using namespace std;

File::File(Adaptor *fAdapt) : fAdapt(fAdapt) {
    this->charFile = new char[fAdapt->recSize];
}

Student::Student(int studentID, const string &name, const string &lastName) : studentID(studentID), name(name),
                                                                              lastName(lastName) {

}

Book::Book(int id, const string &name, const string &author) : id(id), name(name), author(author) {

}