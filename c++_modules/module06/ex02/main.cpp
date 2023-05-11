#include "classes/A.hpp"
#include "classes/B.hpp"
#include "classes/C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

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

void identify(Base *p){
    if (dynamic_cast<A*>(p)){
        std::cout << "I am an objective of Type A class." << std::endl;
    }
    else if(dynamic_cast<B*>(p)){
        std::cout << "I am an objective of Type B class." << std::endl; 
    }
    else if (dynamic_cast<C*>(p)){
         std::cout << "I am an objective of Type C class." << std::endl;
    }
    else{
        std::cout << "I dont know what am i." << std::endl;
    }
}

void identify(Base &p){
    try{
        A &base = dynamic_cast<A&>(p);
        std::cout << "I am an objet of Type A. " << &base << std::endl;
    }
    catch(std::bad_cast &){
    }
     try{
        B &base = dynamic_cast<B&>(p);
        std::cout << "I am an objet of Type B. " << &base << std::endl;
    }
    catch(std::bad_cast &){
    }
     try{
        C &base = dynamic_cast<C&>(p);
        std::cout << "I am an objet of Type C. " << &base << std::endl;
    }
    catch(std::bad_cast &){
    }
}

int main(void){
    Base *base = generate();
    identify(*base);
    identify(base);
    return 0;
}