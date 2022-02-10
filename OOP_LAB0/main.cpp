#include <iostream>
#include "list_filler.h"
#include "word_writer.h"
#include "word_find.h"

int main(int argc, char* argv[]) {

    try{
        if (argc < 3) {
            throw std::runtime_error("Not enough args in main");
        }

        lab0::WordFind findInMyFile(argv[1]);
        findInMyFile.readMyFile();

        lab0::ListFiller addToMyList;
        addToMyList.addToList(findInMyFile.getMap());

        lab0::WordWriter writeOut(argv[2]);
        writeOut.writeFile(addToMyList.getSortList(), findInMyFile.getCount());

    }
    catch(std::runtime_error& err){
        std::cout << err.what() << std::endl;
    }


    return 0;
}
