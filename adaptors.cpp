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

DynRecFixStrAdap::DynRecFixStrAdap(Config& conf) {
    adpConf = conf;
}

DynRecDynStrAdap::DynRecDynStrAdap(Config& conf) {
    adpConf = conf;
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
    int startIndex = 0;
    int tmpSize = 1;
    int fileSize = 0;

    ifstream infile;
    infile.open("students.txt", ios::binary | ios::in);
    if (!infile.fail()) {    // file could be opened
        infile.seekg (0, std::ifstream::end);
        fileSize = infile.tellg();
        infile.seekg (0);
        cout << "before while" << "\ttmp Size:" << tmpSize << "\tstart index:" << startIndex << endl;
        while(true) {
            tmpSize = 0;
            infile.seekg(startIndex);
            infile.read(reinterpret_cast<char *>(&tmpSize), sizeof(int));
            cout << "tmp Size:" << tmpSize << endl;
            if (tmpSize == 0) break;
            else {
                startIndex = startIndex + sizeof(int) + recordSize;
            }
            cout << "start index:" << startIndex << endl;
        }
    }
    infile.close();
    int zeroExSize = startIndex-fileSize;
    cout << "start index:" << startIndex << endl;

    ofstream outfile;
    outfile.open("students.txt", ios::binary | ios::out | ios::app);
    char *zeroEx = new char[zeroExSize];
    for (int i = 0; i < zeroExSize; ++i) {
        zeroEx[i] = 0;
    }
    outfile.write(zeroEx, zeroExSize);
    delete[] zeroEx;
    outfile.write(reinterpret_cast<const char *>(&recordSize), sizeof(int));
    outfile.close();
}

int FixedRecordAdap::getRecord(int index) {
    int recordSize = -2;
    int totalSize = 0;

    ifstream infile;
    infile.open("students.txt", ios::binary | ios::in);

    for (int i = 0; i < index-1; ++i) {
        totalSize += 4;
        infile.read(reinterpret_cast<char *>(&recordSize), sizeof(int));
        totalSize += recordSize;
        infile.seekg(totalSize);
    }

    infile.close();

    return totalSize+4;
}

void DynamicRecordAdap::writeRec(Student &student) {
    cout << "write rec in DynamicRecordAdap" << endl;
}

void DynamicRecordAdap::readRec(int index, Student &student) {
    cout << "read rec in DynamicRecordAdap" << endl;
}

void DynamicRecordAdap::setRecord() {
    cout << "Dyn Record Adap:: set record function" << endl;
    int startIndex = 0;
    int tmpSize = 1;
    int recordSize = this->recSize;

    ifstream infile;
    infile.open("students.txt", ios::binary | ios::in);
    if (!infile.fail()) {    // file could be opened
        infile.seekg (0);
        cout << "before while in set record" << "\ttmp Size: " << tmpSize << "\tstart index: " << startIndex << endl;
        while(true) {
            tmpSize = 0;
            infile.seekg(startIndex);
            infile.read(reinterpret_cast<char *>(&tmpSize), sizeof(int));
            cout << "tmp Size:" << tmpSize << endl;
            if (tmpSize == 0) break;
            else {
                startIndex = startIndex + sizeof(int) + tmpSize;
            }
            cout << "start index:" << startIndex << endl;
        }
    }
    infile.close();
    ofstream outfile;
    outfile.open("students.txt", ios::binary | ios::out | ios::app);
    outfile.write(reinterpret_cast<const char *>(&recordSize), sizeof(int));
    outfile.close();
}

int DynamicRecordAdap::getRecord(int index) {
    cout << "Dyn Record Adap:: get record function" << endl;
    int recordSize = -2;
    int totalSize = 0;

    ifstream infile;
    infile.open("students.txt", ios::binary | ios::in);

    for (int i = 0; i < index-1; ++i) {
        totalSize += 4;
        infile.read(reinterpret_cast<char *>(&recordSize), sizeof(int));
        totalSize += recordSize;
        infile.seekg(totalSize);
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

    outfile.open("students.txt", ios::out | ios::app);
    outfile << fieldValue;
    int zeroExSize = fieldSize - fieldValue.size();
    char *zeroEx = new char[zeroExSize];
    outfile.close();
    outfile.open("students.txt", ios::binary | ios::out | ios::app);
    for (int i = 0; i < zeroExSize; ++i) {
        zeroEx[i] = 0;
    }
    outfile.write(zeroEx, zeroExSize);
    delete[] zeroEx;

    outfile.close();
}

string FixedStringAdap::getField(int &startIndex) {
    cout << "Fixed String Adap:: get field function" << endl;
    int fieldSize = -2;
    string fieldValue;

    ifstream infile;
    infile.open("students.txt", ios::binary | ios::in);

    infile.seekg(startIndex);
    infile.read(reinterpret_cast<char *>(&fieldSize), sizeof(int));
    startIndex += sizeof(int);

    char *tmp = new char[fieldSize+1];
    infile.read(tmp, fieldSize);
    tmp[fieldSize] = 0;
    startIndex += fieldSize;

    infile.close();

    fieldValue = tmp;
    delete[] tmp;

    return fieldValue;
}

void DynamicStringAdap::setField(int fieldSize, string fieldValue) {
    cout << "Dynamic String Adap:: set field function" << endl;

    ofstream outfile;
    outfile.open("students.txt", ios::binary | ios::out | ios::app);
    outfile.write(reinterpret_cast<const char *>(&fieldSize), sizeof(int));
    outfile.close();

    outfile.open("students.txt", ios::out | ios::app);
    outfile << fieldValue;
    outfile.close();
}

string DynamicStringAdap::getField(int &startIndex) {
    cout << "Dynamic String Adap:: get field function" << endl;
    int fieldSize = -2;
    string fieldValue;

    ifstream infile;
    infile.open("students.txt", ios::binary | ios::in);

    infile.seekg(startIndex);
    infile.read(reinterpret_cast<char *>(&fieldSize), sizeof(int));
    startIndex += sizeof(int);

    char *tmp = new char[fieldSize+1];
    infile.read(tmp, fieldSize);
    tmp[fieldSize] = 0;
    startIndex += fieldSize;

    infile.close();

    fieldValue = tmp;
    delete[] tmp;

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

void FixRecDynStrAdap::writeRec(Student &student) {
    cout << "writeRec in FixRecDynStrAdap" << endl;

    int id = student.getStudentId();
    int nameSize = student.getName().size();
    int lastNameSize = student.getLastName().size();

    setRecord();
    setIntField(id);
    setField(nameSize, student.getName());
    setField(lastNameSize, student.getLastName());
}

void FixRecDynStrAdap::readRec(int index, Student &student) {
    cout << "readRec in FixRecDynStrAdap" << endl;
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

void DynRecFixStrAdap::writeRec(Student &student) {
    cout << "writeRec in DynRecFixStrAdap" << endl;

    int recordSize = 0;
    int id = student.getStudentId();
    recordSize += sizeof(int);
    recordSize += sizeof(int);
    int nameSize = adpConf.getStudentNameSize();
    recordSize += sizeof(int);
    recordSize += nameSize;
    int lastNameSize = adpConf.getStudentLastNameSize();
    recordSize += sizeof(int);
    recordSize += lastNameSize;

    this->recSize = recordSize;

    setRecord();
    setIntField(id);
    setField(nameSize, student.getName());
    setField(lastNameSize, student.getLastName());
}

void DynRecFixStrAdap::readRec(int index, Student &student) {
    cout << "readRec in DynRecFixStrAdap" << endl;
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

void DynRecDynStrAdap::writeRec(Student &student) {
    cout << "writeRec in DynRecDynStrAdap" << endl;

    int recordSize = 0;
    int id = student.getStudentId();
    recordSize += sizeof(int);
    recordSize += sizeof(int);
    int nameSize = student.getName().size();
    recordSize += sizeof(int);
    recordSize += nameSize;
    int lastNameSize = student.getLastName().size();
    recordSize += sizeof(int);
    recordSize += lastNameSize;

    this->recSize = recordSize;

    setRecord();
    setIntField(id);
    setField(nameSize, student.getName());
    setField(lastNameSize, student.getLastName());
}

void DynRecDynStrAdap::readRec(int index, Student &student) {
    cout << "readRec in DynRecDynStrAdap" << endl;
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
