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
    string fileName;
public:
    void setRecordSize(int recSize);
    virtual void writeRec() = 0;
    virtual void readRec() = 0;
    virtual void setRecord() = 0;
    virtual int getRecord(int index) = 0;
    virtual void setField(int size, string value) = 0;
    virtual string getField(int &startIndex) = 0;
    void setIntField(int num);
    int getIntField(int &startIndex);
    const Config &getAdpConf() const;
    void setFileName(const string &fileName);
};

class FixedRecordAdap : public Adaptor {
public:
    void writeRec() override;
    void readRec() override;
    void setRecord() override;
    int getRecord(int index) override ;
};

class DynamicRecordAdap : public Adaptor{
public:
    void writeRec() override;
    void readRec() override;
    void setRecord() override;
    int getRecord(int index) override ;
};

class FixedStringAdap {  //similar to interface in java
public:
    void setField(const string &fileName, int fieldSize, string fieldValue);
    string getField(const string &fileName, int &startIndex);
};

class DynamicStringAdap {   //similar to interface in java
public:
    void setField(const string &fileName, int fieldSize, string fieldValue);
    string getField(const string &fileName, int &startIndex);
};

class FixRecFixStrAdap: public FixedRecordAdap, public FixedStringAdap {
public:
    FixRecFixStrAdap(Config& conf);
    void writeRec() override;
    void readRec() override;
    void setField(int size, string value) override;
    string getField(int &startIndex) override;
};

class FixRecDynStrAdap: public FixedRecordAdap, public DynamicStringAdap {
public:
    FixRecDynStrAdap(Config& conf);
    void writeRec() override;
    void readRec() override;
    void setField(int size, string value) override;
    string getField(int &startIndex) override;
};

class DynRecFixStrAdap: public DynamicRecordAdap, public FixedStringAdap {
public:
    DynRecFixStrAdap(Config& conf);
    void writeRec() override;
    void readRec() override;
    void setField(int size, string value) override;
    string getField(int &startIndex) override;
};

class DynRecDynStrAdap: public DynamicRecordAdap, public DynamicStringAdap {
public:
    DynRecDynStrAdap(Config& conf);
    void writeRec() override;
    void readRec() override;
    void setField(int size, string value) override;
    string getField(int &startIndex) override;
};

int getFileSize(const string &fileName);

#endif //BOOKS_LIBRARY_ADAPTORS_H
