#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numberPlayer, initialPoints, numberAnswers, answer, finalScore;

    cin >> numberPlayer >> initialPoints >> numberAnswers;
    vector<int> correctAnswers(numberPlayer, 0);

    for (int i = 0; i < numberAnswers; i++)
    {
        cin >> answer;
        correctAnswers[answer-1]++;
    }

    for (int j = 0; j < numberPlayer; j++)
    {
        finalScore = initialPoints - (numberAnswers - correctAnswers[j]);
        if (finalScore > 0)
        {
            cout << "Yes" << "\n";
        }
        else
        {
            cout << "No" << "\n";
        }
    }

    return 0;
}