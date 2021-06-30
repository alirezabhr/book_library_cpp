#ifndef BOOKS_LIBRARY_UI_H
#define BOOKS_LIBRARY_UI_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "entities.h"

int showMainMenu();
int findObjectMenu(Object& object);
int editObjectMenu(Object& object);
void showEnterKey();

#endif //BOOKS_LIBRARY_UI_H
