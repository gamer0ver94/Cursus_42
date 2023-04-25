#include "../classes/Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr){
	return static_cast<uintptr_t>(ptr->value);
}

Data* Serializer::deserialize(uintptr_t raw){
	Data *Data;

	Data->value = static_cast<int>(raw);
	return Data;
}