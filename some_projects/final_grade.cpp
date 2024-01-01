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

- seems ez
- start: 9:50pm

*/

#include <iostream>
#include <limits>

using namespace std;

const int max_stream_limit = numeric_limits<streamsize>::max();

float GetScores(string display_string)
{
    cout << display_string;

    float input;

    if (!(cin >> input))
    {
        cout << "Enter a number!\n"
             << endl;
        cin.clear();
        cin.ignore(max_stream_limit, '\n');
        return GetScores(display_string);
    }
    else if (input > 100)
    {
        cout << "The score can't be higher than 100!\n"
             << endl;
        cin.clear();
        cin.ignore(max_stream_limit, '\n');
        return GetScores(display_string);
    }

    return input;
}

int main()
{
    const float kFirstAssignmentScore = GetScores("Enter first assignment score:\t");
    const float kSecondAssignmentScore = GetScores("Enter second assignment score:\t");
    const float kThirdAssignmentScore = GetScores("Enter third assignment score:\t");
    const float kFourthAssignmentScore = GetScores("Enter fourth assignment score:\t");
    const float kMidtermScore = GetScores("Enter midterm score:\t\t");
    const float kFinalScore = GetScores("Enter final score:\t\t");
    const float kSectionGrade = GetScores("Enter section grade:\t\t");

    const float kAssignmentScoreAvg = (kFirstAssignmentScore + kSecondAssignmentScore + kThirdAssignmentScore + kFourthAssignmentScore) / 4.0f * 0.4f;

    const float kMidtermScoreAvg = kMidtermScore * 0.15f;

    const float kFinalScoreAvg = kFinalScore * 0.35f;

    const float kSectionGradeAvg = kSectionGrade * 0.1f;

    const float kFinalGrade = kAssignmentScoreAvg + kMidtermScoreAvg + kFinalScoreAvg + kSectionGradeAvg;

    cout << "Final Grade:\t\t\t" << kFinalGrade;

    return 0;
}