#ifndef BOOKS_LIBRARY_UI_H
#define BOOKS_LIBRARY_UI_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Config;

bool check_number(const std::string &str);
void showMainMenu();
Config getAdaptorOptions();
int getRecordSize();
int getNameStrSize();
int getLastNameStrSize();
std::vector<std::string> myTokenize(std::string line);

class Config {
    std::string recordMode;
    std::string stringMode;
    int recordSize;
    int studentNameSize;
    int studentLastNameSize;
public:
    Config();

    const std::string &getRecordMode() const;

    const std::string &getStringMode() const;

    int getRecordSize() const;

    int getStudentNameSize() const;

    int getStudentLastNameSize() const;

    void setFields(const std::string& field, const std::string& value);
};

#endif //BOOKS_LIBRARY_UI_H
