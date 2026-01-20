#pragma once

#include <iostream>
#include <string>


enum LiteralType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};


class ScalarConverter
{
private:
	ScalarConverter( void );
	ScalarConverter( const ScalarConverter& copy);
	~ScalarConverter( void );
public:
	static void convert(const std::string& literal);
};
