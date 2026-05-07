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
            {
                dfs_util(v, vis);
            }
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

        // ========================
    // BELLMAN-FORD
    // ========================
    pair<vector<long long>, bool> bellman_ford(int src)
    {
        vector<long long> dist(n, LLONG_MAX);

        dist[src] = 0;

        // relaxa arestas n-1 vezes
        for (int i = 0; i < n - 1; i++)
        {
            bool updated = false;

            for (int u = 0; u < n; u++)
            {
                if (dist[u] == LLONG_MAX)
                    continue;

                for (auto [v, w] : adj[u])
                {
                    if (dist[v] > dist[u] + w)
                    {
                        dist[v] = dist[u] + w;
                        updated = true;
                    }
                }
            }

            // otimização
            if (!updated)
                break;
        }

        // detectar ciclo negativo
        bool has_negative_cycle = false;

        for (int u = 0; u < n; u++)
        {
            if (dist[u] == LLONG_MAX)
                continue;

            for (auto [v, w] : adj[u])
            {
                if (dist[v] > dist[u] + w)
                {
                    has_negative_cycle = true;
                }
            }
        }

        return {dist, has_negative_cycle};
    }

    // =================================
    // FLOYD-WARSHALL (APSP) / N ~= 500
    // =================================
    vector<vector<long long>> floyd_warshall()
    {
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dist(n, vector<long long>(n, INF));

        // distância para si mesmo
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        // arestas do grafo
        for (int u = 0; u < n; u++)
        {
            for (auto [v, w] : adj[u])
            {
                dist[u][v] = min(dist[u][v], (long long)w);
            }
        }

        // algoritmo principal
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

    // ========================
    // ALL-PAIRS DIJKSTRA (APSP)
    // ========================
    vector<vector<long long>> all_pairs_dijkstra()
    {
        vector<vector<long long>> all_dist(n);

        for (int i = 0; i < n; i++)
        {
            all_dist[i] = dijkstra(i);
        }

        return all_dist;
    }
};
