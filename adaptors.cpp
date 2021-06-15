#include "adaptors.h"

//FixedRecordAdap::FixedRecordAdap(int fixRecSize) : fixRecSize(fixRecSize) {
//
//}
//
//FixedStringAdap::FixedStringAdap(int fixNameSize, int fixLastNameSize) : fixNameSize(fixNameSize),
//                                                                         fixLastNameSize(fixLastNameSize) {
//
//}

FixRecFixStrAdap::FixRecFixStrAdap(int fixRecSize, int fixStrSize)  {
    this->recSize = fixRecSize;
    this->strSize = fixStrSize;
}

FixRecDynStrAdap::FixRecDynStrAdap(int fixRecSize) {

}

//DynRecFixStrAdap::DynRecFixStrAdap(int fixNameSize, int fixLastNameSize) : FixedStringAdap(fixNameSize,
//                                                                                           fixLastNameSize) {
//    data = new char[1];
//    name = new char[fixNameSize];
//    lastName = new char[fixLastNameSize];
//}
//
//DynRecDynStrAdap::DynRecDynStrAdap() {
//    data = new char[1];
//    name = new char[1];
//    lastName = new char[1];
//}

int Adaptor::getRecSize() {
    return recSize;
}
int Adaptor::getStrSize() {
    return strSize;
}