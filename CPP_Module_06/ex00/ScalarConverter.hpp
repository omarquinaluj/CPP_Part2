
#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <iomanip>
# include <cstdlib>
# include <cerrno>

typedef enum e_type
{
	TYPE_INVALID = -1,
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE
}	t_type;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &other);

		static t_type	getDataType(const std::string &literal);

	public:
		static void	convert(const std::string &literal);
};

#endif
