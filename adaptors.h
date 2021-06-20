#ifndef BOOKS_LIBRARY_ADAPTORS_H
#define BOOKS_LIBRARY_ADAPTORS_H

#include <iostream>
#include <fstream>
#include "entities.h"
#include "ui.h"

using namespace std;

class Adaptor;

class File {
    Adaptor *fAdapt;
public:
    File(Adaptor *fAdapt);

    void write(Student& s);
    void read(int index, Student &s);
};

class Adaptor {
protected:
    int recSize = 0;
    Config adpConf;
public:
    virtual void writeRec(Student& student) = 0;
    virtual void readRec(int index, Student& student) = 0;
    virtual void setRecord() = 0;
    void setIntField(int num);
    int getIntField(int &startIndex);
};

class FixedRecordAdap : public Adaptor {
public:
    void writeRec(Student& student) override;
    void readRec(int index, Student& student) override;
    void setRecord() override;
    int getRecord(int index);
};

class DynamicRecordAdap : public Adaptor{
public:
    void writeRec(Student& student) override;
    void readRec(int index, Student& student) override;
    void setRecord() override;
    int getRecord(int index);
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
    void writeRec(Student& student) override;
    void readRec(int index, Student& student) override;
};

class FixRecDynStrAdap: public FixedRecordAdap, public DynamicStringAdap {
public:
    FixRecDynStrAdap(Config& conf);
    void writeRec(Student& student) override;
    void readRec(int index, Student& student) override;
};

class DynRecFixStrAdap: public DynamicRecordAdap, public FixedStringAdap {
public:
    DynRecFixStrAdap(Config& conf);
    void writeRec(Student& student) override;
    void readRec(int index, Student& student) override;
};

class DynRecDynStrAdap: public DynamicRecordAdap, public DynamicStringAdap {
public:
    DynRecDynStrAdap(Config& conf);
    void writeRec(Student& student) override;
    void readRec(int index, Student& student) override;
};

#endif //BOOKS_LIBRARY_ADAPTORS_H
