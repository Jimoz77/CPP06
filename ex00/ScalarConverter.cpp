#include "ScalarConverter.hpp"
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iomanip>


enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL,    // Pour les nan, inf, etc.
    IMPOSSIBLE  // Si la chaîne est invalide (ex: "42.5.5f" ou "bonjour")
};


ScalarConverter::ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

int what_type(const std::string& arg)
{
    if (arg == "nan" || arg == "+inf" || arg == "-inf" || arg == "nanf" || arg == "+inff" || arg == "-inff")
        return (SPECIAL);
    if (arg.length() == 1 && !isdigit(arg[0]))
        return (CHAR);
    int points = 0;
    int fs = 0;
    for (size_t i = 0; i < arg.length(); i++)
    {
        if (i == 0 && (arg[i] == '+' || arg[i] == '-'))
            continue;
        if (arg[i] == '.')
        {
            points++;
            continue;
        }
        if (arg[i] == 'f')
        {
            fs++;
            continue;
        }
        if (!isdigit(arg[i]))
            return IMPOSSIBLE;
    }
    if (points > 1 || fs > 1 || (fs == 1 && arg[arg.length() - 1] != 'f'))
        return IMPOSSIBLE;
    if (fs == 1)
        return FLOAT;
    if (points == 1)
        return DOUBLE;
    return INT;
}
bool has_decimals(double val)
{
	return(std::fmod(val, 1.0) != 0.0);
}

void printChar(const std::string& value)
{
    char c_val = value[0];
    int i_val = static_cast<int>(c_val);
    float f_val = static_cast<float>(c_val);
    double d_val = static_cast<double>(c_val);
    std::cout << "char: '" << c_val << "'\n";
    std::cout << "int: " << i_val << "\n";
	if(!has_decimals(d_val))
        std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f_val << "f\n";
	std::cout << "double: " << d_val << "\n";
	std::cout.unsetf(std::ios_base::floatfield); // C++98 : Enlève le mode "fixed"
	std::cout << std::setprecision(6);           // C++98 : Remet la précision par défaut
}

void printInt(const std::string& value)
{
		char*endptr;
        double d_val = std::strtod(value.c_str(), &endptr);
        if (d_val < 0 || d_val > 127)
            std::cout << "char: impossible\n";
        else if (!isprint(static_cast<int>(d_val)))
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: '" << static_cast<char>(d_val) << "'\n";
		if(d_val > INT_MAX || d_val < INT_MIN)
			std::cout << "int: impossible\n";	//problem !!!!!
		else
			std::cout << "int: " << static_cast<int>(d_val) << "\n";
		if(!has_decimals(d_val))
			std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(d_val) << "f\n";
		std::cout << "double: " << d_val << "\n";
		std::cout.unsetf(std::ios_base::floatfield); // C++98 : Enlève le mode "fixed"
		std::cout << std::setprecision(6);  
}

void printFloat(const std::string& value)
{
	char* endptr;
	double d_val = std::strtod(value.c_str(), &endptr);
	if (d_val < 0 || d_val > 127)
		std::cout << "char: impossible\n";
	else if (!isprint(static_cast<int>(d_val)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d_val) << "'\n";
	if(d_val > INT_MAX || d_val < INT_MIN)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d_val) << "\n";
	if(!has_decimals(d_val))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d_val) << "f\n";
	std::cout << "double: " << d_val << "\n";
	std::cout.unsetf(std::ios_base::floatfield); // C++98 : Enlève le mode "fixed"
	std::cout << std::setprecision(6); 
}

void printDouble(const std::string& value)
{
	char *endptr;
	double d_val = std::strtod(value.c_str(), &endptr);
	if (d_val < 0 || d_val > 127)
		std::cout << "char: impossible\n";
	else if (!isprint(static_cast<int>(d_val)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d_val) << "'\n";
	if(d_val > INT_MAX || d_val < INT_MIN)
		std::cout << "int: impossible\n";	//problem !!!!!
	else
		std::cout << "int: " << static_cast<int>(d_val) << "\n";
	if(!has_decimals(d_val))
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d_val) << "f\n";
	std::cout << "double: " << d_val << "\n";
	std::cout.unsetf(std::ios_base::floatfield);
	std::cout << std::setprecision(6);
}

void ScalarConverter::convert(const std::string& value)
{
	int type = what_type(value);
	if (type == IMPOSSIBLE)
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    if (type == SPECIAL)
    {
        std::cout << "char: impossible\nint: impossible\n";
        if (value == "nan" || value == "nanf")
            std::cout << "float: nanf\ndouble: nan\n";
        else if (value == "+inf" || value == "+inff")
            std::cout << "float: +inff\ndouble: +inf\n";
        else if (value == "-inf" || value == "-inff")
            std::cout << "float: -inff\ndouble: -inf\n";
        return;
    }
    t_conv_func funcs[4] = 
    {
        &printChar,
        &printInt,
        &printFloat,
        &printDouble
    };
    funcs[type](value);
}


ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}
