#include <iostream>
#include <string>
#include <stdint.h>

typedef struct s_Data
{
    std::string string;
    char        c;
    int         i;
    float       f;
    double      d;
} Data;

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

int main(void)
{
    Data        *myData;
    Data        *deserializedData;
    uintptr_t   rawData;

    myData = new Data;

    myData->string = "Hello World!";
    myData->c = 'J';
    myData->i = 42;
    myData->f = 8.15f;
    myData->d = 4711.0;

    std::cout << "string : " << myData->string << std::endl;
    std::cout << "char   : " << myData->c << std::endl;
    std::cout << "int    : " << myData->i << std::endl;
    std::cout << "float  : " << myData->f << std::endl;
    std::cout << "double : " << myData->d << std::endl;

    std::cout << "Pointer before serialization: "
              << myData << std::endl;

    rawData = serialize(myData);
    deserializedData = deserialize(rawData);

    std::cout << "Pointer after deserialization: "
              << deserializedData << std::endl;

  

    std::cout << "string : " << deserializedData->string << std::endl;
    std::cout << "char   : " << deserializedData->c << std::endl;
    std::cout << "int    : " << deserializedData->i << std::endl;
    std::cout << "float  : " << deserializedData->f << std::endl;
    std::cout << "double : " << deserializedData->d << std::endl;

    if (myData == deserializedData)
        std::cout << "Pointers are equal!" << std::endl;
    else
        std::cout << "Pointers are different!" << std::endl;

    delete myData;

    return (0);
}

uintptr_t serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}