#include "list_filler.h"

void lab0::ListFiller::addToList(const std::map<std::string, int>& mp) {

    for (auto & it : mp) {
        std::pair<std::string, int> node;
        node.first = it.first;
        node.second = it.second;

        words_.push_back(node);
    }

    Comparator ListComp;
    words_.sort(ListComp);
}

std::list<std::pair<std::string, int>> lab0::ListFiller::getSortList() {

    return words_;
}

bool lab0::ListFiller::Comparator::operator()(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {

    return a.second > b.second;
}