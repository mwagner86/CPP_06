/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:24:02 by mwagner           #+#    #+#             */
/*   Updated: 2023/07/13 16:24:12 by mwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	if (VERBOSE)
		std::cout << "Default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	if (VERBOSE)
		std::cout << "Copy constructor called" << std::endl;
	*this = src;
};

ScalarConverter &	ScalarConverter::operator=(ScalarConverter const &rhs) {
	if (VERBOSE)
		std::cout << "Assignment operator overload called" << std::endl;
	if (this != &rhs) // NO relevant data members from rhs to this
		(void) rhs;
	return (*this);
};

ScalarConverter::~ScalarConverter() {
	if (VERBOSE)
		std::cout << "Destructor called" << std::endl;
}

void ScalarConverter::convert(const std::string & input)
{
	if (handlePseudoLiterals(input))
		return;

	if (isdigit(input[0]) || input.size() > 1)
	{
		char** ptr_end = new char*;
		double double_value = std::strtod(input.c_str(), ptr_end);
		float float_value = std::strtof(input.c_str(), ptr_end);
		if (**ptr_end && (strlen(*ptr_end) != 1 || **ptr_end != 'f'))
		{
			std::cout << "Error: Invalid input. Only type <char>, <int>, <float>, or <double>!" << std::endl;
			return;
		}
		handleDouble(double_value, float_value);
		delete ptr_end;
	}
	else
	{
		handleChar(input[0]);
	}
}

int ScalarConverter::handlePseudoLiterals(const std::string& input)
{
	int i;
	std::string pseudoArr[8] = {"inff", "+inff", "-inff", "nanf", "inf", "+inf", "-inf", "nan"};

	for (i = 0; i < 8; i++)
	{
		if (input == pseudoArr[i])
			break;
	}

	if (i < 8)
	{
		printChar("Non displayable");
		printInt("Non displayable");

		std::string toPrint;
		if (i < 4)
			toPrint = pseudoArr[i];
		else if (i == 7)
			toPrint = "nanf";
		else
			toPrint = "Undefined behavior";
		printFloat(toPrint);

		if (i >= 4)
			toPrint = pseudoArr[i];
		else if (i == 3)
			toPrint = "nan";
		else
			toPrint = "Undefined behavior";
		printDouble(toPrint);

		return 1;
	}

	return 0;
}

void ScalarConverter::handleChar(char c)
{
	if (isprint(c))
		printChar(std::string(1, c));
	else
		printChar("Non displayable");

	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::handleDouble(double double_value, float float_value)
{
	// (void) float_value;
	if (std::isnan(double_value) || std::isnan(float_value)) {
		printChar("Non displayable");
		printInt("Non displayable");
		printFloat("nanf");
		printDouble("nan");
		return;
	}

	if (std::isinf(double_value) || std::isinf(float_value)) {
		printChar("Non displayable");
		printInt("Non displayable");
		printFloat("infinite");
		printDouble("infinite");
		return;
	}
	// Check if the double value is printable, revert back to int to use isprint and string.length
	int int_value = static_cast<int>(double_value);
	std::ostringstream oss;
	oss << int_value;
	std::string int_string = oss.str();

	if (int_string.length() > 3) {
		printChar("Out of printable range");
	}
	else if (std::isprint(int_value)) {
		std::string char_string(1, static_cast<char>(double_value));
		printChar(char_string);
	}
	else {
		printChar("Non displayable");
	}
	// Check for overflow in int and float range
	if (double_value > std::numeric_limits<int>::max() || double_value < std::numeric_limits<int>::min())
		printInt("Non displayable (overflow)");
	else
		printInt(static_cast<int>(double_value));

	if (double_value > std::numeric_limits<float>::max() || double_value < -std::numeric_limits<float>::max())
		printFloat("Non displayable (overflow)");
	else
		printFloat(static_cast<float>(double_value));
	printDouble(double_value);
}



void ScalarConverter::printChar(const std::string& value) {
	std::cout << COLOR_YELLOW << "char: " << COLOR_DEFAULT << value << std::endl;
}

void ScalarConverter::printInt(const std::string& value) {
	std::cout << COLOR_CYAN << "int: " << COLOR_DEFAULT << value << std::endl;
}

void ScalarConverter::printInt(int value) {
	std::cout << COLOR_CYAN << "int: " << COLOR_DEFAULT << value << std::endl;
}

void ScalarConverter::printFloat(const std::string& value) {
	std::cout << COLOR_PURPLE << "float: " << COLOR_DEFAULT << value << std::endl;
}

void ScalarConverter::printFloat(float value) {
	std::cout << COLOR_PURPLE << "float: " << COLOR_DEFAULT << value << (floorf(value) == value ? ".0f" : "f") << std::endl;
}

void ScalarConverter::printDouble(const std::string& value) {
	std::cout << COLOR_ORANGE << "double: " << COLOR_DEFAULT << value << std::endl;
}

void ScalarConverter::printDouble(double value) {
	std::cout << COLOR_ORANGE << "double: " << COLOR_DEFAULT << value << (floor(value) == value ? ".0" : "") << std::endl;
}
