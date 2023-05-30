#include <iostream>
#include "classes/BitcoinExchange.hpp"


int main(int argc, char **argv) {
    if (argv[1] && argc == 2){
        try{
            BitcoinExchange *file = new BitcoinExchange("data.csv", argv[1]);
            file->outputFile();
            delete file;
        }
        catch(std::exception &e){
            std::cout << RED << "unexpected error: " << CYAN << e.what() << RESET << std::endl;
        };
        
    }
    else{
        std::cout << "no file" << std::endl;
    }
    return 0;
}
