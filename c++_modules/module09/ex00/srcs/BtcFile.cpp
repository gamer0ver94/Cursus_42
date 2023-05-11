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
         while (std::getline(externalDataBase, line)) {
            std::istringstream iss(line);
            std::getline(iss, key, '|');
            std::getline(iss, value);
            std::cout << "key" << key << "value" << value << std::endl;
            try{
                db2[key] = std::stof(value);
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
    // for (std::map<std::string, float>::iterator it = db.begin();it != db.end(); ++it){
    //     std::cout << std::fixed << std::setprecision(2) << it->second << std::endl;
    //     // std::cout << it->second << std::endl;
    // }
    // for (std::map<std::string, float>::iterator it = db2.begin();it != db2.end(); ++it){
    //     std::cout  << it->second << std::endl;
    // std::cout << db2["2011-01-03"] << std::endl;
    // }
    
}
