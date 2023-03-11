#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain{
    private :
        std::string ideias[100];

    public :
        Brain();
        ~Brain();
        Brain(const Brain& copy);
        Brain& operator=(const Brain& copy);

    std::string getIdeia(int index);
    void    setIdeia(int index, std::string ideia);
};

#endif