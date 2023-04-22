#include "../classes/Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr){
	return static_cast<uintptr_t>(ptr->value);
}

Data* Serializer::deserialize(uintptr_t raw){
	
}