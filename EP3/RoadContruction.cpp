#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> sz;
    int max_size;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        max_size = 1;

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
        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        max_size = max(max_size, sz[a]);
    }
};


int main(){
    int n, m;
    cin >> n >> m;

    DSU dsu(n + 1);

    for (int i = 0; i < m; i++){
        int c1, c2;
        cin >> c1 >> c2;

        if (dsu.find(c1) != dsu.find(c2)){
            dsu.unite(c1,c2);           
            n--;
        }
        else {
         dsu.unite(c1,c2);
        }
        cout << n << " " << dsu.max_size << "\n";
    }


    return 0;
}