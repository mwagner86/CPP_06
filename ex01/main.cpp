/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:26:51 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/13 16:27:22 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	Data OriginalStruct;
	uintptr_t rawData;

	OriginalStruct.string = "Hello World!";
	OriginalStruct.c = 'a';
	OriginalStruct.i = 42;
	OriginalStruct.f = 42.042f;
	OriginalStruct.d = 13.37;

	std::cout << "Original Struct values:" << std::endl;
	std::cout << COLOR_CYAN << "string : " << COLOR_DEFAULT << OriginalStruct.string  << std::endl;
	std::cout << COLOR_YELLOW << "char   : " << COLOR_DEFAULT << OriginalStruct.c  << std::endl;
	std::cout << COLOR_BLUE << "int    : " << COLOR_DEFAULT << OriginalStruct.i  << std::endl;
	std::cout << COLOR_MAGENTA << "float  : " << COLOR_DEFAULT << OriginalStruct.f  << std::endl;
	std::cout << COLOR_PURPLE "double : "  << COLOR_DEFAULT << OriginalStruct.d << std::endl;
	std::cout << COLOR_GREEN << "Pointer Address before serialization: " << &OriginalStruct << COLOR_DEFAULT << std::endl;

	std::cout << DARKBLUE << "* Function call to serialize the Pointer Address of DataStruct *" << COLOR_DEFAULT << std::endl;
	rawData = Serializer::serialize(&OriginalStruct);
	std::cout << "Value of rawData after serialization: " << rawData << std::endl; // Display the rawData value


	std::cout << LIGHTBLUE << "* Function call to deserialize the rawData *" << COLOR_DEFAULT << std::endl;
	Data* NewStruct = Serializer::deserialize(rawData);
	std::cout << COLOR_RED << "Pointer Address after deserialization: " << NewStruct << COLOR_DEFAULT << std::endl;
	std::cout << "New Struct values:" << std::endl;
	std::cout << COLOR_CYAN << "string : "  << COLOR_DEFAULT << NewStruct->string << std::endl;
	std::cout << COLOR_YELLOW << "char   : " << COLOR_DEFAULT << NewStruct->c  << std::endl;
	std::cout << COLOR_BLUE << "int    : " << COLOR_DEFAULT << NewStruct->i << std::endl;
	std::cout << COLOR_MAGENTA << "float  : " << COLOR_DEFAULT << NewStruct->f << std::endl;
	std::cout << COLOR_PURPLE << "double : " << COLOR_DEFAULT << NewStruct->d << std::endl;

	return 0;
}
