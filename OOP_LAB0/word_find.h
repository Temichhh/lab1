#ifndef CLAB0_WORD_FIND_H
#define CLAB0_WORD_FIND_H

#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <stdexcept>


namespace lab0 {

    class WordFind {
    private:
        std::ifstream fin_;
        std::map <std::string, int> mp_ ;
        long long count_;

        void breakIntoWord (std::string fileLine);

    public:
        explicit WordFind(const std::string&);

        void readMyFile ();

        long long getCount () const;
        const std::map<std::string, int>& getMap() const;
    };
}

#endif //CLAB0_WORD_FIND_H
