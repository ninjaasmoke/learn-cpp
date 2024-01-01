// final_grade.cpp: Nithin
// Desc: a program that calculates the final grade for a course

/*
2. Write a program that will compute your final grade for a programming course you are taking. Here is the grading scheme:

Final grades will be based on the following:
40% Assignments
15% Midterm Examination
35% Final Examination
10% Class Participation Grade

Your program should ask the user for the four assignment scores, the midterm, final and section grades.
Then, the final score is calculated and printed.
To do the calculations, you average the four assignment scores together and then multiply it by 0.4 (40%).
You then multiply the midterm score by 0.15, the final by 0.35 and the participation grade by 0.1.
Then you add all the results of these multiplications together.

Use functions wherever you can in this program.
You can create a function to get the input by passing in as a parameter the string to be displayed in an explanatory cout.
Here is an example run:


Enter the score for the first assignment. 75
Enter the score for the second assignment. 85
Enter the score for the third assignment. 82
Enter the score for the fourth assignment. 94
Enter the score for the midterm. 81
Enter the score for the final. 89
Enter the score for the section grade. 100
The final grade is: 86.9

*/

/*
Author comments:

- seems tough
- start:    10:20pm
- end:      10:38pm

*/

#include <iostream>
#include <limits>

using namespace std;

const int kNumAssignments = 4;
const float kAssignmentWeight = 0.4f;
const float kMidtermWeight = 0.15f;
const float kFinalWeight = 0.35f;
const float kParticipationWeight = 0.1f;

float GetScore(const string &prompt)
{
    float input;

    do
    {
        cout << prompt;

        if (!(cin >> input) || input < 0 || input > 100)
        {
            std::cout << "Invalid input. Enter a number between 0 and 100.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return GetScore(prompt);
        }
        else
        {
            break;
        }
    } while (true);

    return input;
}

float CalculateWeightedAverage(const float scores[], float weight, int numScores)
{
    float sum = 0.0f;

    for (int i = 0; i < numScores; i++)
    {
        sum += scores[i];
    }

    return (sum / static_cast<float>(numScores)) * weight;
}

float CalculateFinalGrade(const float assignmentScores[], const float midtermScore, const float finalScore, const float participationScore)
{
    float assignmentAverage = CalculateWeightedAverage(assignmentScores, kAssignmentWeight, kNumAssignments);
    float midtermAvg = midtermScore * kMidtermWeight;
    float finalAvg = finalScore * kFinalWeight;
    float participationAvg = participationScore * kParticipationWeight;

    return assignmentAverage + midtermAvg + finalAvg + participationAvg;
}

int main()
{

    float assignmentScores[kNumAssignments];

    for (int i = 0; i < kNumAssignments; i++)
    {
        assignmentScores[i] = GetScore("Enter score for assignment " + to_string(i + 1) + ":\t");
    }

    float midtermScore = GetScore("Enter score for midterm:\t");
    float finalScore = GetScore("Enter score for final:\t");
    float classParticipationScore = GetScore("Enter score for classParticipation:\t");

    float result = CalculateFinalGrade(assignmentScores, midtermScore, finalScore, classParticipationScore);

    cout << "\nFinal result:\t" << result;

    return 0;
}
