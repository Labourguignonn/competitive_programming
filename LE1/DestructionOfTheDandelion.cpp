#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        int numberFields, field;
        long long sumOfDandelions = 0, evenNumberSum = 0;
        vector<int> oddFields;

        cin >> numberFields;

        for (int j = 0; j < numberFields; j++)
        {
            cin >> field;
            if (field % 2 == 0)
            {
                evenNumberSum += field;
            }
            else
            {
                oddFields.push_back(field);
            }
        }
        if (oddFields.size() == 0)
        {
            cout << 0 << "\n";
        }
        else
        {

            sort(oddFields.begin(), oddFields.end());

            int half = oddFields.size() / 2;
            for (int n = half; n < oddFields.size(); n++)
            {
                sumOfDandelions += oddFields[n];
            }

            sumOfDandelions += evenNumberSum;
            cout << sumOfDandelions << "\n";
        }
    }

    return 0;
}