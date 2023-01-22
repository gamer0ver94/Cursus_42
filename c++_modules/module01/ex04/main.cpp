#include <iostream>
#include <fstream>

int main(int argc ,char **argv){

    std::ifstream inFile;
	std::ofstream outFile;
    std::string line;
	std::size_t found;
	std::string add = argv[3];
	std::string del = argv[2];
	std::string fileToBeCreated;

	fileToBeCreated.append(argv[1]).append(".replace");
	found = 0;
    if (argc < 4){
        std::cout << "No args" << std::endl;
        return (-1);
    }
    inFile.open(argv[1]);
	outFile.open(fileToBeCreated);
    if (!inFile.good()){
        std::cout << "Error no file" << std::endl;
        return (-1);
    }
    if (inFile.is_open())
     std::cout << "its open" << std::endl;
	while (!inFile.eof()) {
   		getline(inFile, line);
		found = line.find(argv[2]); 
		if (found != std::string::npos)
		{
			line.erase(found, del.length());
			line.insert(found, add);
		}
		outFile << line << std::endl;
	}
    inFile.close();
	outFile.close();
    return (0);
}