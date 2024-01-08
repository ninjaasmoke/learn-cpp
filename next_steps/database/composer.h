// composer.h : Nithin
// Desc : The class for a composer record.

/*
The default ranking is 10. This is the lowest possible rank.
*/

#ifndef COMPOSER_H
#define COMPOSER_H

#include <string>
const int kHighestRanking = 1;
const int kLowestRanking = 10;
const int kDefaultRanking = kLowestRanking;

class Composer
{

public:
    Composer();
    // This is a constructor

    ~Composer();
    // This is a deconstructor

    // Accessors and Mutators
    void set_first_name(std::string in_first_name);
    std::string first_name();
    void set_last_name(std::string in_last_name);
    std::string last_name();
    void set_composer_yob(int in_composer_yob);
    int composer_yob();
    void set_composer_genre(std::string in_composer_genre);
    std::string composer_genre();
    void set_ranking(int in_ranking);
    int ranking();
    void set_fact(std::string in_fact);
    std::string fact();

    // Methods
    // This method increases the composer's rank by increment
    void Promote(int increment);
    // This method decreases the composer's rank by decrement
    void Demote(int decrement);
    // This method displays data of the composer
    void Display();

private:
    std::string first_name_;
    std::string last_name_;
    std::string genre_;
    std::string fact_;
    int ranking_;
    int yob_;
};

#endif