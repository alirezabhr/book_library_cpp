#ifndef BOOKS_LIBRARY_ADAPTORS_H
#define BOOKS_LIBRARY_ADAPTORS_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class Adaptor;
class Config;

Config getAdaptorOptions();

class CONFIG_EXCEPTION {
    string msg;
public:
    CONFIG_EXCEPTION(const string &msg);

    const string &getMsg() const;
};

class Config {
    string recordMode;
    string stringMode;
    int recordSize;
    int studentNameSize;
    int studentLastNameSize;
public:
    Config();
    const string &getRecordMode() const;
    const string &getStringMode() const;
    int getRecordSize() const;
    int getStudentNameSize() const;
    int getStudentLastNameSize() const;
    void setFields(const string& field, const string& value);
    static vector<string> tokenize(string line);
};

class Adaptor {
protected:
    int recSize = 0;
    Config adpConf;
public:
    void setRecordSize(int recSize);
    virtual void writeRec() = 0;
    virtual void readRec(int index) = 0;
    virtual void setRecord() = 0;
    virtual void setField(int size, string value) = 0;
    void setIntField(int num);
    int getIntField(int &startIndex);

    const Config &getAdpConf() const;
};

class FixedRecordAdap : public Adaptor {
public:
    void writeRec() override;
    void readRec(int index) override;
    void setRecord() override;
    int getRecord(int index);
    void setField(int size, string value) override;
};

class DynamicRecordAdap : public Adaptor{
public:
    void writeRec() override;
    void readRec(int index) override;
    void setRecord() override;
    int getRecord(int index);
    void setField(int size, string value) override;
};

class FixedStringAdap {  //similar to interface in java
public:
    void setField(int fieldSize, string fieldValue);
    string getField(int &startIndex);
};

class DynamicStringAdap {   //similar to interface in java
public:
    void setField(int fieldSize, string fieldValue);
    string getField(int &startIndex);
};

class FixRecFixStrAdap: public FixedRecordAdap, public FixedStringAdap {
public:
    FixRecFixStrAdap(Config& conf);
    void writeRec() override;
    void readRec(int index) override;
    void setField(int size, string value) override;
};

class FixRecDynStrAdap: public FixedRecordAdap, public DynamicStringAdap {
public:
    FixRecDynStrAdap(Config& conf);
    void writeRec() override;
    void readRec(int index) override;
    void setField(int size, string value) override;
};

class DynRecFixStrAdap: public DynamicRecordAdap, public FixedStringAdap {
public:
    DynRecFixStrAdap(Config& conf);
    void writeRec() override;
    void readRec(int index) override;
    void setField(int size, string value) override;
};

class DynRecDynStrAdap: public DynamicRecordAdap, public DynamicStringAdap {
public:
    DynRecDynStrAdap(Config& conf);
    void writeRec() override;
    void readRec(int index) override;
    void setField(int size, string value) override;
};

#endif //BOOKS_LIBRARY_ADAPTORS_H
