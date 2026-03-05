#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib> // Pour strtol
#include <climits> // Pour INT_MAX et INT_MIN
#include <string>
#include <iostream>
typedef void (*t_conv_func)(const std::string&);

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);

		ScalarConverter &operator=(const ScalarConverter &other);

		~ScalarConverter();
		
	public:

		static void convert(const std::string& value);
};

void printFloat(const std::string& value);
void printDouble(const std::string& value);


#endif
