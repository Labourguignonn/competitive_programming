#include <bits/stdc++.h>
using namespace std;

long long modpow(long long x, long long y, long long mod)
{
    long long res = 1;

    x %= mod;

    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % mod;
        }

        x = (x * x) % mod;

        y >>= 1;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    while (c--)
    {
        long long x, y, n;
        cin >> x >> y >> n;

        cout << modpow(x, y, n) << '\n';
    }

    return 0;
}