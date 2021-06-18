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
    char *charFile;
public:
    File(Adaptor *fAdapt);

    void write(Student& s);
    void read(int index, Student &s);
    void append(char *data);
};

class Adaptor {
protected:
    int recSize = 0;
    int strSize = 0;
    Config adpConf;
public:
    int getRecSize();
    int getStrSize();
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

class DynamicRecordAdap {
public:
};

class FixedStringAdap{
public:
    void setField(int fieldSize, string fieldValue);
    string getField(int &startIndex);
};

class DynamicStringAdap {
public:
};

class FixRecFixStrAdap: public FixedRecordAdap, public FixedStringAdap {
public:
    FixRecFixStrAdap(Config& conf, int fixRecSize, int fixStrSize);
    void writeRec(Student& student) override;
    void readRec(int index, Student& student) override;
};

class FixRecDynStrAdap: public FixedRecordAdap, public DynamicStringAdap {
public:
    FixRecDynStrAdap(Config& conf, int fixRecSize);
};

class DynRecFixStrAdap: public Adaptor, public DynamicRecordAdap, public FixedStringAdap {
public:
   DynRecFixStrAdap(Config conf, int fixNameSize, int fixLastNameSize);
};

class DynRecDynStrAdap: public Adaptor, public DynamicRecordAdap, public DynamicStringAdap {
public:
    DynRecDynStrAdap(Config conf);
};

#endif //BOOKS_LIBRARY_ADAPTORS_H
