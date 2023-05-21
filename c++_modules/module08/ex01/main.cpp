#include "classes/Span.hpp"
#include <cstdlib>
#include <ctime>
#define MAX_SPAN 100000

int main(void){
    Span sp = Span(MAX_SPAN);
    std::srand(std::time(NULL));
    int random;
    try{
        for(int i = 0; i < MAX_SPAN; i++){
        random = std::rand() % 100000000;
        sp.addNumber(random);
        }
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(std::exception &e){
        std::cout << "error: " << e.what() << std::endl;
    };
    
    
    std::cout << "_______________________" << std::endl;
    Span spTmp = Span(10000000);
    std::vector<int> test;
    try{
        for(int i = 0; i < 10000000; i++){
        test.push_back(i);
        }
        spTmp.addNumber(test);
        std::cout << spTmp.shortestSpan() << std::endl;
        std::cout << spTmp.longestSpan() << std::endl;
    }
    catch(std::exception &e){
        std::cout << "error: " << e.what() << std::endl;
    }
    return 0;
}