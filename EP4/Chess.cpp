#include <bits/stdc++.h>
using namespace std;

long long ways = 0;
bool col[8], diag1[15], diag2[15];
vector<string> chess(8);

void solve(int r)
{
    if (r == 8)
    {
        ways++;
        return;
    }

    for (int c = 0; c < 8; c++)
    {
        if (chess[r][c] == '*')
            continue;

        if (col[c] || diag1[r - c + 7] || diag2[r + c])
            continue;

        col[c] = diag1[r - c + 7] = diag2[r + c] = true;

        solve(r + 1);

        col[c] = diag1[r - c + 7] = diag2[r + c] = diag2[r + c] = false;
    }
}

int main()
{

    for (int i = 0; i < 8; i++)
    {
        cin >> chess[i];
    }

    solve(0);

    cout << ways << "\n";

    return 0;
}