#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    try
    {
        Bureaucrat alice("Alice", 1);    // grade high
        Bureaucrat bob("Bob", 50);       // grade medium
        Bureaucrat charlie("Charlie", 150); // grade low

        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm roboForm("Marvin");
        PresidentialPardonForm pardonForm("Zaphod");

        std::cout << "\n--- STATUS INICIAL ---\n";
        std::cout << shrubForm << std::endl;
        std::cout << roboForm << std::endl;
        std::cout << pardonForm << std::endl;

        std::cout << "\n--- FIRMAR FORMULARIOS ---\n";
        alice.signForm(pardonForm);  // ok
        bob.signForm(shrubForm);     // ok
        charlie.signForm(roboForm);  // F
        

        std::cout << "\n--- EJECUTAR FORMULARIOS ---\n";
        alice.executeForm(shrubForm);   // ok
        bob.executeForm(shrubForm);     // ok
        charlie.executeForm(shrubForm); // F
        
        std::cout << "\n";

        alice.executeForm(roboForm);    //ok if change people
        bob.executeForm(roboForm);      //F
        charlie.executeForm(roboForm);  //F

        std::cout << "\n";

        alice.executeForm(pardonForm);  // ok
        bob.executeForm(pardonForm); // F
        charlie.executeForm(pardonForm); //F


    }
    catch (std::exception & e)
    {
        std::cout << "EXCEPCION: " << e.what() << std::endl;
    }

    return 0;
}