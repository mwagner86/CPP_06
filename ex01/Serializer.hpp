/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:27:42 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/13 16:27:48 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
