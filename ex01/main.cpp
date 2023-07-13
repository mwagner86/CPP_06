
#include "Serializer.hpp"

int main(void) {
	Data* DataStruct = new Data;
	uintptr_t rawData;

	DataStruct->string = "Hello World!";
	DataStruct->c = 'a';
	DataStruct->i = 42;
	DataStruct->f = 42.042f;
	DataStruct->d = 13.37;
	std::cout << COLOR_CYAN << "string : " << COLOR_DEFAULT << DataStruct->string  << std::endl;
	std::cout << COLOR_YELLOW << "char   : " << COLOR_DEFAULT << DataStruct->c  << std::endl;
	std::cout << COLOR_BLUE << "int    : " << COLOR_DEFAULT << DataStruct->i  << std::endl;
	std::cout << COLOR_MAGENTA << "float  : " << COLOR_DEFAULT << DataStruct->f  << std::endl;
	std::cout << COLOR_PURPLE "double : "  << COLOR_DEFAULT << DataStruct->d << std::endl;
	std::cout << COLOR_GREEN << "Pointer Address of Data structure before serialization: " << &DataStruct << COLOR_DEFAULT << std::endl;

	rawData = Serializer::serialize(DataStruct);
	std::cout << "Value of rawData after serialization: " << rawData << std::endl; // Display the rawData value
	DataStruct = Serializer::deserialize(rawData);

	std::cout << COLOR_RED << "Pointer Address of Data structure after deserialization: " << &DataStruct << COLOR_DEFAULT << std::endl;
	std::cout << COLOR_CYAN << "string : "  << COLOR_DEFAULT << DataStruct->string << std::endl;
	std::cout << COLOR_YELLOW << "char   : " << COLOR_DEFAULT << DataStruct->c  << std::endl;
	std::cout << COLOR_BLUE << "int    : " << COLOR_DEFAULT << DataStruct->i << std::endl;
	std::cout << COLOR_MAGENTA << "float  : " << COLOR_DEFAULT << DataStruct->f << std::endl;
	std::cout << COLOR_PURPLE << "double : " << COLOR_DEFAULT << DataStruct->d << std::endl;
	delete DataStruct;
	return 0;
}