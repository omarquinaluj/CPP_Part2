#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0)); // Inicializamos rand una vez

    try
    {
        Bureaucrat alice("Alice", 1);    // grado alto, puede firmar y ejecutar todo
        Bureaucrat bob("Bob", 50);       // grado medio
        Bureaucrat charlie("Charlie", 150); // grado bajo

        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm roboForm("Marvin");
        PresidentialPardonForm pardonForm("Zaphod");

        std::cout << "\n--- STATUS INICIAL ---\n";
        std::cout << shrubForm << std::endl;
        std::cout << roboForm << std::endl;
        std::cout << pardonForm << std::endl;

        std::cout << "\n--- FIRMAR FORMULARIOS ---\n";
        alice.signForm(pardonForm);  // debería funcionar
        bob.signForm(shrubForm);     // debería funcionar
        charlie.signForm(roboForm);  // debería fallar
        

        std::cout << "\n--- EJECUTAR FORMULARIOS ---\n";
        alice.executeForm(shrubForm);   // ejecuta también
        bob.executeForm(shrubForm);     // ejecuta: suficiente grado
        charlie.executeForm(shrubForm); // falla: grado muy bajo
        
        

        alice.executeForm(roboForm);    // ejecuta: aunque no firmado por Alice (si firma primero)
        bob.executeForm(roboForm);      // falla si no firmado

        alice.executeForm(pardonForm);  // ejecuta correctamente
    }
    catch (std::exception & e)
    {
        std::cout << "EXCEPCION: " << e.what() << std::endl;
    }

    return 0;
}