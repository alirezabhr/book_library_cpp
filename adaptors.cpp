#include "adaptors.h"

FixedRecordAdap::FixedRecordAdap(int fixRecSize) : fixRecSize(fixRecSize) {

}

FixedStringAdap::FixedStringAdap(int fixNameSize, int fixLastNameSize) : fixNameSize(fixNameSize),
                                                                         fixLastNameSize(fixLastNameSize) {

}

FixRecFixStrAdap::FixRecFixStrAdap(int fixRecSize, int fixNameSize, int fixLastNameSize) : FixedRecordAdap(fixRecSize),
                                                                                           FixedStringAdap(fixNameSize,
                                                                                                           fixLastNameSize) {
    data = new char[fixRecSize];
    name = new char[fixNameSize];
    lastName = new char[fixLastNameSize];
}

FixRecDynStrAdap::FixRecDynStrAdap(int fixRecSize) : FixedRecordAdap(fixRecSize) {
    data = new char[fixRecSize];
    name = new char[1];
    lastName = new char[1];
}

DynRecFixStrAdap::DynRecFixStrAdap(int fixNameSize, int fixLastNameSize) : FixedStringAdap(fixNameSize,
                                                                                           fixLastNameSize) {
    data = new char[1];
    name = new char[fixNameSize];
    lastName = new char[fixLastNameSize];
}

DynRecDynStrAdap::DynRecDynStrAdap() {
    data = new char[1];
    name = new char[1];
    lastName = new char[1];
}