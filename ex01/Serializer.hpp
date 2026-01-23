#pragma once

#include <iostream>
#include <stdint.h>


struct Data;

class Serializer{
private:
	Serializer();
	Serializer(const Serializer& src);
	Serializer &operator=(const Serializer &src);
	virtual ~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};