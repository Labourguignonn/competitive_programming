#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int low = 1, high = n;
        vector<int> ans(n);

        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '<') {
                ans[i + 1] = low++;
            } else {
                ans[i + 1] = high--;
            }
        }

        ans[0] = low; 

        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
