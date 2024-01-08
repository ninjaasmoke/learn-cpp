// database.cpp : Nithin
// Desc : a program that uses the database class and created methods for it

#include "database.h"
#include "composer.h"

Database::Database() : next_slot_(0) {}

Database::~Database() {}

Composer &Database::AddComposer(std::string in_first_name, std::string in_last_name, std::string in_genre, int in_yob, std::string in_fact)
{
    if (next_slot_ < kMaxComposers)
    {
        composers_[next_slot_].set_first_name(in_first_name);
        composers_[next_slot_].set_last_name(in_last_name);
        composers_[next_slot_].set_composer_genre(in_genre);
        composers_[next_slot_].set_composer_yob(in_yob);
        composers_[next_slot_].set_fact(in_fact);

        return composers_[next_slot_++];
    }
    else
    {
        std::cerr << "Error: Database is full. Cannot add more composers." << endl;
        // Returning a reference to the first composer in case of an error.
        return composers_[0];
    }
}

Composer &Database::GetComposer(std::string in_last_name)
{
    for (int i = 0; i < next_slot_; ++i)
    {
        if (composers_[i].last_name() == in_last_name)
        {
            // Return a reference to the found composer
            return composers_[i];
        }
    }

    // Handle the case where the composer is not found
    cerr << "Error: Composer not found." << endl;
    // Returning a reference to the first composer in case of an error.
    return composers_[0];
}

// Display all composers
void Database::DisplayAll()
{
    for (int i = 0; i < next_slot_; i++)
    {
        composers_[i].Display();
    }
}

// Display all composers by rank
void Database::DisplayByRank()
{
    const int size = next_slot_;

    // Copy composers_ to a new array
    Composer *composers = new Composer[size];
    for (int i = 0; i < size; ++i)
    {
        composers[i] = composers_[i];
    }

    // Bubble Sort
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (composers[j].ranking() > composers[j + 1].ranking())
            {
                std::swap(composers[j], composers[j + 1]);
            }
        }
    }

    // Display sorted composers
    for (int i = 0; i < size; ++i)
    {
        composers[i].Display();
    }

    // Clean up dynamically allocated memory
    delete[] composers;
}
