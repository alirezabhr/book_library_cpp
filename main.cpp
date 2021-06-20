#include <iostream>
#include "adaptors.h"

using namespace std;

int main() {
    Config config;

    try {
        config = getAdaptorOptions();
    } catch (CONFIG_EXCEPTION ce) {
        cout << "\aError (in config file): " << ce.getMsg() << endl;
        return 0;
    }

    showMainMenu();

    if (config.getRecordMode() == "Fix") {
        if (config.getStringMode() == "Fix") {
            cout << "fix rec fix str" << endl;
            FixRecFixStrAdap adaptor(config);
//            int recSize = config.getRecordSize();
//            int strSize = config.getStudentNameSize() + config.getStudentLastNameSize() + 2;
//            Student student = getStudent(config.getStudentNameSize(), config.getStudentLastNameSize());
//            FixRecFixStrAdap adaptor(config, recSize, strSize);
//            File file(&adaptor);
//            file.write(student);
//            Student testStd;
//            file.read(2, testStd);
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
