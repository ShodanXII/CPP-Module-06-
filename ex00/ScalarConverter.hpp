#pragma once

#include <iostream>
#include <string>

class ScalarConverter
{
public:
	ScalarConverter( void );
	ScalarConverter(ScalarConverter &&) = default;
	ScalarConverter(const ScalarConverter &) = default;
	ScalarConverter &operator=(ScalarConverter &&) = default;
	ScalarConverter &operator=(const ScalarConverter &) = default;
	~ScalarConverter( void );
	static void convert(const std::string& literal);
};
