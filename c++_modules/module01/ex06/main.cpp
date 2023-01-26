#include "Harl.hpp"

int main(int argc, char **argv){
    Harl harld;
    int i = 0;
    std::string level[4] = {
        "DEBUG", "INFO", "WARNING", "ERROR"
    };

    if (argc != 2){
        std::cout << "Please Enter one argument ..." << std::endl;
    }
    while (argv[1] != level[i] && i < 4)
        i++;
    if (i < 4){
        std::cout << "[ " << argv[1] << " ]" << std::endl;
    }
    switch (i){
        case 0:
            while (i < 4)
                harld.complain(level[i++]);
            break;
        case 1:
            while (i < 4)
                harld.complain(level[i++]);
            break;
        case 2:
            while (i < 4)
               harld.complain(level[i++]);
            break;
        case 3:
            while (i < 4)
                harld.complain(level[i++]);
            break;
        case 4:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}