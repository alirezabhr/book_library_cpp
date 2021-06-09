#ifndef BOOKS_LIBRARY_ADAPTORS_H
#define BOOKS_LIBRARY_ADAPTORS_H

#include <string>
//#include "entities.h"

class Adaptor {
public:
    int recSize = 0;
    int nSize = 0;
    int lnSize = 0;
//    virtual std::string writeStudent(Student &s) = 0;
};

class FixedRecordAdap {
    int fixRecSize;
public:
    FixedRecordAdap(int fixRecSize);
};

class DynamicRecordAdap {
public:
};

class FixedStringAdap{
    int fixNameSize;
    int fixLastNameSize;
public:
    FixedStringAdap(int fixNameSize, int fixLastNameSize);
};

class DynamicStringAdap {
public:
};

class FixRecFixStrAdap: public Adaptor, public FixedRecordAdap, public FixedStringAdap {
    char *data;
    char *name;
    char *lastName;
public:
    FixRecFixStrAdap(int fixRecSize, int fixNameSize, int fixLastNameSize);
};

class FixRecDynStrAdap: public Adaptor, public FixedRecordAdap, public DynamicStringAdap {
    char *data;
    char *name;
    char *lastName;
public:
    FixRecDynStrAdap(int fixRecSize);
};

class DynRecFixStrAdap: public Adaptor, public DynamicRecordAdap, public FixedStringAdap {
    char *data;
    char *name;
    char *lastName;
public:
   DynRecFixStrAdap(int fixNameSize, int fixLastNameSize);
};

class DynRecDynStrAdap: public Adaptor, public DynamicRecordAdap, public DynamicStringAdap {
    char *data;
    char *name;
    char *lastName;
public:
    DynRecDynStrAdap();
};

#endif //BOOKS_LIBRARY_ADAPTORS_H
