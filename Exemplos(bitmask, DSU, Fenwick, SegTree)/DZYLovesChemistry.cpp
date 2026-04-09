#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b)
            parent[b] = a;
    }
};

int main(){
    int n, m;
    long long danger = 1;
    cin >> n >> m;

    DSU dsu(n); 
    int a, b;
    
    for(int i=0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        dsu.unite(a, b);
    }
    set<int> comp;
    
    for(int j=0; j < n; j++){
        comp.insert(dsu.find(j));
    }

    for (int k = 0; k < n-comp.size(); k++){

        danger *= 2;
    }

    cout << danger;

    return 0;
}