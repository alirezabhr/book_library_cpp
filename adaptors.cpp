#include "adaptors.h"


File::File(Adaptor *fAdapt) : fAdapt(fAdapt) {
    this->charFile = new char[fAdapt->getRecSize()];
}

void File::write(Student& s) {
    fAdapt->writeRec(s);

    /*
    ofstream outfile;
    outfile.open("binFile.txt", ios::binary | ios::out);
    outfile.write(reinterpret_cast<const char *>(&x), sizeof(int));
    outfile.write(reinterpret_cast<const char *>(&fx), sizeof(fx));
    outfile.close();
     */

//    int num;
//    double d;
//    string new_str;
//    ifstream infile;
//    infile.open("binFile.txt", ios::binary | ios::in);
//    infile.read(reinterpret_cast<char *>(&num), sizeof(int));
//    infile.read(reinterpret_cast<char *>(&d), sizeof(double));
//    infile.read(reinterpret_cast<char *>(&new_str), name.size());
//    cout << "num: " << num << "new str: " << new_str << endl;
}

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

void FixedRecordAdap::writeRec(Student& student) {
    std::cout << "write rec in FixedRecordAdap" << std::endl;
}

void FixRecFixStrAdap::writeRec(Student& student) {
    std::cout << "writeRec in FixRecFixStrAdap" << std::endl;
}