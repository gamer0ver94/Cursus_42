#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T, typename N, typename F>
void iter(T *array, N length, void(*func)(F&)){
    for (N i = 0; i < length; i++){
        func(array[i]);
    }
}

#endif
