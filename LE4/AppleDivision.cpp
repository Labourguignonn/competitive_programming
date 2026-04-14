#include <bits/stdc++.h>
using namespace std;

long long best = LONG_LONG_MAX;
long long tot_sum;
vector<int> apples;

void solve(int i, long long sum) {
    if (i == apples.size()){
        long long diff = abs(tot_sum - 2 * sum);
        best = min(diff, best);
        return;
    }

    solve(i + 1, sum + apples[i]);
    solve(i + 1, sum);
}

int main() {
    
    int n;
    cin >> n;

    apples.resize(n);
    for (int i = 0; i < n; i++){
        cin >> apples[i];
        tot_sum += apples[i];
    }

    solve(0, 0);
    cout << best;
    
    return 0;
}
