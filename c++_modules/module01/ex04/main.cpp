#include <iostream>
#include <fstream>
#define WHITE "\033[0;37m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"

int main(int argc ,char **argv){

    std::ifstream inFile;
	std::ofstream outFile;
    std::string line;
	std::size_t found;
	std::string fileToBeCreated;
	int i = 0;
	found = 0;
    if (argc < 4){
        std::cout << RED << "Not enought args to run the program ..." << WHITE << std::endl;
        return (-1);
    }
	std::string add = argv[3];
	std::string del = argv[2];
	fileToBeCreated.append(argv[1]).append(".replace");
    inFile.open(argv[1]);
	outFile.open(fileToBeCreated);
    if (!inFile.good()){
        std::cout << RED << "File does not exist ..." << std::endl;
		inFile.close();
		outFile.close();
        return (-1);
    }
    if (inFile.is_open())
     std::cout << GREEN << "File open with sucess..." << WHITE << std::endl;
	while (!inFile.eof()) {
   		getline(inFile, line);
		found = line.find(argv[2]); 
		if (found != std::string::npos)
		{
			line.erase(found, del.length());
			line.insert(found, add);
			i++;
		}
		outFile << line << std::endl;
	}
	if (i > 0){
		std::cout << CYAN << i << " word(s)replaced by " << argv[3] << WHITE << std::endl;
	}
    inFile.close();
	outFile.close();
	std::cout << GREEN << "File closed with success" << WHITE << std::endl;
    return (0);
}