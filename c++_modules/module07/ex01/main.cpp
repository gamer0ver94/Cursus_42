#include "generic/iter.hpp"
#include <iostream>

void print(const int &x){
	std::cout << x << std::endl;
}

void multiplyByTwo(int &x){
	x *= 2;
}

int main(void){
	int test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	::iter(test, 10, &multiplyByTwo);
	::iter(test, 10, &print);
	return 0;
}