#include <iostream>

int main(void){
    std::string stringVar;
    std::string *stringPtr;

    stringVar = "HI THIS IS BRAIN";
    stringPtr = &stringVar;
    std::string &stringRef = stringVar;
    std::cout << &stringVar << std::endl;
    std::cout << stringPtr << std::endl;
    std::cout << &stringRef << std::endl;

    std::cout << stringVar << std::endl;
    std::cout << *stringPtr << std::endl;
    std::cout << stringRef << std::endl;
    return (0);
}