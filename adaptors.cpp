#include "adaptors.h"

FixedRecordAdap::FixedRecordAdap(int fixRecSize) : fixRecSize(fixRecSize) {

}

FixedStringAdap::FixedStringAdap(int fixNameSize, int fixLastNameSize) : fixNameSize(fixNameSize),
                                                                         fixLastNameSize(fixLastNameSize) {

}

FixRecFixStrAdap::FixRecFixStrAdap(int fixRecSize, int fixNameSize, int fixLastNameSize) : FixedRecordAdap(fixRecSize),
                                                                                           FixedStringAdap(fixNameSize, fixLastNameSize) {
    data = new char[fixRecSize];
    name = new char[fixNameSize];
    lastName = new char[fixLastNameSize];
}

