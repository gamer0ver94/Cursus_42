#include <iostream>
#include <fstream>

int main(int argc ,char **argv){

    std::ifstream inFile;
    std::string line;

    if (argc < 4){
        std::cout << "No args" << std::endl;
        return (-1);
    }
    inFile.open(argv[1]);
    if (!inFile.good()){
        std::cout << "Error no file" << std::endl;
        return (-1);
    }
    if (inFile.is_open())
     std::cout << "its open" << std::endl;
    getline(inFile, line);
while (!inFile.eof()) {
    std::cout << line << std::endl;
    getline(inFile, line);
}
    inFile.close();
    std::cout << line << std::endl;
    return (0);
}