#include <iostream>
#include <vector>
class Span{
    private :
        unsigned int max;
        std::vector<int> array;
    public :
        Span(unsigned int max);
        void addNumber(int value);
        void addNumber(const std::vector<int>& numbers);
        int shortestSpan(void);
        int longestSpan(void);
};