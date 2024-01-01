// farmer.cpp: Nithin
// Desc: a prog to find how many animals a farmer bought
/*
    a hourse costs 10$
    a pig costs 3$
    a rabbit costs 0.5$
    the farmer has 100$
    the farmer bought 100 animals
*/

#include <iostream>

using namespace std;

int main()
{

    for (int h = 0; h < 100; h++)
        for (int p = 0; p < 100; p++)
            for (int r = 0; r < 100; r++)
                if ((h + p + r) == 100 && (10 * h + 3 * p + 0.5 * r) == 100)
                    cout << "horses: " << h << " pigs: " << p << " rabbits: " << r << endl;

    return 0;
}