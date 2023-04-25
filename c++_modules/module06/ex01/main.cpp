#include "classes/Serializer.hpp"
#include <iostream>
int main(void){
	Data data;
	data.value = 2;
	Data *la;
	Serializer test;
	uintptr_t value = test.serialize(&data);
	std::cout << value << std::endl;
	la = test.deserialize(value);
}