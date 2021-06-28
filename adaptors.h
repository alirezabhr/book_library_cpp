#ifndef BOOKS_LIBRARY_ADAPTORS_H
#define BOOKS_LIBRARY_ADAPTORS_H

#include <iostream>
#include <fstream>
#include <vector>
#include "configurations.h"

using namespace std;


class Adaptor;

class Adaptor {
protected:
//    int recSize = 0;
    Config adpConf;
    string fileName;
public:
    void setRecSize(int recSize);
    int getRecSize();
    char *readFromTo(int start, int end);
    virtual void writeRec() = 0;
    virtual void readRec() = 0;
    virtual void setRecord(int size) = 0;
    virtual int getRecord(int index) = 0;
//    virtual void editRecord(int index, int diff) = 0;
    virtual void edit(char *data1, char *data2) = 0;
    virtual void setField(int size, string value) = 0;
    virtual string getField(int &startIndex) = 0;
    virtual void editField(int startIndex, int size, string value) = 0;
    void setIntField(int num);
    int getIntField(int &startIndex);
    void editIntField(int startIndex, int num);
    const Config &getAdpConf() const;
    void setFileName(const string &fileName);

    const string &getFileName() const;
};

class FixedRecordAdap : public Adaptor {
public:
    void writeRec() override;
    void readRec() override;
    void setRecord(int size) override;
    int getRecord(int index) override;
//    void editRecord(int index, int diff) override;
};

class DynamicRecordAdap : public Adaptor{
public:
    void writeRec() override;
    void readRec() override;
    void setRecord(int size) override;
    int getRecord(int index) override;
//    void editRecord(int index, int diff) override;
};

class FixedStringAdap {  //similar to interface in java
public:
    void setField(const string &fileName, int fieldSize, string fieldValue);
    string getField(const string &fileName, int &startIndex);
    void editField(const string &fileName, int startIndex, int size, string &value, char *data1, char *data2);
};

class DynamicStringAdap {   //similar to interface in java
public:
    void setField(const string &fileName, int fieldSize, string fieldValue);
    string getField(const string &fileName, int &startIndex);
    void editField(const string &fileName, int startIndex, int size, string &value, char *data1, char *data2);
};

class FixRecFixStrAdap: public FixedRecordAdap, public FixedStringAdap {
public:
    FixRecFixStrAdap(Config& conf);
    void writeRec() override;
    void readRec() override;
    void setField(int size, string value) override;
    string getField(int &startIndex) override;
    void editField(int startIndex, int size, string value) override;
    void edit(char *data1, char *data2) override;
};

class FixRecDynStrAdap: public FixedRecordAdap, public DynamicStringAdap {
public:
    FixRecDynStrAdap(Config& conf);
    void writeRec() override;
    void readRec() override;
    void setField(int size, string value) override;
    string getField(int &startIndex) override;
    void editField(int startIndex, int size, string value) override;
    void edit(char *data1, char *data2) override;
};

class DynRecFixStrAdap: public DynamicRecordAdap, public FixedStringAdap {
public:
    DynRecFixStrAdap(Config& conf);
    void writeRec() override;
    void readRec() override;
    void setField(int size, string value) override;
    string getField(int &startIndex) override;
    void editField(int startIndex, int size, string value) override;
    void edit(char *data1, char *data2) override;
};

class DynRecDynStrAdap: public DynamicRecordAdap, public DynamicStringAdap {
public:
    DynRecDynStrAdap(Config& conf);
    void writeRec() override;
    void readRec() override;
    void setField(int size, string value) override;
    string getField(int &startIndex) override;
    void editField(int startIndex, int size, string value) override;
    void edit(char *data1, char *data2) override;
};

int getFileSize(const string &fileName);

#endif //BOOKS_LIBRARY_ADAPTORS_H
