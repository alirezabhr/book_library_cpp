#include <iostream>
#include <vector>
#include "adaptors.h"

using namespace std;

int main() {
//    vector<int> v1 = showMainMenu();
    vector<int> v1 = {4, 52, 16, 23};

    int adpOption = v1.at(0);
    switch (adpOption) {
        case 1:
            cout << "dyn rec dyn str" << endl;
            break;
        case 2:
            cout << "dyn rec fix str" << endl;
            break;
        case 3:
            cout << "fix rec dyn str" << endl;
            break;
        case 4: {
            cout << "fix rec fix str" << endl;
            int recSize = v1.at(1);
            int strSize = v1.at(2) + v1.at(3) + 2;
            Student student = getStudent(v1.at(2), v1.at(3));
            FixRecFixStrAdap adaptor(recSize, strSize);
            File file(&adaptor);
            file.write(student);
            Student testStd;
            file.read(2, testStd);
        }
            break;
        default:
            cout << "wrong response from Main Menu" << endl;
    }

    return 0;
}
