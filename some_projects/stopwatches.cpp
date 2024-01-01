// stopwatches.cpp : Nithin
// Desc : a program to accept time in seconds and output number of hours, minutes and seconds

/*
3.
As electronic stopwatches become cheaper and more accurate, we will no doubt be deluged with impossibly accurate measurements of time.
Write a program that takes as input a time period given in seconds, and outputs the number of hours, minutes and seconds it represents.

For example,

Number of seconds: 3662
Hours: 1
Minutes: 1
Seconds: 2
*/

/*
Author comments:

- seems ez
- start:    10:41pm 01-01-2024
- end:      11:01pm 01-01-2024
*/

#include <iostream>
#include <limits>
#include <cstdlib>
#include <cmath>

using namespace std;

const int kSecondsPerHour = 3600;
const int kSecondsPerMinute = 60;

int GetSeconds(const string &prompt)
{
    int input;

    do
    {
        std::cout << prompt;
        if (!(std::cin >> input) || input < 0)
        {
            std::cout << "Enter a number greater than 0\n";
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return GetSeconds(prompt);
        }
        else
        {
            break;
        }
    } while (true);

    return input;
}

int GetHoursFromSeconds(int &seconds)
{

    int hours = seconds / kSecondsPerHour;
    seconds = seconds - (hours * kSecondsPerHour);
    return floor(hours);
}

int GetMinutesFromSeconds(int &seconds)
{

    int minutes = seconds / kSecondsPerMinute;
    seconds = seconds - (minutes * kSecondsPerMinute);
    return floor(minutes);
}

int main()
{
    int seconds = GetSeconds("Enter number of seconds:\t");

    int hours = GetHoursFromSeconds(seconds);
    int minutes = GetMinutesFromSeconds(seconds);

    cout << "Hours:\t" << hours << endl;
    cout << "Minutes:\t" << minutes << endl;
    cout << "Seconfs:\t" << seconds;

    return 0;
}