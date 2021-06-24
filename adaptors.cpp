#include "adaptors.h"


FixRecFixStrAdap::FixRecFixStrAdap(Config& conf)  {
    this->adpConf = conf;
    this->recSize = conf.getRecordSize();
}

FixRecDynStrAdap::FixRecDynStrAdap(Config& conf) {
    this->adpConf = conf;
    this->recSize = conf.getRecordSize();
}

DynRecFixStrAdap::DynRecFixStrAdap(Config& conf) {
    adpConf = conf;
}

DynRecDynStrAdap::DynRecDynStrAdap(Config& conf) {
    adpConf = conf;
}

void Adaptor::setRecordSize(int recordSize) {
    Adaptor::recSize = recordSize;
}

char *Adaptor::readFromTo(int start, int end) {
    char *data = new char[end-start+1];

    ifstream infile;
    infile.open(this->fileName, ios::binary | ios::in);
    infile.seekg(start);
    infile.read(data, end - start);
    infile.close();
    data[end-start+1] = 0;

    return data;
}

void Adaptor::setIntField(int num) {
    string file = this->fileName;
    ofstream outfile;
    outfile.open(file, ios::binary | ios::out | ios::app);
    outfile.write(reinterpret_cast<const char *>(&num), sizeof(int));
    outfile.close();
}

int Adaptor::getIntField(int &startIndex) {
    string file = this->fileName;
    int fieldValue = -3;

    ifstream infile;
    infile.open(file, ios::binary | ios::in);
    infile.seekg(startIndex);
    infile.read(reinterpret_cast<char *>(&fieldValue), sizeof(int));
    startIndex += sizeof(int);

    infile.close();

    return fieldValue;
}

void Adaptor::editIntField(int startIndex, int num) {
    string file = this->fileName;
    int fieldValue = num;

    int fileSize = getFileSize(file);
    char *d1 = readFromTo(0,startIndex);
    char *d2 = readFromTo(startIndex+4, fileSize);

    ofstream outfile;
    outfile.open(file, ios::binary | ios::out);
    outfile.write(d1, startIndex);
    outfile.write(reinterpret_cast<char *>(&fieldValue), sizeof(int));
    outfile.write(d2, fileSize-(startIndex+4));

    outfile.close();
}

const Config &Adaptor::getAdpConf() const {
    return adpConf;
}

void Adaptor::setFileName(const string &fName) {
    Adaptor::fileName = fName;
}

void FixedRecordAdap::writeRec() {
    cout << "write rec in FixedRecordAdap" << endl;
}

void FixedRecordAdap::readRec() {
    cout << "read rec in FixedRecordAdap" << endl;
}

void FixedRecordAdap::setRecord() {
    cout << "Fixed Record Adap:: set record function" << endl;
    string file = this->fileName;
    int recordSize = adpConf.getRecordSize();
    int startIndex = 0;
    int tmpSize = 1;
    int fileSize = 0;
    int lastObjectId = 0;

    ifstream infile;
    infile.open(file, ios::binary | ios::in);
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
                infile.read(reinterpret_cast<char *>(&lastObjectId), sizeof(int));
                startIndex = startIndex + sizeof(int) + recordSize;
            }
            cout << "start index:" << startIndex << endl;
        }
    }

    int newId = lastObjectId + 1;

    infile.close();
    int zeroExSize = startIndex-fileSize;
    cout << "start index:" << startIndex << endl;

    ofstream outfile;
    outfile.open(file, ios::binary | ios::out | ios::app);
    char *zeroEx = new char[zeroExSize];
    for (int i = 0; i < zeroExSize; ++i) {
        zeroEx[i] = 0;
    }
    outfile.write(zeroEx, zeroExSize);
    delete[] zeroEx;
    outfile.write(reinterpret_cast<const char *>(&recordSize), sizeof(int));
    outfile.write(reinterpret_cast<const char *>(&newId), sizeof(int));
    outfile.close();
}

int FixedRecordAdap::getRecord(int index) {
    string file = this->fileName;
    int recordSize = -2;
    int totalSize = 0;
    int fileSize = 0;

    ifstream infile;
    infile.open(file, ios::binary | ios::in);
    fileSize = getFileSize(file);
    if (infile.fail()) {
        throw std::ifstream::failure("File Not Found!");
    }

    for (int i = 0; i < index-1; ++i) {
        totalSize += 4;
        infile.read(reinterpret_cast<char *>(&recordSize), sizeof(int));
        totalSize += recordSize;
        totalSize += 4;
        infile.seekg(totalSize);
        if (totalSize >= fileSize) {
            throw std::out_of_range("Dont have Object with this index number!");
        }
    }

    infile.close();

    return totalSize+4+4;
}

void DynamicRecordAdap::writeRec() {
    cout << "write rec in DynamicRecordAdap" << endl;
}

void DynamicRecordAdap::readRec() {
    cout << "read rec in DynamicRecordAdap" << endl;
}

void DynamicRecordAdap::setRecord() {
    cout << "DynRecordAdap::setRecord" << endl;
    string file = this->fileName;
    int startIndex = 0;
    int tmpSize = 1;
    int recordSize = this->recSize;
    int lastObjectId = 0;

    ifstream infile;
    infile.open(file, ios::binary | ios::in);
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
                infile.read(reinterpret_cast<char *>(&lastObjectId), sizeof(int));
                startIndex = startIndex + sizeof(int) + tmpSize;
            }
            cout << "start index:" << startIndex << endl;
        }
    }

    int newId = lastObjectId + 1;

    infile.close();
    ofstream outfile;
    outfile.open(file, ios::binary | ios::out | ios::app);
    outfile.write(reinterpret_cast<const char *>(&recordSize), sizeof(int));
    outfile.write(reinterpret_cast<const char *>(&newId), sizeof(int));
    outfile.close();
}

int DynamicRecordAdap::getRecord(int index) {
    cout << "Dyn Record Adap:: get record function" << endl;
    string file = this->fileName;
    int recordSize = -2;
    int totalSize = 0;
    int fileSize = 0;

    ifstream infile;
    infile.open(file, ios::binary | ios::in);
    fileSize = getFileSize(file);
    if (infile.fail()) {
        throw std::ifstream::failure("File Not Found!");
    }

    for (int i = 0; i < index-1; ++i) {
        totalSize += 4;
        infile.read(reinterpret_cast<char *>(&recordSize), sizeof(int));
        totalSize += recordSize;
        totalSize += 4;
        infile.seekg(totalSize);
        if (totalSize >= fileSize) {
            throw std::out_of_range("Dont have Object with this index number!");
        }
    }

    infile.close();

    return totalSize+4+4;
}

void FixedStringAdap::setField(const string &fileName, int fieldSize, string fieldValue) {
    cout << "Fixed String Adap:: set field function" << endl;
    const string& file = fileName;

    ofstream outfile;
    outfile.open(file, ios::binary | ios::out | ios::app);
    outfile.write(reinterpret_cast<const char *>(&fieldSize), sizeof(int));
    outfile.close();

    outfile.open(file, ios::out | ios::app);
    outfile << fieldValue;
    int zeroExSize = fieldSize - fieldValue.size();
    char *zeroEx = new char[zeroExSize];
    outfile.close();
    outfile.open(file, ios::binary | ios::out | ios::app);
    for (int i = 0; i < zeroExSize; ++i) {
        zeroEx[i] = 0;
    }
    outfile.write(zeroEx, zeroExSize);
    delete[] zeroEx;

    outfile.close();
}

string FixedStringAdap::getField(const string &fileName, int &startIndex) {
    cout << "Fixed String Adap:: get field function" << endl;
    const string& file = fileName;
    int fieldSize = -2;
    string fieldValue;

    ifstream infile;
    infile.open(file, ios::binary | ios::in);

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

void DynamicStringAdap::setField(const string &fileName, int fieldSize, string fieldValue) {
    cout << "Dynamic String Adap:: set field function" << endl;
    const string& file = fileName;

    ofstream outfile;
    outfile.open(file, ios::binary | ios::out | ios::app);
    outfile.write(reinterpret_cast<const char *>(&fieldSize), sizeof(int));
    outfile.close();

    outfile.open(file, ios::out | ios::app);
    outfile << fieldValue;
    outfile.close();
}

string DynamicStringAdap::getField(const string &fileName, int &startIndex) {
    cout << "Dynamic String Adap:: get field function" << endl;
    const string& file = fileName;
    int fieldSize = -2;
    string fieldValue;

    ifstream infile;
    infile.open(file, ios::binary | ios::in);

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

void FixRecFixStrAdap::writeRec() {
    cout << "writeRec in FixRecFixStrAdap" << endl;
}

void FixRecFixStrAdap::readRec() {
    cout << "readRec in FixRecFixStrAdap" << endl;
}

void FixRecFixStrAdap::setField(int size, string value) {
    cout << "FixRecFixStrAdap::setField" << endl;
    string file = this->fileName;
    FixedStringAdap::setField(file, size, value);
}

string FixRecFixStrAdap::getField(int &startIndex) {
    cout << "FixRecFixStrAdap::getField" << endl;
    string file = this->fileName;
    return FixedStringAdap::getField(file, startIndex);
}

void FixRecDynStrAdap::writeRec() {
    cout << "writeRec in FixRecDynStrAdap" << endl;
}

void FixRecDynStrAdap::readRec() {
    cout << "readRec in FixRecDynStrAdap" << endl;
}

void FixRecDynStrAdap::setField(int size, string value) {
    cout << "FixRecDynStrAdap::setField" << endl;
    string file = this->fileName;
    DynamicStringAdap::setField(file, size, value);
}

string FixRecDynStrAdap::getField(int &startIndex) {
    cout << "FixRecDynStrAdap::getField" << endl;
    string file = this->fileName;
    return DynamicStringAdap::getField(file, startIndex);
}

void DynRecFixStrAdap::writeRec() {
    cout << "writeRec in DynRecFixStrAdap" << endl;
}

void DynRecFixStrAdap::readRec() {
    cout << "readRec in DynRecFixStrAdap" << endl;
}

void DynRecFixStrAdap::setField(int size, string value) {
    cout << "DynRecFixStrAdap::setField" << endl;
    string file = this->fileName;
    FixedStringAdap::setField(file, size, value);
}

string DynRecFixStrAdap::getField(int &startIndex) {
    cout << "DynRecFixStrAdap::getField" << endl;
    string file = this->fileName;
    return FixedStringAdap::getField(file, startIndex);
}

void DynRecDynStrAdap::writeRec() {
    cout << "writeRec in DynRecDynStrAdap" << endl;
}

void DynRecDynStrAdap::readRec() {
    cout << "readRec in DynRecDynStrAdap" << endl;
}

void DynRecDynStrAdap::setField(int size, string value) {
    cout << "DynRecDynStrAdap::setField" << endl;
    string file = this->fileName;
    DynamicStringAdap::setField(file, size, value);
}

string DynRecDynStrAdap::getField(int &startIndex) {
    cout << "DynRecDynStrAdap::getField" << endl;
    string file = this->fileName;
    return DynamicStringAdap::getField(file, startIndex);
}

int getFileSize(const string &fileName) {
    int fileSize = 0;
    ifstream infile( fileName, ios::binary | ios::ate);
    fileSize = infile.tellg();
    infile.close();
    return fileSize;
}