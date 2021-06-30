#include "configurations.h"


Config getAdaptorOptions() {
    vector<string> lines;
    vector<string> tmp;
    vector<string> commands;
    string line;
    Config config;

    ifstream infile;
    infile.open("config.txt");

    while (getline(infile, line)) {
        if (line.empty()) {
            continue;
        }
        if (line.at(0) == '#') {
            continue;
        }
        lines.push_back(line);
    }

    for (auto &it : lines) {
        tmp = Config::tokenize(it);
        commands.push_back(tmp.at(0));
        commands.push_back(tmp.at(1));
    }

    for (int i=0; i<commands.size(); i+=2) {
        string cmd1 = commands.at(i);
        string cmd2 = commands.at(i+1);
        config.setFields(cmd1, cmd2);
    }

    config.checkConfigValidation();

    return config;
}

CONFIG_EXCEPTION::CONFIG_EXCEPTION(const string &msg) : msg(msg) {}

const string &CONFIG_EXCEPTION::getMsg() const {
    return msg;
}

Config::Config() {
}

const string &Config::getStudentRecordMode() const {
    return studentRecordMode;
}

const string &Config::getStudentStringMode() const {
    return studentStringMode;
}

int Config::getStudentRecordSize() const {
    return studentRecordSize;
}

int Config::getStudentNameSize() const {
    return studentNameSize;
}

int Config::getStudentLastNameSize() const {
    return studentLastNameSize;
}

const string &Config::getBookRecordMode() const {
    return bookRecordMode;
}

const string &Config::getBookStringMode() const {
    return bookStringMode;
}

int Config::getBookRecordSize() const {
    return bookRecordSize;
}

int Config::getBookNameSize() const {
    return bookNameSize;
}

int Config::getBookAuthorSize() const {
    return bookAuthorSize;
}

int Config::getBookPublisherSize() const {
    return bookPublisherSize;
}

const string &Config::getLibRecRecordMode() const {
    return libRecRecordMode;
}

const string &Config::getLibRecStringMode() const {
    return libRecStringMode;
}

int Config::getLibRecRecordSize() const {
    return libRecRecordSize;
}

/**
 * This function uses to set attributes and assign a value to them.
 * It will check the name of field, and if it is correct is will assign the value to the attribute
 *
 * @param field The name of field (this is what you wrote in config.txt file)
 * @param value The value of field
 * @return void
 */
void Config::setFields(const std::string& field, const std::string& value) {
    if (field == "STD_RECORD_MODE") {
        if (value == "Fix") {
            this->studentRecordMode = value;
        } else if (value == "Dyn") {
            this->studentRecordMode = value;
        } else {
            throw CONFIG_EXCEPTION("Wrong Record Mode!");
        }
    } else if (field == "STD_STRING_MODE") {
        if (value == "Fix") {
            this->studentStringMode = value;
        } else if (value == "Dyn") {
            this->studentStringMode = value;
        } else {
            throw CONFIG_EXCEPTION("Wrong String Mode!");
        }
    } else if (field == "STD_RECORD_SIZE") {
        if (this->studentRecordMode == "Dyn") {
            this->studentRecordSize = -1;
        } else {
            try {
                this->studentRecordSize = stoi(value);
                if (this->studentRecordSize < 0) {
                    throw CONFIG_EXCEPTION("Record Size Is Not Valid!\nTry A Positive Number");
                }
            } catch (exception &err) {
                throw CONFIG_EXCEPTION("Record Size Is Not Valid!");
            }
        }
    } else if (field == "STD_NAME_SIZE") {
        if (this->studentStringMode == "Dyn") {
            this->studentNameSize = -1;
        } else {
            try {
                this->studentNameSize = stoi(value);
                if (this->studentNameSize < 0) {
                    throw CONFIG_EXCEPTION("Student Name Size Is Not Valid!\nTry A Positive Number");
                }
            } catch (exception &err) {
                throw CONFIG_EXCEPTION("Student Name Size Is Not Valid!");
            }
        }
    } else if (field == "STD_LAST_NAME_SIZE") {
        if (this->studentStringMode == "Dyn") {
            this->studentLastNameSize = -1;
        } else {
            try {
                this->studentLastNameSize = stoi(value);
                if (this->studentLastNameSize < 0) {
                    throw CONFIG_EXCEPTION("Student Last Name Size Is Not Valid!\nTry A Positive Number");
                }
            } catch (exception &err) {
                throw CONFIG_EXCEPTION("Student Last Name Size Is Not Valid!");
            }
        }
    } else if (field == "BOOK_RECORD_MODE") {
        if (value == "Fix") {
            this->bookRecordMode = value;
        } else if (value == "Dyn") {
            this->bookRecordMode = value;
        } else {
            throw CONFIG_EXCEPTION("Wrong Record Mode!");
        }
    } else if (field == "BOOK_STRING_MODE") {
        if (value == "Fix") {
            this->bookStringMode = value;
        } else if (value == "Dyn") {
            this->bookStringMode = value;
        } else {
            throw CONFIG_EXCEPTION("Wrong String Mode!");
        }
    } else if (field == "BOOK_RECORD_SIZE") {
        if (this->bookRecordMode == "Dyn") {
            this->bookRecordSize = -1;
        } else {
            try {
                this->bookRecordSize = stoi(value);
                if (this->bookRecordSize < 0) {
                    throw CONFIG_EXCEPTION("Record Size Is Not Valid!\nTry A Positive Number");
                }
            } catch (exception &err) {
                throw CONFIG_EXCEPTION("Record Size Is Not Valid!");
            }
        }
    } else if (field == "BOOK_NAME_SIZE") {
        if (this->bookStringMode == "Dyn") {
            this->bookNameSize = -1;
        } else {
            try {
                this->bookNameSize = stoi(value);
                if (this->bookNameSize < 0) {
                    throw CONFIG_EXCEPTION("Book Name Size Is Not Valid!\nTry A Positive Number");
                }
            } catch (exception &err) {
                throw CONFIG_EXCEPTION("Book Name Size Is Not Valid!");
            }
        }
    } else if (field == "BOOK_AUTHOR_SIZE") {
        if (this->bookStringMode == "Dyn") {
            this->bookAuthorSize = -1;
        } else {
            try {
                this->bookAuthorSize = stoi(value);
                if (this->bookAuthorSize < 0) {
                    throw CONFIG_EXCEPTION("Book Author Size Is Not Valid!\nTry A Positive Number");
                }
            } catch (exception &err) {
                throw CONFIG_EXCEPTION("Book Author Size Is Not Valid!");
            }
        }
    } else if (field == "BOOK_PUBLISHER_SIZE") {
        if (this->bookStringMode == "Dyn") {
            this->bookPublisherSize = -1;
        } else {
            try {
                this->bookPublisherSize = stoi(value);
                if (this->bookPublisherSize < 0) {
                    throw CONFIG_EXCEPTION("Book Publisher Size Is Not Valid!\nTry A Positive Number");
                }
            } catch (exception &err) {
                throw CONFIG_EXCEPTION("Book Publisher Size Is Not Valid!");
            }
        }
    } else if (field == "LIB_REC_RECORD_MODE") {
        if (value == "Fix") {
            this->libRecRecordMode = value;
        } else if (value == "Dyn") {
            this->libRecRecordMode = value;
        } else {
            throw CONFIG_EXCEPTION("Wrong Record Mode!");
        }
    } else if (field == "LIB_REC_STRING_MODE") {
        if (value == "Fix") {
            this->libRecStringMode = value;
        } else if (value == "Dyn") {
            this->libRecStringMode = value;
        } else {
            throw CONFIG_EXCEPTION("Wrong String Mode!");
        }
    } else if (field == "LIB_REC_RECORD_SIZE") {
        if (this->libRecRecordMode == "Dyn") {
            this->libRecRecordSize = -1;
        } else {
            try {
                this->libRecRecordSize = stoi(value);
                if (this->libRecRecordSize < 0) {
                    throw CONFIG_EXCEPTION("Record Size Is Not Valid!\nTry A Positive Number");
                }
            } catch (exception &err) {
                throw CONFIG_EXCEPTION("Record Size Is Not Valid!");
            }
        }
    } else {
        cout << "WRONG CONFIGURATION KEY!" << endl;
    }
}

vector<string> Config::tokenize(string line) {
    string delimiter = " = ";
    vector<string> v1;

    int pos = 0;
    string token;
    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        v1.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    v1.push_back(line);

    return v1;
}

void Config::checkConfigValidation() {
    unsigned int totalSize = 0;

    if (this->studentRecordMode == "Fix" && this->studentStringMode == "Fix"){
        totalSize = (sizeof(int) * 3) + this->studentNameSize + this->studentLastNameSize;
        if (totalSize > this->studentRecordSize) {
            throw CONFIG_EXCEPTION("Student Record Size Is Too Small!");
        }
    }
    if (this->bookRecordMode == "Fix" && this->bookStringMode == "Fix"){
        totalSize = sizeof(long long) + (sizeof(int) * 4) + this->bookNameSize + this->bookAuthorSize + this->bookPublisherSize;
        if (totalSize > this->bookRecordSize) {
            throw CONFIG_EXCEPTION("Book Record Size Is Too Small!");
        }
    }
}
