#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <cerrno>
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

static void printdouble(double value, bool ispesdo)
{
    std::cout << "Double: ";
    if(ispesdo)
    {
        if(value != value)
            std::cout << "nan" << std::endl;
        else if(value > 0)
            std::cout << "+inf" << std::endl;
        else
            std::cout << "-inf" << std::endl;
        return ;
    }
    if(value == static_cast<int>(value))
        std::cout << value << ".0" << std::endl;
    else
        std::cout << value << std::endl;
}

static void printchar(double value, bool ispesdo)
{
    std::cout << "char: ";

    if (ispesdo || value < 0 || value > 127)
    {
        std::cout << "impossible\n";
        return;
    }    
    char c = static_cast<char>(value);
    if (!std::isprint(static_cast<unsigned char>(c)))
    {
        std::cout << "non displayable" << std::endl;
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

static void printfloat(double value, bool ispesdo)
{
    std::cout << "Float: ";
    if(ispesdo)
    {
        if(value != value)
            std::cout << "nanf" << std::endl;
        else if(value > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
        return ;
    }
    if(value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
    {
        std::cout << "Impossible" << std::endl;
        return;
    }
    float f = static_cast<float>(value);
    if(f == static_cast<int>(f))
        std::cout << f << ".0f" << std::endl;
    else
        std::cout << f << "f" << std::endl;
}

void printint(double value, bool ispesdo)
{
    std::cout << "Int: ";
    if(ispesdo)
    {
        std::cout << "Impossible" <<std::endl;
        return ;
    }
    if (value < std::numeric_limits<int>::min() ||  value > std::numeric_limits<int>::max())
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    int i = static_cast<int>(value);
    std::cout << i << std::endl;
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

    printchar(value, isPseudo);
    printint(value, isPseudo);
    printfloat(value, isPseudo);
    printdouble(value, isPseudo);
}
