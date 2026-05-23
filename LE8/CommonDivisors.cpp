#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, mx = 0;

    cin >> n;
    vector<int> list(n);

    for (int i=0; i< n; i++){
        cin >> list[i];
        mx = max(mx, list[i]);
    }
    
    vector<int> freq(mx+1, 0);
    
    for (int x : list){
       freq[x]++;
    }

    for (int d = mx; d >= 1; d--)
    {
        int cnt = 0;

        for (int multiple = d; multiple <= mx; multiple += d)
        {
            cnt += freq[multiple];

            if (cnt >= 2)
            {
                cout << d << '\n';
                return 0;
            }
        }
    }
}