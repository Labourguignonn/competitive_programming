#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }

    sort(a.begin(), a.end());

    long long l = 0, r = 1e18, ans = -1;

    while (l <= r) {
        long long x = (l + r) / 2;

        long long new_sum = sum + x;

        long long count = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] * 2 * n < new_sum) count++;
        }

        if (count > n / 2) {
            ans = x;
            r = x - 1;
        } else {
            l = x + 1;
        }
    }

    cout << ans << endl;
}
