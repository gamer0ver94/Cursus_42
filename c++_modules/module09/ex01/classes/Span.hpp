#include <iostream>
#include <vector>
class Span{
    private :
        unsigned int max;
        std::vector<int> array;
    public :
        Span(unsigned int max);
        void addNumber(int value);
        int shortestSpan(void);
        int longestSpan(void);
};