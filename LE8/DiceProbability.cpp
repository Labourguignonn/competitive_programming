#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1, 0));

    dp[0][0] = 1.0;

    for (int i = 1; i <= n; i++)
    {
        for (int sum = 1; sum <= 6 * n; sum++)
        {
            for (int dice = 1; dice <= 6; dice++)
            {
                if (sum - dice >= 0)
                {
                    dp[i][sum] += dp[i - 1][sum - dice] / 6.0;
                }
            }
        }
    }

    double ans = 0;

    for (int s = a; s <= b; s++)
    {
        ans += dp[n][s];
    }

    cout << fixed << setprecision(6) << ans << '\n';

    return 0;
}