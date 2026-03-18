#include <bits/stdc++.h>
using namespace std;

int binarySearchIterative(const vector<int> &numbers, int query)
{
    int low = 0, high = numbers.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (numbers[mid] == query)
            return mid;
        else if (numbers[mid] < query)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arraySize, numQueries;
    cin >> arraySize >> numQueries;

    int query;
    vector<int> numbers(arraySize);


    for (int i = 0; i < arraySize; i++)
    {
        cin >> numbers[i];
    }

    for (int j = 0; j < numQueries; j++)
    {
        cin >> query;
        int pos = binarySearchIterative(numbers, query);
        cout << pos << "\n";
    }

    return 0;
}
