#include <iostream>
#include <stack>

template <typename T>
class MutantStack{
	private :
		int arraySize;
		std::stack<T> array;
	public :
		void push(T value){
			array.push(value);
		}
		void pop(){
			array.pop();
		}
		T top(){
			return array.top();
		}
		T begin(){
			return array.begin();
		}
		T end(){
			return array.end();
		}
		T size(){
			return array.size();
		}
};