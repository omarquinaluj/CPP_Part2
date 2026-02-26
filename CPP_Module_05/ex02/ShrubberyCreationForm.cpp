#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("shrubbery", 145, 137), target(target)
{
	//std::cout << "shrubbery default constructor called" << std::endl
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	//std::cout << "shrubbery default destructor called" << std::endl
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy), target(copy.target)
{
	//std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{

	//std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	this->target = other.target;
	return *this;
}

void ShrubberyCreationForm::_execute(Bureaucrat const & executor) const
{
    checkExec(executor); // lanza excepción si no se puede ejecutar

    std::string file_name = target + "_shrubbery";
    std::string content =
    "                 ###############\n"
    "                  ########################|\n"
    "                ##########\\####||#\\//###\\#####\n"
    "               ####\\###\\//###||###//#\\##//##\n"
    "           ######\\###//#\\#||##//###\\//######\n"
    "          ########\\#//###\\||//##//##//##\n"
    "            #######\\\\###\\#|#//////####\n"
    "                ####\\\\||//#//#####\n"
    "                  #####\\||#####\n"
    "                       ||||\n"
    "                       ||||\n"
    "                       ||||\n";

    // Después:
	std::ofstream file(file_name.c_str());
    if (file.is_open())
    {
        file << content;
        file.close();                       	
    }
    else
        std::cout << "There has been an error opening the file" << std::endl;
}