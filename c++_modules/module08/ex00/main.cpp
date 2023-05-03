#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    return it;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> lst = {10, 20, 30, 40, 50};

    try {
        std::vector<int>::iterator it_vec = easyfind(vec, 3);
        std::cout << "Value found in vector at index " << it_vec - vec.begin() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it_lst = easyfind(lst, 50);
        std::cout << "Value found in list at position " << std::distance(lst.begin(), it_lst) << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
