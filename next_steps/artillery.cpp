// artillery.cpp : Nithin
// Desc: A simple game program where user input is accepted to try and kill enemies.

/*
Expected gameplay:

Welcome to Artillery.
You are in the middle of a war and being charged by thousands of enemies.
You have one cannon, which you can shoot at any angle.
You only have 10 cannonballs for this target..
Let's begin...

The enemy is 507 feet away!!!
What angle? 25<
You over shot by 445
What angle? 15
You over shot by 114
What angle? 10
You under shot by 82
What angle? 12
You under shot by 2
What angle? 12.01
You hit him!!!
It took you 4 shots.
You have killed 1 enemy.
I see another one, are you ready? (Y/N) n

You killed 1 of the enemy.
*/

/*
Additional information:

In case you are a little rusty on physics, here are the calculations:

Velocity = 200.0; // initial velocity of 200 ft/sec
Gravity = 32.2; // gravity for distance calculation

// in_angle is the angle the player has entered, converted to radians.
time_in_air = (2.0 * Velocity * sin(in_angle)) / Gravity;
distance = round((Velocity * cos(in_angle)) * time_in_air);
*/

/*
Expected code structure:

StartUp(); // This displays the introductory script.
killed = 0;
do {
  killed = Fire(); // Fire() contains the main loop of each round.
  cout << "I see another one, care to shoot again? (Y/N) " << endl;
  cin >> done;
} while (done != 'n');
cout << "You killed " << killed << " of the enemy." << endl;

*/

/*
Author comments:

-   seems pretty easy
-   start:      2:15pm 04-01-2024
-   end:        3:14pm 04-01-2024
*/

#include <iostream>
#include <limits>
#include <math.h>
#include <time.h>

using namespace std;

const float kVelocity = 200.0f;
const float kGravity = 32.2f;
const int kNumCanonBalls = 10;
const double kPiValue = 3.14159;

double GetRadiansFromDegree(double degree)
{
    return degree * kPiValue / 180;
}

double GetUserInputAngle(int enemy_dist)
{
    double user_input;

    do
    {
        std::cout << "\n---------------------------\n";
        std::cout << "The enemy is " << enemy_dist << " feet away!" << endl;
        std::cout << "What angle?: ";
        if (!(std::cin >> user_input))
        {
            cout << "Please enter a valid angle." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    } while (true);

    return user_input;
}

double CanonBallDistance(double angle)
{
    const double in_angle = GetRadiansFromDegree(angle);
    double time_in_air = (2.0 * kVelocity * sin(in_angle)) / kGravity;
    double distance = round((kVelocity * cos(in_angle)) * time_in_air);
    return distance;
}

void StartUp()
{
    cout << "Welcome to Artillery." << endl;
    cout << "You are in the middle of a war and being charged by thousands of enemies." << endl;
    cout << "You have one cannon, which you can shoot at any angle." << endl;
    cout << "You only have " << kNumCanonBalls << " cannonballs for this target.." << endl;
    cout << "Let's begin..." << endl;
    return;
}

int Fire(int chances)
{
    srand((unsigned)time(NULL)); // set a seed for the random generator

    int killed = 0;

    int enemy_dist = rand() % 1000 + 1; // generate a random value between 1 and 1000
    double user_input;
    double canon_ball_dist;
    double canon_hit_enemy;

    do
    {
        if (chances-- <= 0)
        {
            std::cout << "\nYou ran out of canon balls! :')\n"
                      << endl;
            std::cout << "\n---------------------------\n";
            return killed;
        }

        user_input = GetUserInputAngle(enemy_dist);
        canon_ball_dist = CanonBallDistance(user_input);

        canon_hit_enemy = enemy_dist - canon_ball_dist;

        if (canon_hit_enemy < 0.0)
        {
            std::cout << "\nYou over shot by " << (canon_hit_enemy * -1.0) << " feet." << std::endl;
            continue;
        }
        else if (canon_hit_enemy > 0.0)
        {
            std::cout << "\nYou under shot by " << canon_hit_enemy << " feet." << std::endl;
            continue;
        }
    } while (canon_hit_enemy != 0.0);

    killed += 1;

    std::cout << "\nYou hit him!!" << std::endl;
    std::cout << "It took you " << (kNumCanonBalls - chances) << " shots." << std::endl;
    std::cout << "\n---------------------------\n";

    return killed;
}

int main()
{
    StartUp();

    int killed = 0;
    int canon_balls = kNumCanonBalls;
    std::string choice;

    do
    {
        killed += Fire(canon_balls);
        std::cout << "\nI see another one, care to shoot again? (Y/N): ";
        std::cin >> choice;
    } while (choice != "N");

    std::cout << "\nYou killed " << killed << " of the enemy!\n";
    return 0;
}
