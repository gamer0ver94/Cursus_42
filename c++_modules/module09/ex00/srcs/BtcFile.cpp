#include "../classes/BtcFile.hpp"
#include <string>
#include <sstream>
#include <iomanip>
BtcFile::BtcFile(const char *fileName, const char *fileName2){
    std::string value;
    std::string key;
    std::string line;
    internalDataBase.open(fileName);
    externalDataBase.open(fileName2);
	std::getline(internalDataBase, line);
    if (!internalDataBase || !externalDataBase){
        std::cout << "failed to open file" << std::endl;
    }
    else{
        while (std::getline(internalDataBase, line)) {
            std::istringstream iss(line);
            std::getline(iss, key, ',');
            std::getline(iss, value);
            try{
                db[key] = std::stof(value);
            }
            catch(...){std::cout << "error" << value << std::endl;};
        }
        std::cout << "File Constructor" << std::endl;
    }
}
BtcFile::~BtcFile(){
    internalDataBase.close();
    externalDataBase.close();
};

void BtcFile::outputFile(){
	std::string line;
	std::string key;
	std::string value;
    while (std::getline(externalDataBase, line)) {
        std::istringstream iss(line);
        std::getline(iss, key, '|');
        std::getline(iss, value);
		key[key.size() - 1] = '\0';
        try{
			if (db[key]){
           		std::cout << key << " => " << value << " = " << std::endl;
			}
			else{
				std::cout << "Error: bad input => " << key << std::endl;
			}
        }
        catch(...){std::cout << "error" << value << std::endl;};
    }
    
}
