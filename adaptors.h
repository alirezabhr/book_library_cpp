#pragma once
#ifndef BOOKS_LIBRARY_ADAPTORS_H
#define BOOKS_LIBRARY_ADAPTORS_H

#include <iostream>
#include "entities.h"

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
//    virtual std::string writeStudent(Student &s) = 0;
public:
    int getRecSize();
    int getStrSize();
    virtual void writeRec(Student& student) = 0;
//    virtual void readRec() = 0;
};

class FixedRecordAdap : public Adaptor {
public:
    void writeRec(Student& student) override ;
};

class DynamicRecordAdap {
public:
};

class FixedStringAdap{
public:
};

class DynamicStringAdap {
public:
};

class FixRecFixStrAdap: public FixedRecordAdap, public FixedStringAdap {
public:
    FixRecFixStrAdap(int fixRecSize, int fixStrSize);
    void writeRec(Student& student) override;
};

class FixRecDynStrAdap: public FixedRecordAdap, public DynamicStringAdap {
public:
    FixRecDynStrAdap(int fixRecSize);
};

class DynRecFixStrAdap: public Adaptor, public DynamicRecordAdap, public FixedStringAdap {
public:
   DynRecFixStrAdap(int fixNameSize, int fixLastNameSize);
};

class DynRecDynStrAdap: public Adaptor, public DynamicRecordAdap, public DynamicStringAdap {
public:
    DynRecDynStrAdap();
};

#endif //BOOKS_LIBRARY_ADAPTORS_H
