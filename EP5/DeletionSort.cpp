#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        bool is_sorted = true;
        int s;
        cin >> s;
        vector<int> numbers(s);

        for (int i = 0; i < s; i++)
        {
            cin >> numbers[i];
        }
        if (s == 1)
        {
            cout << 1 << "\n";
        }
        else
        {

            for (int j = 0; j < s - 1; j++)
            {
                int x = numbers[j + 1];
                int y = numbers[j];
                if (x < y)
                {
                    is_sorted = false;
                    break;
                }
            }
            if (is_sorted)
            {
                cout << s << "\n";
            }
            else
            {
                cout << 1 << "\n";
            }
        }
    }

    return 0;
}