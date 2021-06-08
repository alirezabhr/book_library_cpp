#ifndef BOOKS_LIBRARY_UI_H
#define BOOKS_LIBRARY_UI_H

#include <iostream>
#include <string>
#include <vector>

bool check_number(const std::string &str);
std::vector<int> showMainMenu();
std::vector<int> showAdaptorOptions();
int getRecordSize();
int getNameStrSize();
int getLastNameStrSize();

#endif //BOOKS_LIBRARY_UI_H
