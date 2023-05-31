#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#define RESET   "\033[0m"   
#define RED     "\033[31m"
#define GREEN   "\033[32m"  
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m" 
#define WHITE   "\033[37m"

class BitcoinExchange{
    public :
      BitcoinExchange(const char* fileName, const char *fileName2);
      ~BitcoinExchange();
	   BitcoinExchange(const BitcoinExchange& copy);
	   BitcoinExchange& operator=(const BitcoinExchange& copy);
      void outputFile();
    private :
         BitcoinExchange();
         std::ifstream internalDataBase;
         std::ifstream externalDataBase;
         std::map<std::string, float> db;
         std::map<std::string, float>::const_iterator getClosestDate(const std::map<std::string, float>& datesMap, const std::string& inputDate);
         bool isValidDateFormat(std::string date);
         bool isValidLineFormat(const std::string& line);
         void trim(std::string& str);
         bool isNumber(std::string);
};