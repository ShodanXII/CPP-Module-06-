#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
    Data data;
    data.value = 42;

    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Original value: " << data.value << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr << std::endl;
    std::cout << "Deserialized value: " << ptr->value << std::endl;

    if (ptr == &data)
        std::cout << "Success: pointers match!" << std::endl;

    return 0;
}