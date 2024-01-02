// encoding_dates.cpp : Nithin
// Desc : a program that decodes encoded dates

/*
6.
The law requires that food product manufacturers place expiration dates on their products, but there is a loophole in the law:
it does not require the expiration date to be in any particular form.
So, it can be written in Swahili and still be legal.
Ralph Nader's third cousin, Nadine is a self-appointed Food Quality Spy.
She has learned that many food product manufacturers have started encoding the product expiration dates to keep customers from knowing how old the stuff is.

But the encoding does allow grocers to figure out the expiration dates if for some reason, they want to.

One popular encoding method:

encode the months from Jan to Dec as 'A' through 'L'
encode each digit of the date as 'Q' through 'Z'
encode the year as 'A' through 'Z' meaning 1 through 26 which is then added to 1995.

Nadine found a particularly questionable loaf of bread with this date: ARZM.
Write a program to determine the date.
*/

/*
Authors comments:

-   seems like we need to do some string ops
-   assumption:
    -   all the inputs are 4 characters long
    -   the inputs are characters
-   start:      10:02pm 02-01-2024
-   end:        11:21pm 02-01-2024
*/

#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

using month_map_t = std::map<char, string>;

const int kInputChars = 4;
const int kNumMonths = 12;
const int kNumDigits = 10;
const int kStartYear = 1995;
const int kNumAlphabets = 26;

const int kMonthCodeLoc = 0;
const int kDigitsLoc[2] = {1, 2};
const int kYearLoc = 3;

const string kAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string kMonths[kNumMonths] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

// preprocessing: generating a month map
void GenerateMonthMap(month_map_t &month_map)
{

    for (int i = 0; i < kNumMonths; i++)
    {
        month_map[kAlphabet[i]] = kMonths[i];
    }

    return;
}

int GetYearFromChar(const char &c)
{
    for (int i = 0; i < sizeof(kAlphabet); i++)
    {
        if (kAlphabet[i] == c)
        {
            return (kStartYear + i + 1);
        }
    }
    return 0;

    /*
    Arguably a simpler way to do the same:

    int idx = kAplhabet.find(c)

    if(idx!=string::npos) {
        return 0;
    }

    return  kStartYear + idx + 1;

    */
}

int GetDigitFromChar(const char &c)
{
    for (int i = kNumDigits, j = kNumAlphabets; i > 0; i--, j--)
    {
        if (kAlphabet[j] == c)
        {
            return i;
        }
    }

    return 0;
}

int main()
{
    char input[kInputChars];
    month_map_t kMonthMap;

    GenerateMonthMap(kMonthMap);

    cout << "Enter the date: ";
    cin >> input;

    const char month_code = input[kMonthCodeLoc];

    if (kMonthMap.find(month_code) == kMonthMap.end())
    {
        cout << "Invalid month code! Enter values as 'A' through 'L'" << endl;
        exit(1);
    }

    std::string date_code = "";
    for (int i = 1; i <= 2; i++)
    {
        int digit = GetDigitFromChar(input[i]);
        if (digit == 0)
        {
            cout << "Invalid date code! Enter values as 'Q' through 'Z'" << endl;
            exit(1);
        }
        else
        {
            date_code += std::to_string(digit);
        }
    }

    const int year_code = GetYearFromChar(input[kYearLoc]);

    if (year_code == 0)
    {
        cout << "Invalid year code! Enter values as 'A' through 'Z'" << endl;
        exit(1);
    }

    cout << "\nMonth:\t" << kMonthMap[month_code] << endl;
    cout << "Day:\t" << date_code << endl;
    cout << "Year:\t" << year_code << endl;

    return 0;
}