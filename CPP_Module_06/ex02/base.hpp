#pragma once
#ifndef BASE_HPP
# define BASE_HPP
# include <iostream>
# include <cstdlib>

class Base
{
    public:

        Base* generate(void);
        Base(void);
        virtual ~Base();
};

void identify(Base& p);
void identify(Base* p);

#endif