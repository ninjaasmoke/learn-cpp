// cricket_chirps.cpp: Nithin Sai
// Desc: This program calculates the temperature based on the number of cricket chirps

/*
The common field cricket chirps in direct proportion to the current temperature.
Adding 40 to the number of time a cricket chirps in a minute, then dividing that value by 4 gives us the temperature.
Write a program that takes as input the number of chirps in a minute and prints the current temperature.
For example,

Number of chirps: 120
The temperature is: 40.0 degrees.
*/

/*
Comments by author:

- seems pretty simple
- math is also simple
- start 9:06pm 01-01-2024
- end 9:18pm 01-01-2024 (wtf? how did this take so long?)

- modifications:
    - static float
    - added comments

*/

#include <iostream>

using namespace std;

float CalculateTemperature(int chirps)
{
    if (chirps < 1)
    {
        return 0;
    }

    // float temperature = (float(chirps) + 40) / 4;

    // evidently this is a better way to do this
    float temperature = static_cast<float>(chirps + 40) / 4.0f;

    return temperature;
}

int main()
{
    int chirps;
    char choice;

    // a do-while loop to repeat this
    do
    {
        cout << "Enter the number of chirps per minute: ";

        if (!(cin >> chirps))
        {
            cout << "eh! enter a number!" << endl;
            cin.clear();
            cin.ignore(10000, '\n'); // the last arguement is a character NOT a string!
            continue;
        }

        float temperature = CalculateTemperature(chirps);

        cout << "Temperature: " << temperature << " degrees." << endl;

        cout << "Contiue? (y/n): ";
        cin >> choice;

    } while (choice != 'n');

    return 0;
}