#include "Harl.hpp"

int main(int argc, char **argv){
    Harl harl;

    if (argc < 2){
        std::cout << "Please enter one or more [COMPLAIN LEVEL(s)] for Harl to say ..." << std::endl;
        return (1);
    }
    while (*argv){
        harl.complain(*argv);
        argv++;
    }
    return (0);
}