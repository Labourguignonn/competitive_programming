#include <bits/stdc++.h>
using namespace std;

struct DFS {
    int n;
    vector<vector<int>> adj;
    vector<int> depth;

    DFS(int n) : n(n), adj(n + 1), depth(n + 1, 0) {}

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void run(int u, int p = -1) {
        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            run(v, u);
        }
    }

    // retorna o nó mais distante e a distância
    pair<int,int> farthest(int start) {
        fill(depth.begin(), depth.end(), 0);
        run(start);

        int node = start;
        for (int i = 1; i <= n; i++) {
            if (depth[i] > depth[node]) {
                node = i;
            }
        }
        return {node, depth[node]};
    }
};

int main() {
    int n;
    cin >> n;

    DFS dfs(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        dfs.add_edge(a, b);
    }

    // 1ª DFS: pega um extremo
    auto [A, _] = dfs.farthest(1);

    // 2ª DFS: pega o diâmetro
    auto [B, diameter] = dfs.farthest(A);

    cout << diameter << "\n";

    return 0;
}
