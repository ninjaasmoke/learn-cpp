// hello.cpp: Nithin
// Desc: a program that prints the immortal "hello world"

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // set `cout` to right align
    cout <<  std::setiosflags(ios::left);
    
    // handle the rows
    for (int i = 0; i < 6; i++) {
        // handle the columns
        for (int j = 0; j < 4; j++) {
            // setw() sets the width of the next output
            cout << setw(17) << "Hello World!";
        }
        cout << endl;
    }

    return 0;
}