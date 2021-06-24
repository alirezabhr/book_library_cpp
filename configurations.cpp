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

    return config;
}

CONFIG_EXCEPTION::CONFIG_EXCEPTION(const string &msg) : msg(msg) {}

const string &CONFIG_EXCEPTION::getMsg() const {
    return msg;
}

Config::Config() {
    recordSize = 0;
    studentNameSize = 0;
    studentLastNameSize = 0;
}

const string &Config::getRecordMode() const {
    return recordMode;
}

const string &Config::getStringMode() const {
    return stringMode;
}

int Config::getRecordSize() const {
    return recordSize;
}

int Config::getStudentNameSize() const {
    return studentNameSize;
}

int Config::getStudentLastNameSize() const {
    return studentLastNameSize;
}

void Config::setFields(const std::string& field, const std::string& value) {
    if (field == "RECORD_MODE") {
        if (value == "Fix") {
            this->recordMode = value;
        } else if (value == "Dyn") {
            this->recordMode = value;
        } else {
            throw CONFIG_EXCEPTION("Wrong Record Mode!");
        }
    } else if (field == "STRING_MODE") {
        if (value == "Fix") {
            this->stringMode = value;
        } else if (value == "Dyn") {
            this->stringMode = value;
        } else {
            throw CONFIG_EXCEPTION("Wrong String Mode!");
        }
    } else if (field == "RECORD_SIZE") {
        if (this->recordMode == "Dyn") {
            this->recordSize = -1;
        } else {
            try {
                this->recordSize = stoi(value);
                if (this->recordSize < 0) {
                    throw CONFIG_EXCEPTION("Record Size Is Not Valid!\nTry A Positive Number");
                }
            } catch (exception &err) {
                throw CONFIG_EXCEPTION("Record Size Is Not Valid!");
            }
        }
    } else if (field == "STD_NAME_SIZE") {
        if (this->stringMode == "Dyn") {
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
        if (this->stringMode == "Dyn") {
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