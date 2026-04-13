#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Returns the decrease in inconvenience when merging a and b.
    // If already same component, returns 0.
    long long unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return 0;
        long long delta = (long long)sz[a] * sz[b];
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return delta;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> A(m), B(m);
    for (int i = 0; i < m; i++)
        cin >> A[i] >> B[i];

    // Process bridges in reverse: add them one by one
    // Start state: all bridges collapsed → every island is isolated
    // Inconvenience = C(n,2) = n*(n-1)/2
    DSU dsu(n + 1);
    long long incov = (long long)n * (n - 1) / 2;

    vector<long long> ans(m);

    for (int i = m - 1; i >= 0; i--) {
        ans[i] = incov;
        incov -= dsu.unite(A[i], B[i]);
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";

    return 0;
}