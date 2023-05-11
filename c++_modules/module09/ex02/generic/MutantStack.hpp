#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
	public :
		MutantStack() : std::stack<T>(){
		}
		MutantStack(const MutantStack<T>& copy){
		}
		~MutantStack() {
		}
		MutantStack<T>& operator=(const MutantStack<T>& copy) {
			if (this != &copy) {
				this->array = copy.array;
			}
			return *this;
		}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(){
			return this->c.begin();
		}
		iterator end(){
			return this->c.end();
		}
};