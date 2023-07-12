//
// Created by max on 7/12/23.
//

#ifndef EX00_SCALARCONVERTER_HPP
#define EX00_SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstring>
#include "colors.hpp"

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter & src);
	ScalarConverter & operator=(const ScalarConverter & rhs);
	~ScalarConverter();

	static void convert(const std::string& input);

private:
	static int handlePseudoLiterals(const std::string& input);
	static void handleChar(char c);
	static void handleDouble(double double_value, float float_value);
	static void printChar(const std::string& value);
	static void printInt(const std::string& value);
	static void printInt(int value);
	static void printFloat(const std::string& value);
	static void printFloat(float value);
	static void printDouble(const std::string& value);
	static void printDouble(double value);
};

#endif //EX00_SCALARCONVERTER_HPP
