#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> stones(n);
    int c_stone;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
    }
    c_stone = n - 1;

    while (c_stone != 0)
    {
        long long diff = LONG_LONG_MAX;
        int pos = max(0, c_stone - k);
        int final_pos = c_stone;
        
        for (int u = final_pos - 1; u >= pos; u--)
        {
            long long ac_diff = abs(stones[final_pos] - stones[u]);

            if (ac_diff < diff)
            {
                diff = ac_diff;
                c_stone = u;
            }
        }

        sum += diff;
    }

    cout << sum;

    return 0;
}