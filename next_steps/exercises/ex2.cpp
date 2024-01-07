// ex2.cpp : Nithin
// Desc : a program used for estimating book sales.

/*
Exercise 2

Your college book store needs your help in estimating its business for next year.
Experience has shown that sales depend greatly on whether a book is required for a course or just optional, and whether or not it has been used in the class before.
A new, required textbook will sell to 90% of prospective enrollment, but if it has been used in the class before, only 65% will buy.
Similarly, 40% of prospective enrollment will buy a new, optional textbook, but if it has been used in the class before only 20% will buy.
(Note that "used" here does not mean second-hand books.)

Write a program that accepts as input a series of books (until the user enters a sentinel).

For each book ask for:
a code for the book,
the single copy cost for the book,
the current number of books on hand,
the prospective class enrollment,
and data that indicates if the book is required/optional, new/used in past.

As output,
show all the input information in a nicely formatted screen along with how many books must be ordered (if any, note that only new books are ordered),
the total cost of each order.

Then, after all input is complete, show the total cost of all book orders, and the expected profit if the store pays 80% of list price.
Since we have not yet discussed any ways of dealing with a large set of data coming into a program (stay tuned!), just process one book at a time and show the output screen for that book.
Then, when the user has finished entering all the data, your program should output the total and profit values.

Before you start writing code, take some time to think about design of this program.
Decompose into a set of functions, and create a main() function that reads like an outline for your solution to the problem.
Make sure each function does one task.
*/

#include <iostream>
#include <unordered_map>
#include <limits>

using namespace std;

const float kPercentRequiredUsed = 0.65f;
const float kPercentRequiredNew = 0.90f;
const float kPercentOptionalUsed = 0.20f;
const float kPercentOptionalNew = 0.40f;
const float kProfitPercentage = 0.20f;

struct BookData
{
    int code;
    float cost;
    float class_enrollment;
    char required;
    char used;
};

class Book
{
private:
    BookData data_;
    int num_books_;
    int need_to_order_;
    float total_cost_;

    float calculatePercentage(bool required, bool used)
    {
        if (required)
        {
            return used ? kPercentRequiredUsed : kPercentRequiredNew;
        }
        else
        {
            return used ? kPercentOptionalUsed : kPercentOptionalNew;
        }
    }

    void CalulateOrdersNeeded()
    {

        float percent = calculatePercentage(data_.required == 'Y', data_.used == 'Y');
        need_to_order_ = static_cast<int>(data_.class_enrollment * percent) - num_books_;
    }

    void CalculateTotalCost()
    {
        total_cost_ = need_to_order_ * data_.cost;
    }

public:
    void Set(BookData data, int num_books)
    {
        num_books_ = num_books;
        data_.code = data.code;
        data_.cost = data.cost;
        data_.class_enrollment = data.class_enrollment;
        data_.required = data.required;
        data_.used = data.used;
        CalulateOrdersNeeded();
        CalculateTotalCost();
        return;
    }

    void Show()
    {
        std::cout << "\n---------------------\n"
                  << "Book details:" << std::endl
                  << "Code:\t\t\t" << data_.code << std::endl
                  << "Cost:\t\t\t" << data_.cost << std::endl
                  << "Class Enrollment:\t" << data_.class_enrollment << std::endl
                  << "Required:\t\t" << (data_.required == 'Y' ? true : false) << std::endl
                  << "Used Before:\t\t" << (data_.used == 'Y' ? true : false) << std::endl
                  << "Number of books:\t" << num_books_ << std::endl
                  << "*******************\n"
                  << "Need to order:\t\t" << need_to_order_ << std::endl
                  << "Total cost:\t\t$" << total_cost_ << std::endl
                  << "*******************\n";
    }

    float GetCost()
    {
        return total_cost_;
    }
};

class Books
{
private:
    std::unordered_map<int, const Book> list_;
    float running_price_ = 0;

public:
    void InsertBook(BookData data, int num_books)
    {
        if (list_.count(data.code) > 0)
        {
            throw std::invalid_argument("Book with same code already exists!");
        }

        Book new_book;
        new_book.Set(data, num_books);
        list_.insert({data.code, new_book});
        running_price_ += new_book.GetCost();
        return;
    }

    Book GetBook(int code)
    {
        if (list_.count(code) <= 0)
        {
            throw std::out_of_range("Book does not exist!");
        }
        return list_.at(code);
    }

    void DisplayBookData(int code)
    {
        if (list_.count(code) <= 0)
        {
            throw std::out_of_range("Book does not exist!");
        }

        Book book = list_.at(code);
        book.Show();
        return;
    }

    float GetRunningCost()
    {
        return running_price_;
    }
};

/*
int InsertPositiveInt(
    const std::string &prompt = "Enter positive integer:\t",
    const std::string &error = "Please enter positive integer!")
{
    int positive_integer;
    while (true)
    {
        std::cout << prompt;

        if (!(cin >> positive_integer) || positive_integer < 0)
        {
            std::cout << error << std::endl;
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    return positive_integer;
}

float InsertPositiveFloat(
    const std::string &prompt = "Enter positive float:\t",
    const std::string &error = "Please enter positive number!")
{
    float positive_float;
    while (true)
    {
        std::cout << prompt;

        if (!(cin >> positive_float) || positive_float < 0.0f)
        {
            std::cout << error << std::endl;
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    return positive_float;
}
*/

template <typename T>
T InsertPositiveNumber(
    const std::string &prompt = "Enter positive number:\t",
    const std::string &error = "Please enter positive number!")
{
    T positive_number;
    while (true)
    {
        std::cout << prompt;

        if (!(cin >> positive_number) || positive_number < 0)
        {
            std::cout << error << std::endl;
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    return positive_number;
}

char InsertCharacterChoice(
    const std::string &prompt = "Enter Y/N:\t",
    const std::string &error = "Please enter a character!")
{
    char choice;
    while (true)
    {
        std::cout << prompt;

        if (!(cin >> choice) || (choice != 'Y' && choice != 'N'))
        {
            std::cout << error << std::endl;
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    return choice;
}

void InsertBookData(BookData &data, int &num_books)
{
    std::cout << "\n-------------------------\n";
    std::cout << "Please enter the details\n";
    data.code = InsertPositiveNumber<int>("Book code:\t\t\t");
    data.cost = InsertPositiveNumber<float>("Book cost:\t\t\t");
    num_books = InsertPositiveNumber<int>("No of books available:\t\t");
    data.class_enrollment = InsertPositiveNumber<int>("Class enrollment:\t\t");
    data.required = InsertCharacterChoice("Required for class (Y/N):\t");
    data.used = InsertCharacterChoice("Used before in class(Y/N)\t");
    std::cout << "-------------------------\n";
    return;
}

int main()
{
    Books books;
    BookData data;
    int num_books;

    int choice = 1;

    do
    {
        try
        {

            InsertBookData(data, num_books);

            books.InsertBook(data, num_books);
            books.DisplayBookData(data.code);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
        choice = InsertPositiveNumber<int>("\nEnter 1 to do another book, 0 to stop:\t");
    } while (choice != 0);

    std::cout << "Total cost for all orders: $" << books.GetRunningCost() << std::endl;
    std::cout << "Profit: $" << (books.GetRunningCost() * kProfitPercentage) << std::endl;

    return 0;
}