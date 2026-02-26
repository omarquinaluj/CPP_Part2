#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    private:
        const   std::string name;
        int     grade;
        Bureaucrat(void);
        void    checkGrade(int grade) const;
    public:
        //Canonical form
         Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        //AForm
        void signForm(AForm & form) const;
        void executeForm(AForm const & form) const;

        //Getters
        std::string getName(void) const;
        int getGrade(void) const;
       
       //Controlled modifiers
        void    incrementGrade(void);
        void    decrementGrade(void);

        //Exceptions
        class GradeTooHighException : public std::exception{
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception{
        public:
            virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B);    

#endif