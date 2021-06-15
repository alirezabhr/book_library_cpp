#ifndef BOOKS_LIBRARY_ADAPTORS_H
#define BOOKS_LIBRARY_ADAPTORS_H

#include <string>

class Adaptor {
protected:
    int recSize = 0;
    int strSize = 0;
//    virtual std::string writeStudent(Student &s) = 0;
public:
    int getRecSize();
    int getStrSize();
};

class FixedRecordAdap {
public:
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

class FixRecFixStrAdap: public Adaptor, public FixedRecordAdap, public FixedStringAdap {
public:
    FixRecFixStrAdap(int fixRecSize, int fixStrSize);
};

class FixRecDynStrAdap: public Adaptor, public FixedRecordAdap, public DynamicStringAdap {
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
