#include <iostream>
#include <vector>
#include "ui.h"

using namespace std;

int main() {
    vector<int> v1 = showMainMenu();
    if (v1.at(0) == 1) {
        //todo should create an object of adaptor (dyn rec dyn str)
    } else if (v1.at(0) == 2) {
        //todo should create an object of adaptor (dyn rec fix str)
    } else if (v1.at(0) == 3) {
        //todo should create an object of adaptor (fix rec dyn str)
    } else if (v1.at(0) == 4) {
        //todo should create an object of adaptor (fix rec fix str)
    } else {
        cout << "wrong response from Main Menu" << endl;
    }

    return 0;
}
