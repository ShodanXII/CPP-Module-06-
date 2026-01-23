#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int r = rand() % 3;

    if (r == 0)
    {
        std::cout << "Generated A" << std::endl;
        return new A();
    }
    else if (r == 1)
    {
        std::cout << "Generated B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generated C" << std::endl;
        return new C();
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}
}

int main(void)
{
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        Base *base = generate();

        std::cout << "Pointer   : ";
        identify(base);

        std::cout << "Reference : ";
        identify(*base);

        std::cout << "----------------" << std::endl;

        delete base;
    }
    return 0;
}
