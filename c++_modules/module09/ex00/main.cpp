#include <iostream>
#include "classes/BtcFile.hpp"


int main(int argc, char **argv) {
    if (argv[1] && argc == 2){
        BtcFile *file = new BtcFile("data.csv", argv[1]);
        file->outputFile();
        delete file;
    }
    else{
        std::cout << "no file" << std::endl;
    }
    return 0;
}
