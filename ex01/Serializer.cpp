/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:27:33 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/13 16:27:37 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer() {
	if (VERBOSE)
		std::cout << "Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src) {
	if (VERBOSE)
		std::cout << "Copy constructor called" << std::endl;
	*this = src;
};

Serializer &	Serializer::operator=(Serializer const &rhs) {
	if (VERBOSE)
		std::cout << "Assignment operator overload called" << std::endl;
	if (this != &rhs)
		(void) rhs;
	return (*this);
};

Serializer::~Serializer() {
	if (VERBOSE)
		std::cout << "Destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
