#ifndef BOOKS_LIBRARY_CONFIGURATIONS_H
#define BOOKS_LIBRARY_CONFIGURATIONS_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Config;

Config getAdaptorOptions();

class CONFIG_EXCEPTION {
    string msg;
public:
    CONFIG_EXCEPTION(const string &msg);

    const string &getMsg() const;
};

class Config {
    string studentRecordMode;
    string studentStringMode;
    int studentRecordSize = 0;
    int studentNameSize = 0;
    int studentLastNameSize = 0;
    string bookRecordMode;
    string bookStringMode;
    int bookRecordSize = 0;
    int bookNameSize = 0;
    int bookAuthorSize = 0;
    int bookPublisherSize = 0;
public:
    Config();
    void checkConfigValidation();
    const string &getStudentRecordMode() const;
    const string &getStudentStringMode() const;
    int getStudentRecordSize() const;
    int getStudentNameSize() const;
    int getStudentLastNameSize() const;

    const string &getBookRecordMode() const;

    const string &getBookStringMode() const;

    int getBookRecordSize() const;

    int getBookNameSize() const;

    int getBookAuthorSize() const;

    int getBookPublisherSize() const;

    void setFields(const string& field, const string& value);
    static vector<string> tokenize(string line);
};

#endif //BOOKS_LIBRARY_CONFIGURATIONS_H
