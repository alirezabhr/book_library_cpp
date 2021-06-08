#ifndef BOOKS_LIBRARY_ADAPTORS_H
#define BOOKS_LIBRARY_ADAPTORS_H

#include <string>
#include "entities.h"

class Adaptor {
public:
    int recSize = 0;
    int nSize = 0;
    int lnSize = 0;
    virtual std::string writeStudent(Student &s) = 0;
};

class FixedRecordAdap: public Adaptor {
    int fixRecSize;
public:
    FixedRecordAdap(int fixRecSize);
};

class DynamicRecordAdap: public Adaptor {
public:
};

class FixedStringAdap: public Adaptor {
    int fixNameSize;
    int fixLastNameSize;
public:
    FixedStringAdap(int fixNameSize, int fixLastNameSize);
};

class DynamicStringAdap: public Adaptor {
public:
};

class FixRecFixStrAdap: public FixedRecordAdap, public FixedStringAdap {
    char *data;
    char *name;
    char *lastName;
public:
    FixRecFixStrAdap(int fixRecSize, int fixNameSize, int fixLastNameSize);
};

class FixRecDynStrAdap: public FixedRecordAdap, public DynamicStringAdap {

};

class DynRecFixStrAdap: public DynamicRecordAdap, public FixedStringAdap {

};

class DynRecDynStrAdap: public DynamicRecordAdap, public DynamicStringAdap {

};

#endif //BOOKS_LIBRARY_ADAPTORS_H
