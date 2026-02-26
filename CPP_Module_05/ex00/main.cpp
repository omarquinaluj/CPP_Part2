#include "Bureaucrat.hpp"

int main()
{
    std::cout << "===== TEST 1: Valid creation =====" << std::endl;
    try
    {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 2: Grade too high =====" << std::endl;
    try
    {
        Bureaucrat b("Bob", 0);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 3: Grade too low =====" << std::endl;
    try
    {
        Bureaucrat c("Charlie", 151);
        std::cout << c << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 4: Increment until excepcion =====" << std::endl;
    try
    {
        Bureaucrat d("David", 2);
        std::cout << d << std::endl;
        d.incrementGrade();
        std::cout << d << std::endl;
        d.incrementGrade(); 
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 5: Decrement until excepcion =====" << std::endl;
    try
    {
        Bureaucrat e("Eve", 149);
        std::cout << e << std::endl;
        e.decrementGrade();
        std::cout << e << std::endl;
        e.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 6: Copy constructor =====" << std::endl;
    try
    {
        Bureaucrat original("Frank", 10);
        Bureaucrat copy(original); // copy constructor

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== TEST 7: Operator = =====" << std::endl;
    try
    {
        Bureaucrat first("George", 50);
        Bureaucrat second("Henry", 3);

        std::cout << "Before:" << std::endl;
        std::cout << "First:  " << first << std::endl;
        std::cout << "Second: " << second << std::endl;

        first = second; // operator=

        std::cout << "\nAfter (first = second):" << std::endl;
        std::cout << "First:  " << first << std::endl;
        std::cout << "Second: " << second << std::endl;

        //Note: The name 'first' does NOT change because it is const."
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
