#include "../classes/BtcFile.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <map>
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
		char *test = new char[key.size() - 1];
		for (int i = 0; i < static_cast<int>(key.size() - 1); i++){
			test[i] = key[i];
		}
		test[key.size() - 1] = 0;
        try{
			for (std::map<std::string, float>::iterator it = db.begin(); it != db.end(); ++it){
				if (it->first == test){
					if (std::stof(value) * it->second < 0){
						std::cout << "Error: not a positive number" << std::endl;
					}
					else if (std::stof(value) > MAXFLOAT){
						std::cout << "Error: too large" << std::endl;
					}
					else{
						std::cout << it->first << " => " << it->second << " = " << (std::stof(value) * it->second) << std::endl;
					}
					break;
				}
			}

        }
        catch(...){std::cout << "another error" << value << std::endl;};
		delete[] test;
    }
}
