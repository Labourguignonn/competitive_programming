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
        else if (oddFields.size() == 1)
        {
            cout << evenNumberSum + oddFields[0] << "\n";
        }
        else
        {

            sort(oddFields.begin(), oddFields.end(), greater<int>());

            if (oddFields.size() % 2 == 0)
            {
                for (int n = 0; n < (oddFields.size() / 2); n++)
                {
                    sumOfDandelions += oddFields[n];
                }
                if (evenNumberSum > oddFields[oddFields.size() - 1])
                {
                    sumOfDandelions += evenNumberSum;
                }
                else
                {
                    sumOfDandelions += oddFields[oddFields.size() - 1];
                }
            }
            else
            {
                for (int n = 0; n < (ceil(oddFields.size()) / 2); n++)
                {
                    sumOfDandelions += oddFields[n];
                }
                sumOfDandelions += evenNumberSum;
            }

            cout << sumOfDandelions << "\n";
        }
    }

    return 0;
}