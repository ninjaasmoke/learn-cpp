// const_pointers.cpp : Nithin
// Desc: a program to understand constants and pointers

#include <iostream>

using namespace std;

int main()
{
    int x = 10;
    std::cout << "X: " << x << std::endl;
    int *xptr = &x; // Pointer to a variable
    std::cout << "*Xptr: " << *xptr << std::endl;

    int y = 20;
    std::cout << "y: " << y << std::endl;
    const int *yptr = &y; // Constant pointer to a variable
    std::cout << "*yptr: " << *yptr << std::endl;

    // const int z = 30;
    // int *const zptr = &z; // Pointer to a constant variable
    /*
    DOES NOT work!
    occurs because we are attempting to create a constant pointer (int *const) to a constant variable (const int z).
    In C++, we cannot assign the address of a constant variable to a non-const pointer.
    */

    const int w = 40;
    std::cout << "w: " << w << std::endl;
    const int *const wptr = &w; // Constant pointer to a constant variable
    std::cout << "*wptr: " << *wptr << std::endl;
    std::cout << "wptr: " << wptr << std::endl;

    return 0;
}