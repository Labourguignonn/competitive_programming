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
    // BFS (menor caminho sem peso)
    // ========================
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

    // ========================
    // DFS
    // ========================
    void dfs_util(int u, vector<bool> &vis)
    {
        vis[u] = true;
        for (auto [v, _] : adj[u])
        {
            if (!vis[v])
                dfs_util(v, vis);
        }
    }

    void dfs_block(int u, int blocked, vector<bool> &vis)
    {
        if (u == blocked)
            return;
        vis[u] = true;
        for (auto [v, _] : adj[u])
        {
            if (!vis[v])
                dfs_block(v, blocked, vis);
        }
    }

    vector<bool> dfs(int src)
    {
        vector<bool> vis(n, false);
        dfs_util(src, vis);
        return vis;
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

    // ========================
    // KRUSKAL (MST)
    // ========================
    struct Edge
    {
        int u, v, w;
    };

    struct DSU
    {
        vector<int> parent, rank;

        DSU(int n)
        {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x)
        {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int a, int b)
        {
            a = find(a);
            b = find(b);
            if (a == b)
                return false;

            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;

            return true;
        }
    };

    int kruskal()
    {
        vector<Edge> edges;

        // converter adj -> lista de arestas
        for (int u = 0; u < n; u++)
        {
            for (auto [v, w] : adj[u])
            {
                if (u < v)
                { // evita duplicar
                    edges.push_back({u, v, w});
                }
            }
        }

        sort(edges.begin(), edges.end(), [](Edge a, Edge b)
             { return a.w < b.w; });

        DSU dsu(n);
        int mst_cost = 0;

        for (auto e : edges)
        {
            if (dsu.unite(e.u, e.v))
            {
                mst_cost += e.w;
            }
        }

        return mst_cost;
    }
};

void format_output(int n)
{
    cout << "+";
    for (int h = 0; h < (2 * n - 1); h++)
    {
        cout << "-";
    }
    cout << "+" << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while(cin >> n >> m);

    return 0;
}