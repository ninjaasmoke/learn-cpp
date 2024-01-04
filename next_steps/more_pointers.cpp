// more_pointers.cpp : Nithin
// Desc: a program to understand pointers and memory allocation

#include <iostream>

void allocateMemory()
{
    int *ptr = new int; // Allocate memory on the heap
    *ptr = 42;          // Assign a value to the allocated memory
    // No delete statement here, so the memory is not freed
}

void useMemory()
{
    int *ptr = new int;             // Allocate more memory on the heap
    *ptr = 100;                     // Assign a value to the new memory
    std::cout << *ptr << std::endl; // Access the new memory

    // Attempting to access memory allocated in the previous function
    // (which was not freed) could lead to undefined behavior.
    // It's a memory leak.
}

int main()
{
    allocateMemory(); // Calls a function that allocates memory but doesn't free it
    useMemory();      // Calls a function that allocates and uses memory
    // Memory allocated in allocateMemory() is not freed.
    // This is a memory leak.
    return 0;
}
