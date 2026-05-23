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
    void add_edge(int u, int v, int w = 1, bool undirected = false)
    {
        adj[u].push_back({v, w});
        if (undirected)
            adj[v].push_back({u, w});
    }

    // ========================
    // DIJKSTRA
    // ========================
    vector<long long> dijkstra(int src)
    {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

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
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

pair<int, int> edge(int u, int v)
{
    return {min(u, v), max(u, v)};
}

int id(int r, int c)
{
    return (r - 1) * 6 + (c - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    Graph g(n);

    for(int i = 0; i < m; i++){
        int a, b, c;

        cin >> a >> b >> c;
        g.add_edge(a-1, b-1, c);
    }

    vector<long long> dist = g.dijkstra(0);

    for (int j = 0; j < n; j++){
        cout << dist[j] << " ";
    }

    return 0;
}