#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "===== TEST 1: Valid creation =====" << std::endl;
    try
    {
        Form f1("Contract", 50, 25);
        std::cout << f1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Grade too hight =====" << std::endl;
    try
    {
        Form f2("InvalidHigh", 0, 10);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: Grade too low =====" << std::endl;
    try
    {
        Form f3("InvalidLow", 10, 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: Correct sign =====" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 10);
        Form f4("TopSecret", 20, 5);

        std::cout << f4 << std::endl;
        f4.beSigned(boss);
        std::cout << "After signing:" << std::endl;
        std::cout << f4 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 5: Sign with grade insuficent =====" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 100);
        Form f5("ImportantDoc", 50, 10);

        f5.beSigned(intern);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 6: Copy constructor =====" << std::endl;
    try
    {
        Form original("Original", 30, 10);
        Bureaucrat chief("Chief", 1);
        original.beSigned(chief);

        Form copy(original);

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 7: Operator= =====" << std::endl;
    try
    {
        Form a("FormA", 40, 20);
        Form b("FormB", 5, 2);

        Bureaucrat director("Director", 1);
        b.beSigned(director);

        std::cout << "Before of change:" << std::endl;
        std::cout << "A: " << a << std::endl;
        std::cout << "B: " << b << std::endl;

        a = b;

        std::cout << "\nAfter of change(A = B):" << std::endl;
        std::cout << "A: " << a << std::endl;
        std::cout << "B: " << b << std::endl;

        //Nota: the name y grades of A DONT change (are const).
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}