// database.h : Nithin
// Desc : Class for database for composer records.

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include "composer.h"

using namespace std;

const int kMaxComposers = 100;

class Database
{
public:
    Database();
    ~Database();

    // Add a new composer using operations in the Composer class
    // For convenience, we return a reference (pointer) to the new record.
    Composer &AddComposer(std::string in_first_name, std::string in_last_name, std::string in_genre, int in_yob, std::string in_fact);

    // Search for a composer based on last_name.
    // Return reference to the found record
    Composer &GetComposer(std::string in_last_name);

    // Display all composers
    void DisplayAll();

    // Display all composers by rank
    void DisplayByRank();

private:
    // Store the individual records in an array.
    Composer composers_[kMaxComposers];

    // Track the next slot in the array to place a new record.
    int next_slot_;
};

#endif