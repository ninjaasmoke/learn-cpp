// classes_intro.cpp : Nithin
// Desc: a program as an introduction to classes and objects in cpp

#include <iostream>

using namespace std;

class Time
{
private:
    int hours_;
    int minutes_;
    int seconds_;

public:
    void set(int h, int m, int s)
    {
        hours_ = h;
        minutes_ = m;
        seconds_ = s;
        return;
    }
    void increment();
    void display();
    void decrement();
};

void Time::increment()
{
    seconds_++;
    minutes_ += seconds_ / 60;
    hours_ += minutes_ / 60;

    seconds_ %= 60;
    minutes_ %= 60;
    hours_ %= 24;

    return;
}

void Time::display()
{
    std::cout << (hours_ % 12 ? hours_ % 12 : 12) << ":"
              << (minutes_ < 10 ? "0" : "") << minutes_ << ":"
              << (seconds_ < 10 ? "0" : "") << seconds_ << " "
              << (hours_ < 12 ? "AM" : "PM") << endl;
    return;
}

void Time::decrement()
{
    seconds_--;

    if (seconds_ < 0)
    {
        seconds_ = 59;
        minutes_--;
        if (minutes_ < 0)
        {
            minutes_ = 59;
            hours_--;
            if (hours_ < 0)
            {
                hours_ = 23;
            }
        }
    }

    return;
}

int main()
{
    Time timer;

    timer.set(0, 0, 2);
    for (int i = 0; i < 5; i++)
    {
        // timer.increment();
        timer.decrement();
        timer.display();
        cout << endl;
    }

    return 0;
}