// composer.cpp : Nithin
// Desc : a program that uses the composer class and created methods for it

#include <iostream>
#include "composer.h"

Composer::Composer() : ranking_(kDefaultRanking)
{
}

Composer::~Composer() {}

// Accessors and mutators
void Composer::set_first_name(std::string in_first_name)
{
    first_name_ = in_first_name;
    return;
}

std::string Composer::first_name()
{
    return first_name_;
}

void Composer::set_last_name(std::string in_last_name)
{
    last_name_ = in_last_name;
}

std::string Composer::last_name()
{
    return last_name_;
}

void Composer::set_composer_yob(int in_composer_yob)
{
    yob_ = in_composer_yob;
}

int Composer::composer_yob()
{
    return yob_;
}

void Composer::set_composer_genre(std::string in_composer_genre)
{
    genre_ = in_composer_genre;
}

std::string Composer::composer_genre()
{
    return genre_;
}

void Composer::set_ranking(int in_ranking)
{
    ranking_ = in_ranking;
}

int Composer::ranking()
{
    return ranking_;
}

void Composer::set_fact(std::string in_fact)
{
    fact_ = in_fact;
}

std::string Composer::fact()
{
    return fact_;
}

// Methods
void Composer::Promote(int increment)
{
    ranking_ -= increment;
    if (ranking_ <= 0)
    {
        ranking_ = kHighestRanking;
    }
}

void Composer::Demote(int decrement)
{
    ranking_ += decrement;
    if (ranking_ >= 10)
    {
        ranking_ = kLowestRanking;
    }
}

void Composer::Display()
{
    std::cout << "Composer: " << first_name_ << " " << last_name_ << std::endl;
    std::cout << "Year of Birth: " << yob_ << std::endl;
    std::cout << "Genre: " << genre_ << std::endl;
    std::cout << "Ranking: " << ranking_ << std::endl;
    std::cout << "Fact: " << fact_ << std::endl;
    std::cout << "------------------------" << std::endl;
}