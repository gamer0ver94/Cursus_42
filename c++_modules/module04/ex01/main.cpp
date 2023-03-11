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
	Cat *cat = new Cat();
	cat->getBrain()->setIdeia(0, "I am cat");
	std::cout << cat->getBrain()->getIdeia(0) << std::endl;
	Cat *cat2 = new Cat(*cat);

	std::cout << cat->getBrain() << std::endl;
	std::cout << cat2->getBrain() << std::endl;
	delete cat2;
	delete cat;
	return 0;
}