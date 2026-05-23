#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    int removable = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool redundant = false;

            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j)
                    continue;

                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    cout << -1 << '\n';
                    return 0;
                }

                if (dist[i][j] == dist[i][k] + dist[k][j])
                {
                    redundant = true;
                }
            }

            if (redundant)
                removable++;
        }
    }

    cout << removable << '\n';

    return 0;
}