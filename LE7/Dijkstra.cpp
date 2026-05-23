#include <bits/stdc++.h>
using namespace std;
struct Graph
{
    int n;
    vector<vector<pair<int, int>>> adj; // (vizinho, peso)

    // ========================
    // CONSTRUTOR
    // ========================
    Graph(int n) : n(n)
    {
        adj.resize(n);
    }

    // ========================
    // ADICIONAR ARESTA
    // ========================
    void add_edge(int u, int v, int w = 1, bool undirected = true)
    {
        adj[u].push_back({v, w});
        if (undirected)
            adj[v].push_back({u, w});
    }

    // ========================
    // DIJKSTRA
    // ========================
    pair<vector<long long>, vector<int>> dijkstra(int src)
    {
        vector<long long> dist(n, LLONG_MAX);
        vector<int> parent(n, -1);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<>>
            pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto [v, w] : adj[u])
            {
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;

                    // registra de onde veio
                    parent[v] = u;

                    pq.push({dist[v], v});
                }
            }
        }

        return {dist, parent};
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g.add_edge(a, b, c);
    }

    auto [dist, parent] = g.dijkstra(0);

    if (dist[n - 1] == LLONG_MAX)
    {
        cout << -1;
        return 0;
    }

    vector<int> path;

    for (int v = n - 1; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    for (int j = 0; j < path.size(); j++)
    {
        cout << path[j] + 1 << " ";
    }

    return 0;
}