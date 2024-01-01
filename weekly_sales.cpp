// weekly_sales.cpp: Nithin
// Desc: A program to figure out which way is the best to earn most money

/*

    You have just gotten a position as a salesperson for the ExerShoe company, specializing in high-end exercise shoes costing around $225 per pair. Your boss has given you three options for compensation, which you must choose before you begin your first day:

    Straight salary of $600 per week;
    A salary of $7.00 per hour plus a 10% commission on sales;
    No salary, but 20% commissions and $20 for each pair of shoes sold

    GetInput(WeeklySales);
    CalcMethod1(WeeklySales);
    CalcMethod2(WeeklySales);
    CalcMethod3(WeeklySales);

*/

#include <iostream>

using namespace std;

const int kShoePrice = 225;
const int kHoursPerWeek = 40;

int GetInput(int weekly_sales)
{
    cout << "Enter weekly sales: ";
    cin >> weekly_sales;
    return weekly_sales;
}

int CalcMethod1(int weekly_sales)
{
    int salary = 600;
    cout << "Method 1: " << salary << endl;
    return salary;
}

int CalcMethod2(int weekly_sales)
{
    int salary = 7 * kHoursPerWeek + weekly_sales * kShoePrice * 0.1;
    cout << "Method 2: " << salary << endl;
    return salary;
}

int CalcMethod3(int weekly_sales)
{
    int salary = weekly_sales * kShoePrice * 0.2 + weekly_sales * 20;
    cout << "Method 3: " << salary << endl;
    return salary;
}

int main()
{

    int weekly_sales;

    const int WeeklySales = GetInput(weekly_sales);
    CalcMethod1(WeeklySales);
    CalcMethod2(WeeklySales);
    CalcMethod3(WeeklySales);

    return 0;
}