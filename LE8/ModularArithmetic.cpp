#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

long long string_mod(const string &s, long long mod)
{
    long long res = 0;

    for (char c : s)
    {
        res = (res * 10 + (c - '0')) % mod;
    }

    return res;
}

long long binpow(long long base, long long exp)
{
    long long res = 1;

    base %= MOD;

    while (exp > 0)
    {
        if (exp & 1)
        {
            res = (res * base) % MOD;
        }

        base = (base * base) % MOD;
        exp >>= 1;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string x, y;
    char op;

    cin >> x >> op >> y;

    long long a = string_mod(x, MOD);
    long long b = string_mod(y, MOD);

    if (op == '+')
    {
        cout << (a + b) % MOD;
    }
    else if (op == '-')
    {
        cout << (a - b + MOD) % MOD;
    }
    else if (op == '*')
    {
        cout << (a * b) % MOD;
    }
    else if (op == '^')
    {
        long long exp = string_mod(y, MOD - 1);

        cout << binpow(a, exp);
    }

    return 0;
}