// pointers.cpp : Nithin
// Desc: a program to understand pointers


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

    int *intptr; 
                // Declare a pointer that holds the address
                // of a memory location that can store an integer.
                // Note the use of * to indicate this is a pointer variable.

    intptr = new int; 
    // Allocate memory for the integer.
    /*
    This is a keyword in C++ that allocates memory on the heap for an integer. 
    The new keyword returns a pointer to the first byte of the allocated space.
    */

    *intptr = 5; 
    // Store 5 in the memory address stored in intptr.

    /*
Stack: The stack is a region of memory that is used for local variables and function call information. 
When you declare a variable like int *intptr;, that variable is usually stored on the stack. 
The stack is a fast and automatically managed memory space, and it's well-suited for managing local variables and function calls.

So, in the case of 
`int *intptr;`, 
the memory for the pointer variable itself (intptr) is allocated on the stack.

Heap: The heap, on the other hand, is a region of memory used for dynamic memory allocation. 
When you use new to allocate memory, as in `intptr = new int;`, the memory for the integer is allocated on the heap. 
The pointer variable intptr (on the stack) holds the address of this dynamically allocated memory.

The heap is used for data that needs to persist beyond the scope of the current function, or when you need a more flexible memory management approach.

Here's a simple representation:

diff
Copy code
Stack                        Heap
+------------------+         +------------------------+
|      intptr      |         |           5            |
+------------------+         +------------------------+
In the diagram:

intptr (on the stack) holds the address of the dynamically allocated memory (on the heap).
The value 5 is stored at the memory location on the heap.
    */

    return 0;
}