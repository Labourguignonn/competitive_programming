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
    int n, m, incov = 0;
    vector<pair<int,int>> b_orders(m);
    cin >> n >> m;

    DSU dsu(n);

    for (int i =0; i< m; i++){
        int i1, i2;
        cin >> i1 >> i2;
        dsu.unite(i1, i2);

        b_orders.push_back(make_pair(i1,i2));
    }

    for (int j=0; j < m; j++){
        
    }

    return 0;
}