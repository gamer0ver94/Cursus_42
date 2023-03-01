#include "Brain.hpp"
#include "Animal.hpp"

//_________Brain Default Contructor________

Brain::Brain(){
    std::cout << GREEN << "Brain Default Constructor" << WHITE << std::endl;
}

//__________Brain Destructor____________

Brain::~Brain(){
    std::cout << RED << "Brain Destructor" << WHITE << std::endl;
}

//________________Brain Copy Constructor________

Brain::Brain(const Brain& copy){
    for (int i = 0; i < 100; i++){
        this->ideias[i] = copy.ideias[i];
    }
    std::cout << CYAN << "Brain copy Constructor" << WHITE << std::endl;
}

//_____________Brain assigment Operator_____________

Brain& Brain::operator=(const Brain& copy){
    for (int i = 0; i < 100; i++){
        this->ideias[i] = copy.ideias[i];
    }
    std::cout << CYAN << "Brain Assigment Operator" << WHITE << std::endl;
    return *this;
}