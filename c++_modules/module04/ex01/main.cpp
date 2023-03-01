#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void){
	Animal *animals[20];

	for (int i = 0; i < 20; i++){
		if (i < 10){
			animals[i] = new Dog();
		}
		else{
			animals[i] = new Cat();
		}
	}
	for (int i = 0; i < 20; i++){
		delete animals[i];
	}
	return 0;
}