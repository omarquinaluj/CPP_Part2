#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

template <typename T>
class Array
{
private:
    T* array;
    unsigned int len;

public:
    class indexOutOfBounds : public std::exception
    {
    public:
        const char* what() const throw()
        {
            return ("Index Out Of Bounds");
        }
    };

    Array();
    Array(unsigned int n);
    Array(const Array& before);
    ~Array();

    Array& operator=(const Array& before);

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;
};

#include "Array.tpp"