#include <bits/stdc++.h>
using namespace std;
int max_waters;
vector<int> aq;
int n, h = 0;
long long corals, w;

int compute_w(long long h){
    long long corals = 0;

    for (int i=0; i < n; i++){
            corals += min((long long)aq[i], h);
    }
    w = (h * n) - corals;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        w = 0;
        cin >> n >> max_waters;       
        aq.resize(n);
        for (int i = 0; i < n ; i++){
            cin >> aq[i];
        }
         long long l = 0, r = 1e9;
        long long ans = r;

        while (l <= r) {
            long long mid = (l + r) / 2;

            long long w = compute_w(mid);

            if (w >= max_waters) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}