#include "../classes/Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr){
	std::cout << "\033[33m" << "Serializing ..." << "\033[37m" << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
	std::cout << "\033[33m" << "Deserializing ..." << "\033[37m" << std::endl;
	return reinterpret_cast<Data*>(raw);
}