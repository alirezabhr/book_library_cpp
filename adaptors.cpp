#include "adaptors.h"


File::File(Adaptor *fAdapt) : fAdapt(fAdapt) {
    this->charFile = new char[fAdapt->getRecSize()];
}

void File::write(Student& s) {
    fAdapt->writeRec(s);
}

void File::read(int index, Student &s) {
    fAdapt->readRec(index, s);
}

FixRecFixStrAdap::FixRecFixStrAdap(int fixRecSize, int fixStrSize)  {
    this->recSize = fixRecSize;
    this->strSize = fixStrSize;
}

FixRecDynStrAdap::FixRecDynStrAdap(int fixRecSize) {

}

int Adaptor::getRecSize() {
    return recSize;
}
int Adaptor::getStrSize() {
    return strSize;
}

void FixedRecordAdap::writeRec(Student& student) {
    cout << "write rec in FixedRecordAdap" << endl;
}

void FixedRecordAdap::readRec(int index, Student &student) {
    cout << "read rec in FixedRecordAdap" << endl;
}

void FixRecFixStrAdap::writeRec(Student& student) {
    cout << "writeRec in FixRecFixStrAdap" << endl;

    int id = student.getStudentId();
    string name = student.getName();

    ofstream outfile;
    outfile.open("students.txt", ios::binary | ios::out | ios::app);
    outfile.write(reinterpret_cast<const char *>(&id), sizeof(id));
    outfile.write(reinterpret_cast<const char *>(&name), name.size());
    outfile.close();
}

void FixRecFixStrAdap::readRec(int index, Student &student) {
    cout << "readRec in FixRecFixStrAdap" << endl;
    cout << "index: " << index << endl;
    int id;
    string name;

    ifstream infile;
    infile.open("students.txt", ios::binary | ios::in);
    infile.read(reinterpret_cast<char *>(&id), sizeof(id));
    infile.read(reinterpret_cast<char *>(&name), 23);
    infile.close();

    cout << "id: " << id << " | name: " << name << endl;
}

