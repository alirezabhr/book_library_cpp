#include <iostream>
#include <vector>
#include "ui.h"
#include "adaptors.h"

using namespace std;

int main() {
    Config config = getAdaptorOptions();
//    showMainMenu();

    if (config.getRecordMode() == "Fix") {
        if (config.getStringMode() == "Fix") {
            cout << "fix rec fix str" << endl;
            int recSize = config.getRecordSize();
            int strSize = config.getStudentNameSize() + config.getStudentLastNameSize() + 2;
            Student student = getStudent(config.getStudentNameSize(), config.getStudentLastNameSize());
            FixRecFixStrAdap adaptor(recSize, strSize);
            File file(&adaptor);
            file.write(student);
            Student testStd;
            file.read(2, testStd);
        }
        if (config.getStringMode() == "Dyn") {
            cout << "fix rec dyn str" << endl;
        }
    }
    if (config.getRecordMode() == "Dyn") {
        if (config.getStringMode() == "Fix") {
            cout << "dyn rec fix str" << endl;
        }
        if (config.getStringMode() == "Dyn") {
            cout << "dyn rec dyn str" << endl;
        }
    }

    return 0;
}
