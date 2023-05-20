#include "classes/Span.hpp"
#include <cstdlib>
#include <ctime>
#define MAX_SPAN 10000

int main(void){
Span sp = Span(MAX_SPAN);
std::srand(std::time(NULL));
int random;

for(int i = 0; i < MAX_SPAN; i++){
    random = rand() % 100000000;
    sp.addNumber(random);
}
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
    return 0;
}