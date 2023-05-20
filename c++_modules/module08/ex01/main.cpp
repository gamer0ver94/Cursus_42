#include "classes/Span.hpp"
#include <cstdlib>
#include <ctime>
#define MAX_SPAN 100000

int main(void){
Span sp = Span(MAX_SPAN);
std::srand(std::time(NULL));
int random;

for(int i = 0; i < MAX_SPAN; i++){
    random = rand() % 100000000;
    sp.addNumber(random);
}
std::cout << "shortest span " << sp.shortestSpan() << std::endl;
std::cout << "longes spam " << sp.longestSpan() << std::endl;
    return 0;
}

// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }