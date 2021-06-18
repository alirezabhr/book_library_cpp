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

FixRecFixStrAdap::FixRecFixStrAdap(Config& conf, int fixRecSize, int fixStrSize)  {
    this->adpConf = conf;
    this->recSize = fixRecSize;
    this->strSize = fixStrSize;
}

FixRecDynStrAdap::FixRecDynStrAdap(Config& conf, int fixRecSize) {
    this->adpConf = conf;
    this->recSize = fixRecSize;
}

int Adaptor::getRecSize() {
    return recSize;
}
int Adaptor::getStrSize() {
    return strSize;
}

void Adaptor::setIntField(int num) {
    const int intSize = sizeof(int);

    ofstream outfile;
    outfile.open("students.txt", ios::binary | ios::out | ios::app);
    outfile.write(reinterpret_cast<const char *>(&intSize), sizeof(int));
    outfile.write(reinterpret_cast<const char *>(&num), sizeof(int));
    outfile.close();
}

int Adaptor::getIntField(int &startIndex) {
    int fieldValue = -3;

    ifstream infile;
    infile.open("students.txt", ios::binary | ios::in);
    startIndex += sizeof(int);
    infile.seekg(startIndex);
    infile.read(reinterpret_cast<char *>(&fieldValue), sizeof(int));
    startIndex += sizeof(int);

    infile.close();

    return fieldValue;
}

void FixedRecordAdap::writeRec(Student& student) {
    cout << "write rec in FixedRecordAdap" << endl;
}

void FixedRecordAdap::readRec(int index, Student &student) {
    cout << "read rec in FixedRecordAdap" << endl;
}

void FixedRecordAdap::setRecord() {
    cout << "Fixed Record Adap:: set record function" << endl;
    int recordSize = adpConf.getRecordSize();

    ofstream outfile;
    outfile.open("students.txt", ios::binary | ios::out | ios::app);
    outfile.write(reinterpret_cast<const char *>(&recordSize), sizeof(int));
    outfile.close();
}

int FixedRecordAdap::getRecord(int index) {
    int recordSize = -2;
    int totalSize = 0;

    ifstream infile;
    infile.open("students.txt", ios::binary | ios::in);

    for (int i = 0; i < index-1; ++i) {
        infile.read(reinterpret_cast<char *>(&recordSize), sizeof(int));
        totalSize += recordSize;
        infile.seekg(recordSize);
    }

    infile.close();

    return totalSize+4;
}

void FixedStringAdap::setField(int fieldSize, string fieldValue) {
    cout << "Fixed String Adap:: set field function" << endl;

    ofstream outfile;
    outfile.open("students.txt", ios::binary | ios::out | ios::app);
    outfile.write(reinterpret_cast<const char *>(&fieldSize), sizeof(int));
    outfile.close();
//    outfile.write(reinterpret_cast<const char *>(&fieldValue), fieldSize);
//    outfile.write(reinterpret_cast<const char *>(&fieldValue), fieldValue.size());
    outfile.open("students.txt", ios::out | ios::app);
    outfile << fieldValue;
    int tmpSize = fieldSize - fieldValue.size();
    char *tmp = new char[tmpSize];
    outfile.close();
    outfile.open("students.txt", ios::binary | ios::out | ios::app);
    for (int i = 0; i < tmpSize; ++i) {
        tmp[i] = 0;
    }
    outfile.write(tmp, fieldSize - fieldValue.size());
//    outfile << tmp;
    outfile.close();
}

string FixedStringAdap::getField(int &startIndex) {
    int fieldSize = -2;
    string fieldValue;

    ifstream infile;
    infile.open("students.txt", ios::binary | ios::in);

    infile.seekg(startIndex);
    infile.read(reinterpret_cast<char *>(&fieldSize), sizeof(int));
    startIndex += sizeof(int);

    char *tmp = new char[fieldSize];
    infile.read(tmp, fieldSize);
    startIndex += fieldSize;

    infile.close();

    fieldValue = tmp;

    return fieldValue;
}

void FixRecFixStrAdap::writeRec(Student& student) {
    cout << "writeRec in FixRecFixStrAdap" << endl;

    int id = student.getStudentId();
    int nameSize = adpConf.getStudentNameSize();
    int lastNameSize = adpConf.getStudentLastNameSize();

    setRecord();
    setIntField(id);
    setField(nameSize, student.getName());
    setField(lastNameSize, student.getLastName());
}

void FixRecFixStrAdap::readRec(int index, Student &student) {
    cout << "readRec in FixRecFixStrAdap" << endl;
    int startIndex = 0;
    int stdId;
    string stdName;
    string stdLastName;

    startIndex = getRecord(index);
    stdId = getIntField(startIndex);
    stdName = getField(startIndex);
    stdLastName = getField(startIndex);

    cout << "std id: =" << stdId << "=" << endl;
    cout << "std name is: =" << stdName << "=" << endl;
    cout << "std last name is: =" << stdLastName << "=" << endl;
}
