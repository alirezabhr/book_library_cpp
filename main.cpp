#include <iostream>
#include <vector>
#include "ui.h"
#include "entities.h"

using namespace std;

int main() {
//    vector<int> v1 = showMainMenu();
    vector<int> v1 = {4, 52, 16, 23};
    if (v1.at(0) == 1) {
        //todo should create an object of adaptor (dyn rec dyn str)
    } else if (v1.at(0) == 2) {
        //todo should create an object of adaptor (dyn rec fix str)
    } else if (v1.at(0) == 3) {
        //todo should create an object of adaptor (fix rec dyn str)
    } else if (v1.at(0) == 4) {
        FixRecFixStrAdap adaptor(v1.at(1), v1.at(2), v1.at(3));
        File f(&adaptor);
//        Student student = get_student(adaptor.nSize, adaptor.lnSize); ///adaptor didnt work correctly
        Student student = getStudent(v1.at(2), v1.at(3));
        f.write(student);
    } else {
        cout << "wrong response from Main Menu" << endl;
    }

    return 0;
}
