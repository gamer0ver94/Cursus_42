#pragma once
#include <iostream>
#include <fstream>
#include <map>
class BtcFile{
    public :
       BtcFile(const char* fileName, const char *fileName2);
       ~BtcFile();
       void outputFile();

    private :
        std::ifstream internalDataBase;
        std::ifstream externalDataBase;
        std::map<std::string, float> db;
        std::map<std::string, int> db2;
};