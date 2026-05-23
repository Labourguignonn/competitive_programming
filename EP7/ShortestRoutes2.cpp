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

    // =================================
    // FLOYD-WARSHALL (APSP) / N ~= 500
    // =================================
    vector<vector<long long>> floyd_warshall()
    {
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dist(n, vector<long long>(n, INF));

        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        for (int u = 0; u < n; u++)
        {
            for (auto [v, w] : adj[u])
            {
                dist[u][v] = min(dist[u][v], (long long)w);
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                    {
                        dist[i][j] = min(dist[i][j],
                                         dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        return dist;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;

    cin >> n >> m >> q;

    Graph g(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        g.add_edge(a - 1, b - 1, c);
    }

    vector<vector<long long>> dist = g.floyd_warshall();

    for (int j = 0; j < q; j++)
    {
        int x, y;
        cin >> x >> y;

        if (dist[x - 1][y - 1] == LLONG_MAX / 4)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << dist[x - 1][y - 1] << "\n";
        }
    }

    return 0;
}