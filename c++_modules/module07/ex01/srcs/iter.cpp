#include "../generic/iter.hpp"

template<typename T, typename N>
void iter(T *array, N lenght, void(*func)(T&)){
	for (N i = 0; i < lenght; i++){
		func(array[i]);
	}
}