#ifndef BOOKS_LIBRARY_ADAPTORS_H
#define BOOKS_LIBRARY_ADAPTORS_H

#include <iostream>
#include <fstream>
#include "ui.h"

using namespace std;

class Adaptor;

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
