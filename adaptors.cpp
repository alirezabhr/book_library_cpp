#include "adaptors.h"


Config getAdaptorOptions() {
    vector<string> lines;
    vector<string> tmp;
    vector<string> commands;
    string line;
    Config config;

    ifstream infile;
    infile.open("config.txt");

    while (getline(infile, line)) {
        if (line.empty()) {
            continue;
        }
        if (line.at(0) == '#') {
            continue;
        }
        lines.push_back(line);
    }

    for (auto &it : lines) {
        tmp = Config::tokenize(it);
        commands.push_back(tmp.at(0));
        commands.push_back(tmp.at(1));
    }

    for (int i=0; i<commands.size(); i+=2) {
        string cmd1 = commands.at(i);
        string cmd2 = commands.at(i+1);
        config.setFields(cmd1, cmd2);
    }

    return config;
}

CONFIG_EXCEPTION::CONFIG_EXCEPTION(const string &msg) : msg(msg) {}

const string &CONFIG_EXCEPTION::getMsg() const {
    return msg;
}

Config::Config() {
    recordSize = 0;
    studentNameSize = 0;
    studentLastNameSize = 0;
}

const string &Config::getRecordMode() const {
    return recordMode;
}

const string &Config::getStringMode() const {
    return stringMode;
}

int Config::getRecordSize() const {
    return recordSize;
}

int Config::getStudentNameSize() const {
    return studentNameSize;
}

int Config::getStudentLastNameSize() const {
    return studentLastNameSize;
}

void Config::setFields(const std::string& field, const std::string& value) {
    if (field == "RECORD_MODE") {
        if (value == "Fix") {
            this->recordMode = value;
        } else if (value == "Dyn") {
            this->recordMode = value;
        } else {
            throw CONFIG_EXCEPTION("Wrong Record Mode!");
        }
    } else if (field == "STRING_MODE") {
        if (value == "Fix") {
            this->stringMode = value;
        } else if (value == "Dyn") {
            this->stringMode = value;
        } else {
            throw CONFIG_EXCEPTION("Wrong String Mode!");
        }
    } else if (field == "RECORD_SIZE") {
        if (this->recordMode == "Dyn") {
            this->recordSize = -1;
        } else {
            try {
                this->recordSize = stoi(value);
                if (this->recordSize < 0) {
                    throw CONFIG_EXCEPTION("Record Size Is Not Valid!\nTry A Positive Number");
                }
            } catch (exception &err) {
                throw CONFIG_EXCEPTION("Record Size Is Not Valid!");
            }
        }
    } else if (field == "STD_NAME_SIZE") {
        if (this->stringMode == "Dyn") {
            this->studentNameSize = -1;
        } else {
            try {
                this->studentNameSize = stoi(value);
                if (this->studentNameSize < 0) {
                    throw CONFIG_EXCEPTION("Student Name Size Is Not Valid!\nTry A Positive Number");
                }
            } catch (exception &err) {
                throw CONFIG_EXCEPTION("Student Name Size Is Not Valid!");
            }
        }
    } else if (field == "STD_LAST_NAME_SIZE") {
        if (this->stringMode == "Dyn") {
            this->studentLastNameSize = -1;
        } else {
            try {
                this->studentLastNameSize = stoi(value);
                if (this->studentLastNameSize < 0) {
                    throw CONFIG_EXCEPTION("Student Last Name Size Is Not Valid!\nTry A Positive Number");
                }
            } catch (exception &err) {
                throw CONFIG_EXCEPTION("Student Last Name Size Is Not Valid!");
            }
        }
    } else {
        cout << "WRONG CONFIGURATION KEY!" << endl;
    }
}

vector<string> Config::tokenize(string line) {
    string delimiter = " = ";
    vector<string> v1;

    int pos = 0;
    string token;
    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        v1.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    v1.push_back(line);

    return v1;
}

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

const Config &Adaptor::getAdpConf() const {
    return adpConf;
}

void FixedRecordAdap::writeRec() {
    cout << "write rec in FixedRecordAdap" << endl;
}

void FixedRecordAdap::readRec(int index) {
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

void FixedRecordAdap::setField(int size, string value) {
    cout << "FixedRecordAdap::setField not ok" << endl;
}

void DynamicRecordAdap::writeRec() {
    cout << "write rec in DynamicRecordAdap" << endl;
}

void DynamicRecordAdap::readRec(int index) {
    cout << "read rec in DynamicRecordAdap" << endl;
}

void DynamicRecordAdap::setRecord() {
    cout << "DynRecordAdap::setRecord" << endl;
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

void DynamicRecordAdap::setField(int size, string value) {
    cout << "DynamicRecordAdap::setField not ok" << endl;
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

void FixRecFixStrAdap::writeRec() {
    cout << "writeRec in FixRecFixStrAdap" << endl;
}

void FixRecFixStrAdap::readRec(int index) {
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

void FixRecFixStrAdap::setField(int size, string value) {
    cout << "FixRecFixStrAdap::setField maybe ok" << endl;
    FixedStringAdap::setField(size, value);
}

void FixRecDynStrAdap::writeRec() {
    cout << "writeRec in FixRecDynStrAdap" << endl;
}

void FixRecDynStrAdap::readRec(int index) {
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

void FixRecDynStrAdap::setField(int size, string value) {
    cout << "FixRecDynStrAdap::setField maybe ok" << endl;
    DynamicStringAdap::setField(size, value);
}

void DynRecFixStrAdap::writeRec() {
    cout << "writeRec in DynRecFixStrAdap" << endl;
}

void DynRecFixStrAdap::readRec(int index) {
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

void DynRecFixStrAdap::setField(int size, string value) {
    cout << "DynRecFixStrAdap::setField maybe ok" << endl;
    FixedStringAdap::setField(size, value);
}

void DynRecDynStrAdap::writeRec() {
    cout << "writeRec in DynRecDynStrAdap" << endl;
}

void DynRecDynStrAdap::readRec(int index) {
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

void DynRecDynStrAdap::setField(int size, string value) {
    cout << "DynRecDynStrAdap::setField maybe ok" << endl;
    DynamicStringAdap::setField(size, value);
}
