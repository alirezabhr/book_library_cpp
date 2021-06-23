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
    string recordMode;
    string stringMode;
    int recordSize;
    int studentNameSize;
    int studentLastNameSize;
public:
    Config();
    const string &getRecordMode() const;
    const string &getStringMode() const;
    int getRecordSize() const;
    int getStudentNameSize() const;
    int getStudentLastNameSize() const;
    void setFields(const string& field, const string& value);
    static vector<string> tokenize(string line);
};

#endif //BOOKS_LIBRARY_CONFIGURATIONS_H
