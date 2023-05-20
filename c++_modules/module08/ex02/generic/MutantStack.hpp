#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>

template<class	 T, class Container = std::deque<T> > 
class MutantStack : public std::stack< T, Container >
{
	public:
    	MutantStack() {};
    	~MutantStack() {};
    	MutantStack( const MutantStack& copy ){
			*this = copy;
		}
    	MutantStack&    operator=( const MutantStack& copy ) {
    	    std::stack< T, Container >::operator=(copy);
    	    return *this;
    	}
    	typedef typename Container::iterator    iterator;
    	iterator    begin(){
			return this->c.begin();
		}
    	iterator    end(){
			return this->c.end();
		}
};