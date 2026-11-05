
#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>

static bool	isCharLiteral(const std::string &literal)
{
	return (literal.length() == 3
		&& literal[0] == '\''
		&& literal[2] == '\'');
}

static bool	isIntegerLiteral(const std::string &literal)
{
	size_t	i;

	if (literal.empty())
		return (false);
	i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return (false);
	while (i < literal.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(literal[i])))
			return (false);
		i++;
	}
	return (true);
}

static bool	isFloatLiteral(const std::string &literal)
{
	size_t	i;
	bool	dot;
	bool	digit;

	if (literal.length() < 4)
		return (false);
	if (literal[literal.length() - 1] != 'f')
		return (false);
	i = 0;
	dot = false;
	digit = false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length() - 1)
		return (false);
	while (i < literal.length() - 1)
	{
		if (std::isdigit(static_cast<unsigned char>(literal[i])))
			digit = true;
		else if (literal[i] == '.' && !dot)
			dot = true;
		else
			return (false);
		i++;
	}
	return (dot && digit);
}

static bool	isDoubleLiteral(const std::string &literal)
{
	size_t	i;
	bool	dot;
	bool	digitBeforeDot;
	bool	digitAfterDot;

	if (literal.empty())
		return (false);
	i = 0;
	dot = false;
	digitBeforeDot = false;
	digitAfterDot = false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (i < literal.length())
	{
		if (std::isdigit(static_cast<unsigned char>(literal[i])))
		{
			if (!dot)
				digitBeforeDot = true;
			else
				digitAfterDot = true;
		}
		else if (literal[i] == '.' && !dot)
			dot = true;
		else
			return (false);
		i++;
	}
	return (dot && digitBeforeDot && digitAfterDot);
}

static bool	isSpecialLiteral(const std::string &literal)
{
	return (literal == "nan"
		|| literal == "+inf"
		|| literal == "-inf"
		|| literal == "nanf"
		|| literal == "+inff"
		|| literal == "-inff");
}

static bool	isFloatSpecial(const std::string &literal)
{
	return (literal == "nanf"
		|| literal == "+inff"
		|| literal == "-inff");
}

static double	toDouble(const std::string &literal)
{
	char	*end;
	double	value;

	errno = 0;
	end = NULL;
	value = std::strtod(literal.c_str(), &end); //
	if (errno == ERANGE)
		return (value);
	return (value);
}

static bool	isInIntRange(double value)
{
	return (value >= static_cast<double>(std::numeric_limits<int>::min())
		&& value <= static_cast<double>(std::numeric_limits<int>::max()));
}

static bool	isInCharRange(double value)
{
	return (value >= 0.0 && value <= 127.0);
}

static bool	isPrintableChar(int value)
{
	return (value >= 32 && value <= 126);
}

static void	printChar(double value)
{
	int	charValue;

	if (std::isnan(value) || std::isinf(value)
		|| !isInCharRange(value))
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	charValue = static_cast<int>(value);
	if (!isPrintableChar(charValue))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(charValue) << "'"
			<< std::endl;
}

static void	printInt(double value)
{
	if (std::isnan(value) || std::isinf(value)
		|| !isInIntRange(value))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void	printFloat(double value)
{
	float	floatValue;

	floatValue = static_cast<float>(value);
	if (std::isnan(floatValue))
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	if (std::isinf(floatValue))
	{
		if (floatValue < 0)
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: +inff" << std::endl;
		return ;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< floatValue << "f" << std::endl;
}

static void	printDouble(double value)
{
	if (std::isnan(value))
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		if (value < 0)
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: +inf" << std::endl;
		return ;
	}
	std::cout << "double: " << std::fixed << std::setprecision(1)
		<< value << std::endl;
}

t_type	ScalarConverter::getDataType(const std::string &literal)
{
	if (isSpecialLiteral(literal))
	{
		if (isFloatSpecial(literal))
			return (TYPE_FLOAT);
		return (TYPE_DOUBLE);
	}
	if (isCharLiteral(literal))
		return (TYPE_CHAR);
	if (isIntegerLiteral(literal))
		return (TYPE_INT);
	if (isFloatLiteral(literal))
		return (TYPE_FLOAT);
	if (isDoubleLiteral(literal))
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

void	ScalarConverter::convert(const std::string &literal)
{
	t_type	type;
	double	value;

	type = getDataType(literal);
	if (type == TYPE_INVALID)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (type == TYPE_CHAR)
		value = static_cast<double>(literal[1]);
	else if (isSpecialLiteral(literal))
	{
		if (literal == "nan" || literal == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "-inf" || literal == "-inff")
			value = -std::numeric_limits<double>::infinity();
		else
			value = std::numeric_limits<double>::infinity();
	}
	else
		value = toDouble(literal);

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
