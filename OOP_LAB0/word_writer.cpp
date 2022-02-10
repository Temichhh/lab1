#include "word_writer.h"

lab0::WordWriter::WordWriter(const std::string& file_name_): fout_(file_name_){}


void lab0::WordWriter::writeFile(const std::list<std::pair<std::string, int>>& word, long long count) {

    for(auto & it : word) {
        double perc = percOfWords(count, it.second);

        fout_ << it.first << ";" << it.second << ";" << round((perc * 10))/10.0 << "%" << std::endl;
    }
}

double lab0::WordWriter::percOfWords(const long long int count, int my_count) {

    return (double)(my_count * 100) * 1.0 / (double)count;
}