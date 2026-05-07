#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        vector<int> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1;
            
            int next = i + 1 + a[i];
            if (next <= n) {
                dp[i] = min(dp[i], dp[next]);
            }
        }
        
        cout << dp[0] << "\n";
    }
    
    return 0;
}