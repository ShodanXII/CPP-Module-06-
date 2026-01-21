#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <limits>


/*
    the fucking types are 
1) pseudo literals (nan, inf…)
2) char
3) int
4) float
5) double
*/


static bool isPseudoLiteral(const std::string& s)
{
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "-inf" ||
            s == "+inff" || s == "-inff");
}


static void printchar(double value, bool ispesdo)
{
    std::cout << "char: ";

    if(value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || ispesdo)
    {
        std::cout << "is Impossible" << std::endl;
        return ;
    }
    char c = static_cast<char>(value);
    if(!std::isprint(c))
    {
        std::cout << "is not desplable" << std::endl;
        return ;
    }
    std::cout << "'" << c << "'" << std::endl;
}

bool parse(const std::string& s, double& value, bool& isPseudo)
{
    char* end;

    isPseudo = false;

    // 1) Pseudo literals
    if (isPseudoLiteral(s))
    {
        isPseudo = true;
        value = std::strtod(s.c_str(), 0);
        return true;
    }

    // 2) Char literal (single non-digit)
    if (s.length() == 1 && !std::isdigit(s[0]))
    {
        value = static_cast<double>(s[0]);
        return true;
    }

    // 3) Int literal
    errno = 0;
    long l = std::strtol(s.c_str(), &end, 10);
    if (*end == '\0' && errno != ERANGE)
    {
        value = static_cast<double>(l);
        return true;
    }

    // 4) Float literal (must end with 'f')
    if (s.length() > 1 && s[s.length() - 1] == 'f')
    {
        errno = 0;
        value = std::strtod(s.substr(0, s.length() - 1).c_str(), &end);
        if (*end == '\0' && errno != ERANGE)
            return true;
    }

    // 5) Double literal
    errno = 0;
    value = std::strtod(s.c_str(), &end);
    if (*end == '\0' && errno != ERANGE)
        return true;

    return false;
}

void ScalarConverter::convert(const std::string& literal)
{
    double value;
    bool isPseudo;

    if (!parse(literal, value, isPseudo))
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    // printChar(value, isPseudo);
    // printInt(value, isPseudo);
    // printFloat(value, isPseudo);
    // printDouble(value, isPseudo);
}
