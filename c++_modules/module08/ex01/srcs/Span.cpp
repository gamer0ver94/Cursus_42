#include "../classes/Span.hpp"

Span::Span(unsigned int max) : max(max){
    array.reserve(max);
}

void Span::addNumber(int value){
    if(array.size() == max){
        throw std::runtime_error("Reached already max size of container");
    }
    else{
        std::vector<int>::iterator it = std::lower_bound(array.begin(),array.end(), value);
        array.insert(it, value);    
    }
}

void Span::addNumber(const std::vector<int>& numbers){
    if (numbers.size() + array.size() > max){
        throw std::overflow_error("Reached already max size of container");
    }
    array.insert(array.end(), numbers.begin(), numbers.end());
}

int Span::shortestSpan(void){
    int shortest;
    if(array.size() < 2){
        throw std::runtime_error("error");
    }
   else{
        shortest = array[1] - array[0];
        for (size_t i = 1; i < array.size(); i++){
            if (i + 1 < array.size() && array[i + 1] - array[i] < shortest && array[i + 1] != array[i]){
                shortest = array[i + 1] - array[i];
            }
        }
    }
    return shortest;
}

int Span::longestSpan(void){
    if(array.size() < 2){
        throw std::runtime_error("error");
    }
    return array[array.size() - 1] - array[0];
}