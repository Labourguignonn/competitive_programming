#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int n, d, r;
    
    while (cin >> n >> d >> r && (n != 0 || d != 0 || r != 0)) {
        long long tot_money = 0;
        vector<int> m_roads(n);
        vector<int> e_roads(n);
        for (int i = 0; i < n; i++) cin >> m_roads[i];
        for (int j = 0; j < n; j++) cin >> e_roads[j];

        sort(m_roads.begin(), m_roads.end());
        sort(e_roads.rbegin(), e_roads.rend());

        for(int x=0; x < n; x++){
            int sum = 0;
            
            sum += m_roads[x] + e_roads[x];
            if (sum > d){
                tot_money += (sum - d) * r;
            }
        }

        cout << tot_money << "\n";
    }

    return 0;
}