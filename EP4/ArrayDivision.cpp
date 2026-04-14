#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    long long sum = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }

    long long l = mx, r = sum, ans = sum;

    while (l <= r) {
        long long mid = (l + r) / 2;

        int parts = 1;
        long long cur = 0;

        for (int i = 0; i < n; i++) {
            if (cur + a[i] > mid) {
                parts++;
                cur = 0;
            }
            cur += a[i];
        }

        if (parts <= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;
}
