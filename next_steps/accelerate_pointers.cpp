// accelerate_pointers.cpp : Nithin
// Desc: understanding pointers

/*
Write a function called accelerate() that takes as input the speed of a vehicle, and an amount.
The function adds the amount to the speed to accelerate the vehicle.
The speed parameter should be passed by reference, and amount by value.
*/

#include <iostream>

using namespace std;

void accelerate(float &speed, float acceleration);

int main()
{

    float speed;
    float acceleration;
    cout << "Enter the speed of the vehicle: ";
    cin >> speed;

    cout << "Enter the acceleration factor: ";
    cin >> acceleration;

    accelerate(speed, acceleration);

    cout << "New speed is: " << speed << endl;

    return 0;
}

void accelerate(float &speed, float acceleration)
{
    speed += acceleration;
    return;
}