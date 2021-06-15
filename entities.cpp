#include <iostream>
#include <fstream>
#include "entities.h"

using namespace std;

File::File(Adaptor *fAdapt) : fAdapt(fAdapt) {
    this->charFile = new char[fAdapt->getRecSize()];
}

void File::write(const Student& s) {

    int x = 123;
    double fx = 34.54;
    string name = "hello mother fuxker";
    ofstream outfile;
    outfile.open("binFile.txt", ios::binary | ios::out);
    outfile.write(reinterpret_cast<const char *>(&x), sizeof(int));
    outfile.write(reinterpret_cast<const char *>(&fx), sizeof(fx));
    outfile.write(reinterpret_cast<const char *>(&name), sizeof(name));
    outfile.close();

//    int num;
//    double d;
//    string new_str;
//    ifstream infile;
//    infile.open("binFile.txt", ios::binary | ios::in);
//    infile.read(reinterpret_cast<char *>(&num), sizeof(int));
//    infile.read(reinterpret_cast<char *>(&d), sizeof(double));
//    infile.read(reinterpret_cast<char *>(&new_str), name.size());
//    cout << "num: " << num << "new str: " << new_str << endl;
}

Student::Student(int studentID, const string &name, const string &lastName) : studentID(studentID), name(name),
                                                                              lastName(lastName) {

}

Book::Book(int id, const string &name, const string &author) : id(id), name(name), author(author) {

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
    system("cls");
    return s;
}