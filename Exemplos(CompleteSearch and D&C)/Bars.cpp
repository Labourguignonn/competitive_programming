#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int sum, int target, vector<int>& bars) {
    if (sum == target) return true;

    if (i == bars.size() || sum > target) return false;

    return solve(i + 1, sum + bars[i], target, bars) ||
           solve(i + 1, sum, target, bars);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, p;
        cin >> n >> p;

        vector<int> bars(p);
        for (int i = 0; i < p; i++) cin >> bars[i];

        bool ok = solve(0, 0, n, bars);

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
