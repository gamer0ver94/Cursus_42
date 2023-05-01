#include "srcs/iter.cpp"
#include <iostream>

void multiplyByTwo(int &x){
	x = 0;
}

int main(void){
	int test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	::iter(test, 10, &multiplyByTwo);
	for (int i = 0; i < 10; i++){
		std::cout << test[i] << std::endl;
	}
	return 0;
}