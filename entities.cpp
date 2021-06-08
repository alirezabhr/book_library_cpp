#include <iostream>
#include "entities.h"

using namespace std;


Student::    Student(int studentID, const string &name, const string &lastName) : studentID(studentID), name(name), lastName(lastName) {}