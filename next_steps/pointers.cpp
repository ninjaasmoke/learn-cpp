#include <iostream>

int main()
{
    int a = 5;

    std::cout << "A: " << a;
    std::cout << "\n&A: " << &a;

    int *b = &a;
    *b = a;

    std::cout << "\n*B: " << *b;
    std::cout << "\nB: " << b;

    if (b == &a && *b ==a)
    {
        std::cout << "\n(b == &a && *b ==a): They are same\n";
    }
    else
    {
        std::cout << "\n(b == &a && *b ==a): They are not\n";
    }

    return 0;
}