#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int n;
    while (n--){
        
    }
    vector<pair<int, int>> stones(n);
    
    for (int i=0; i < n; i++){
        cin >> stones[i].first;
        stones[i].second = i+1;
    }
    sort(stones.begin(),stones.end());
    int h = stones[0].first;
    int st = stones[0].second;
    
    while(st != n){
        
    }



    return 0;
}