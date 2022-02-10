#include "word_find.h"


lab0::WordFind::WordFind(const std::string &fileName): fin_(fileName), count_(0) {}

void lab0::WordFind::readMyFile() {

    if (!fin_.is_open()){
        throw std::runtime_error("File is not open");
    }

    while (!fin_.eof()) {
        std::string s;
        getline(fin_, s);

        std::transform(s.begin(), s.end(), s.begin(), tolower);

        breakIntoWord(s);
    }

    fin_.close();
}

void lab0::WordFind::breakIntoWord(std::string fileLine) {

    std::regex expression ("([a-zA-Z0-9]{1,})");

    std::sregex_iterator first(fileLine.begin(), fileLine.end(), expression);
    std::sregex_iterator last;

    count_ += distance(first, last);

    for (auto i = first; i != last; i++) {
        std::smatch wordNow = *i;
        std::string wordInStr = wordNow.str();

        mp_[wordInStr] += 1;
    }
}


const std::map<std::string, int> &lab0::WordFind::getMap() const {
    return mp_;
}


long long lab0::WordFind::getCount() const {
    return count_;
}

