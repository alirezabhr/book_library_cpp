#include <iostream>
#include "adaptors.h"

using namespace std;

#define ADD_STUDENT_OPTION 1
#define ADD_BOOK_OPTION 2
#define EXIT_PROGRAM_OPTION 3

int main() {
    Config config;
    Adaptor *adaptor = nullptr;

    try {
        config = getAdaptorOptions();
    } catch (CONFIG_EXCEPTION &ce) {
        cout << "\aError (in config file): " << ce.getMsg() << endl;
        return 0;
    }

    if (config.getRecordMode() == "Fix") {
        if (config.getStringMode() == "Fix") {
            cout << "fix rec fix str" << endl;
            adaptor = new FixRecFixStrAdap(config);
        } else {
            cout << "fix rec dyn str" << endl;
            adaptor = new FixRecDynStrAdap(config);
        }
    } else {
        if (config.getStringMode() == "Fix") {
            cout << "dyn rec fix str" << endl;
            adaptor = new DynRecFixStrAdap(config);
        } else {
            cout << "dyn rec dyn str" << endl;
            adaptor = new DynRecDynStrAdap(config);
        }
    }

    while (true) {

        int option = showMainMenu();

        switch (option) {
            case ADD_STUDENT_OPTION: {
                cout << "request for adding a student" << endl;
                Student student = getStudent(config.getStudentNameSize(), config.getStudentLastNameSize());
                File file(adaptor, &student);
                file.write();
//                file.write(student);
//            Student testStd;
//            file.read(2, testStd);
            }
                break;
            case ADD_BOOK_OPTION: {
                cout << "request for adding a book" << endl;
            }
                break;
            case EXIT_PROGRAM_OPTION:
                cout << "Program Closed" << endl;
                break;
            default:
                cout << "bad request!" << endl;
        }
        if (option == EXIT_PROGRAM_OPTION) {
            break;
        }
    }
    return 0;
}
