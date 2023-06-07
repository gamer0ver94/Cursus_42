#include "../classes/BitcoinExchange.hpp"
#include <sstream>
#include <iomanip>
#include <iterator>
#include <map>
#include <cstdlib>
#include <cfloat>
#include <ctime>

// Constructor takes the databasefile and input file and save db data in a map
BitcoinExchange::BitcoinExchange(const char *fileName, const char *fileName2){
    std::string value;
    std::string key;
    std::string line;
    internalDataBase.open(fileName);
    externalDataBase.open(fileName2);
	std::getline(internalDataBase, line);
    if (!internalDataBase || !externalDataBase){
        std::cout << RED << "failed to open file" << RESET <<std::endl;
    }
    else{
        while (std::getline(internalDataBase, line)) {
            std::istringstream iss(line);
            std::getline(iss, key, ',');
            std::getline(iss, value);
            try{
                db[key] = std::atof(value.c_str());
            }
            catch(std::exception &e){
				std::cout << RED << "error : " << value << RESET <<std::endl;
				std::cout << e.what() << std::endl;
			};
        }
    }
}

// Destructor closes files
BitcoinExchange::~BitcoinExchange(){
    internalDataBase.close();
    externalDataBase.close();
};

 BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy){
	if (this != &copy){
		for(std::map<std::string, float>::const_iterator it = copy.db.begin(); it != copy.db.end(); ++it){
			db.insert(*it);
		}
	}
 }

 BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy){
	if (this != &copy){
		db = copy.db;
	}
	return *this;
 }

// output new information
void BitcoinExchange::outputFile(){
	std::string line;
	std::string key;
	std::string value;
	bool formatCheck = false;
    while (std::getline(externalDataBase, line)) {
        std::istringstream iss(line);
        std::getline(iss, key, '|');
        std::getline(iss, value);
		char *tmpStr = new char[key.size() + 1];
		for (int i = 0; i < static_cast<int>(key.size()); i++){
			tmpStr[i] = key[i];
		}
		tmpStr[key.size()] = '\0';
        if (std::atof(value.c_str()) > 1000){
            std::cout << RED << "Error: too large a number" << RESET << std::endl;
            break;
        }
        try{
			// if (!formatCheck && value != " value" && key != "date "){
			// 	std::cerr << YELLOW << "Input File first line does not cointain the format or the right one ..." << RESET << std::endl;
			// 	return;
			// }
			if (!formatCheck && value == " value" && key == "date "){
				formatCheck = true;
				continue;
			}
            std::map<std::string, float>::iterator it;
			for (it = db.begin(); it != db.end(); ++it){
                if (!isValidLineFormat(line) || !isValidDateFormat(key)  || !isNumber(value)){
                    if (!line.empty()){
                        std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
                    }
                    break;
                }
				if (it->first == tmpStr){
                    if (std::atof(value.c_str()) * it->second < 0){
						std::cout << RED << "Error: not a positive number." << RESET << std::endl;
					}
					else if (std::atof(value.c_str()) > FLT_MAX){
						std::cout << RED << "Error: too large." << RESET << std::endl;
					}
					else{
						std::cout << it->first << " => " << it->second << " = " << (std::atof(value.c_str()) * it->second) << std::endl;
					}
					break;
				}
			}
            if (isValidDateFormat(tmpStr) && it == db.end())
            {
                std::map<std::string, float>::const_iterator iter = getClosestDate(db, tmpStr);
                if (iter->first.empty()){
                    std::cout << RED << "Error : There is no closest date in db before date in input => " << tmpStr <<  RESET << std::endl;
                }
                else{
                    std::cout << iter->first << " => " << iter->second << " = " << (std::atof(value.c_str()) * iter->second) << std::endl;
                }

            }
        }
        catch(...){
            std::cout << RED << "Error : exception found" << value << RESET <<std::endl;
        }
		delete[] tmpStr;
    }
}

bool BitcoinExchange::isValidDateFormat(std::string date){
 std::istringstream ss(date);
    std::string yearStr, monthStr, dayStr;

    if (!(std::getline(ss, yearStr, '-') &&
          std::getline(ss, monthStr, '-') &&
          std::getline(ss, dayStr)))
        return false;

    int year, month, day;
    std::istringstream(yearStr) >> year;
    std::istringstream(monthStr) >> month;
    std::istringstream(dayStr) >> day;

    if (ss.fail() ||
        yearStr.empty() || monthStr.empty() || dayStr.empty() ||
        year <= 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

std::map<std::string, float>::const_iterator BitcoinExchange::getClosestDate(const std::map<std::string, float>& datesMap, const std::string& inputDate) {
    std::tm timeinfo = {};
    std::istringstream iss(inputDate);
    int year, month, day;
    char dash1, dash2;
    iss >> year >> dash1 >> month >> dash2 >> day;
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    std::time_t inputDateTime = std::mktime(&timeinfo);

    int minDifference = 999999999;
    std::map<std::string, float>::const_iterator closestDateIterator = datesMap.end();

    for (std::map<std::string, float>::const_iterator it = datesMap.begin(); it != datesMap.end(); ++it) {
        std::tm dateInfo = {};
        std::istringstream dateSS(it->first);
        dateSS >> year >> dash1 >> month >> dash2 >> day;
        dateInfo.tm_year = year - 1900;
        dateInfo.tm_mon = month - 1;
        dateInfo.tm_mday = day;
        std::time_t dateDateTime = std::mktime(&dateInfo);

        int difference = static_cast<int>(inputDateTime - dateDateTime);

        if (difference >= 0 && difference < minDifference) {
            minDifference = difference;
            closestDateIterator = it;
        }
    }
    return closestDateIterator;
}



bool BitcoinExchange::isValidLineFormat(const std::string& line) {
    size_t found = line.find(" | ");
    return found != std::string::npos;
}

bool BitcoinExchange::isNumber(const std::string str) {
    std::istringstream iss(str);
    double num;
    return (iss >> num) && (iss.eof());
}