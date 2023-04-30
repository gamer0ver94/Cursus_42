#include "classes/A.hpp"
#include "classes/B.hpp"
#include "classes/C.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void){
    std::srand(std::time(NULL));
    int random = std::rand() % 3;
    switch(random){
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        break;
    }
    return NULL;
}

int main(void){

    return 0;
}