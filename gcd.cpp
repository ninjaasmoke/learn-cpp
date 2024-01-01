// gcd.cpp: Nithin
//  Desc: a prog to find the greatest common divisor of two numbers.

#include <iostream>

using namespace std;

int GCD(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    if (num1 == 0)
    {
        return num2;
    }
    int smaller_number = num1 < num2 ? num1 : num2;
    for (int i = smaller_number; i > 0; i--)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            return i;
        }
    }
}

int EuclideanGCD(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{

    int num1, num2;

    cout << "Enter two integers!" << endl;
    cin >> num1 >> num2;

    int gcd = GCD(num1, num2);
    int e_gcd = EuclideanGCD(num1, num2);

    if (gcd < 0)
    {
        cout << "No common divisor found!" << endl;
    }
    else
    {
        cout << "GCD(" << num1 << "," << num2 << ") = " << gcd << endl;
        cout << "EuclideanGCD(" << num1 << "," << num2 << ") = " << e_gcd << endl;
    }

    return 0;
}
