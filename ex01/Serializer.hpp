//
// Created by max on 7/13/23.
//

#ifndef EX01_SERIALIZER_HPP
#define EX01_SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"
#include "colors.hpp"

class Serializer {

public:
	Serializer();
	Serializer(const Serializer & src);
	Serializer & operator=(const Serializer & rhs);
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif //EX01_SERIALIZER_HPP
