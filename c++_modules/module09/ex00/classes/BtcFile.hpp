#pragma once
#include <fstream>
#include <iostream>
#include <string>
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
        std::map<std::string, float>::const_iterator getClosestDate(const std::map<std::string, float>& datesMap, const std::string& inputDate);
        bool isValidDateFormat(std::string date);
        bool isValidLineFormat(const std::string& line);
        void trim(std::string& str);
        bool isNumber(std::string);
};