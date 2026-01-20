#pragma once

#include <iostream>
#include <string>

class ScalarConverter
{
private:
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter& copy);
	~ScalarConverter( void );
public:
	static void convert(const std::string& literal);
};
