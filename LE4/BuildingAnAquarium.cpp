#include <bits/stdc++.h>
using namespace std;

vector<int> aq;
int n;
long long max_waters;

long long compute_w(long long h){
    long long corals = 0;

    for (int i = 0; i < n; i++){
        corals += min((long long)aq[i], h);
    }

    return h * (long long)n - corals;
}

int main(){
    int t;
    cin >> t;

    while (t--){
        cin >> n >> max_waters;
        aq.resize(n);

        for (int i = 0; i < n; i++){
            cin >> aq[i];
        }

        long long l = 1, r = 2e9;
        long long ans = 0;

        while (l <= r){
            long long mid = (l + r) / 2;

            if (compute_w(mid) <= max_waters){
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
