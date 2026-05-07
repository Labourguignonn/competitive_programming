#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int n;
    vector<vector<pair<int, int>>> adj;

    Graph(int n) : n(n)
    {
        adj.resize(n);
    }

    void add_edge(int u, int v, int w = 1, bool undirected = false)
    {
        adj[u].push_back({v, w});
        if (undirected)
            adj[v].push_back({u, w});
    }

    vector<int> bfs(int src)
    {
        vector<int> dist(n, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto [v, _] : adj[u])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return dist;
    }
};

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ch_size = n*n;

    Graph g(ch_size);

    for (int i = 0; i < ch_size; i++)
    {
        g.add_edge(i, (i - 1 + 32768) % 32768);
        if (i % 2 == 0)
        {
            g.add_edge(i, i / 2);
            g.add_edge(i, i / 2 + 16384);
        }
    }

    vector<int> dists = g.bfs(0);
    while (n--)
    {
        int m;
        cin >> m;
        cout << dists[m] << " ";
    }

    return 0;
}