#pragma once
#include <iostream>
template <typename T>
class Array{
    private :
        T *array;
        unsigned int _size;
    public :
        Array() : array(NULL), _size(0){
        }
        Array(unsigned int n) : array(new T[n]), _size(n){
            for (int i = 0; i < n; i++){

                array[i] = T();
            }
        }
        virtual ~Array(){
        }

        Array(const Array &copy) : array(new T[copy._size]), _size(copy._size){
            for(int i = 0; i < copy._size; i++){
                this->array[i] = copy.array[i];
            }
        }

        Array& operator=(const Array &copy){
            if (this != &copy){
                delete[] array;
                array = new T[copy._size];
                for(int i = 0; i < copy._size; i++){
                    this->array[i] = copy->array[i];
                }
                this->_size = copy._size;
            }
            return *this;
        }
        T& operator[](size_t index){
            if (index >= _size || index < 0){
                throw std::out_of_range("Index out of range");
            }
            return array[index];
        }
        size_t size(void)const{
            return _size;
        } 
};