#include <iostream>
#include "ui.h"

using namespace std;

#define ADD_STUDENT_OPTION 1
#define ALL_STUDENTS_OPTION 2
#define FIND_STUDENT_OPTION 3
#define EDIT_STUDENT_OPTION 4
#define DELETE_STUDENT_OPTION 5
#define ADD_BOOK_OPTION 6
#define ALL_BOOKS_OPTION 7
#define FIND_BOOK_OPTION 8
#define EDIT_BOOK_OPTION 9
#define DELETE_BOOK_OPTION 10
#define EXIT_PROGRAM_OPTION 0

int main() {
    Config config;
    Adaptor *studentAdaptor = nullptr;
    Adaptor *bookAdaptor = nullptr;
    int option = 0;
    int findOption = 0;
    int editOption = 0;

    try {
        config = getAdaptorOptions();
    } catch (CONFIG_EXCEPTION &ce) {
        cout << "\aError (in config file): " << ce.getMsg() << endl;
        return 0;
    }

    studentAdaptor = Student::getObjectAdaptor(config);
    bookAdaptor = Book::getObjectAdaptor(config);

    while (true) {
        option = showMainMenu();

        switch (option) {
            case ADD_STUDENT_OPTION: {
                cout << "Add Student" << endl;
                Student student = getStudent(studentAdaptor, config.getStudentNameSize(),
                                             config.getStudentLastNameSize());
                student.add();
            }
                break;
            case ALL_STUDENTS_OPTION: {
                cout << "All students" << endl;
                Student tmpStudent(studentAdaptor);
                tmpStudent.printAllObjects();
            }
                break;
            case FIND_STUDENT_OPTION: {
                cout << "Find Student" << endl;
                Student tmpStudent(studentAdaptor);
                findOption = findObjectMenu(tmpStudent);
                vector<int> idList = tmpStudent.find(findOption);
                for (int id: idList) {
                    tmpStudent.read(id);
                    cout << tmpStudent;
                }
            }
                break;
            case EDIT_STUDENT_OPTION: {
                cout << "Edit Student" << endl;
                Student tmpStudent(studentAdaptor);
                findOption = findObjectMenu(tmpStudent);
                vector<int> idList = tmpStudent.find(findOption);
                for (int id: idList) {
                    tmpStudent.read(id);
                    cout << tmpStudent;
                }
                if (idList.size() > 1) {
                    cout << "There Is More Than One Item!" << endl;
                    continue;
                }
                if (idList.empty()) {
                    continue;
                }
                editOption = editObjectMenu(tmpStudent);
                tmpStudent.edit(editOption, idList.at(0));
            }
                break;
            case DELETE_STUDENT_OPTION: {
                cout << "Delete Student" << endl;
                Student tmpStudent(studentAdaptor);
                findOption = findObjectMenu(tmpStudent);
                vector<int> idList = tmpStudent.find(findOption);
                for (int id: idList) {
                    tmpStudent.read(id);
                    cout << tmpStudent;
                }
                if (idList.size() > 1) {
                    cout << "There Is More Than One Item!" << endl;
                    continue;
                }
                if (idList.empty()) {
                    continue;
                }
                tmpStudent.deleteObj(idList.at(0));
            }
                break;
            case ADD_BOOK_OPTION: {
                cout << "Add Book" << endl;
                Book book = getBook(bookAdaptor, config.getBookNameSize(), config.getBookAuthorSize(),
                                    config.getBookPublisherSize());
                book.add();
            }
                break;
            case ALL_BOOKS_OPTION: {
                cout << "All Books" << endl;
                Book tmpBook(bookAdaptor);
                tmpBook.printAllObjects();
            }
                break;
            case FIND_BOOK_OPTION: {
                cout << "Find Book" << endl;
                Book tmpBook(bookAdaptor);
                findOption = findObjectMenu(tmpBook);
                vector<int> idList = tmpBook.find(findOption);
                for (int id: idList) {
                    tmpBook.read(id);
                    cout << tmpBook;
                }
            }
                break;
            case EDIT_BOOK_OPTION:{
                cout << "Edit Student" << endl;
                Book tmpBook(bookAdaptor);
                findOption = findObjectMenu(tmpBook);
                vector<int> idList = tmpBook.find(findOption);
                for (int id: idList) {
                    tmpBook.read(id);
                    cout << tmpBook;
                }
                if (idList.size() > 1) {
                    cout << "There Is More Than One Item!" << endl;
                    continue;
                }
                if (idList.empty()) {
                    continue;
                }
                editOption = editObjectMenu(tmpBook);
                tmpBook.edit(editOption, idList.at(0));
            }
                break;
            case DELETE_BOOK_OPTION:{
                cout << "Delete Book" << endl;
                Book tmpBook(bookAdaptor);
                findOption = findObjectMenu(tmpBook);
                vector<int> idList = tmpBook.find(findOption);
                for (int id: idList) {
                    tmpBook.read(id);
                    cout << tmpBook;
                }
                if (idList.size() > 1) {
                    cout << "There Is More Than One Item!" << endl;
                    continue;
                }
                if (idList.empty()) {
                    continue;
                }
                tmpBook.deleteObj(idList.at(0));
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
