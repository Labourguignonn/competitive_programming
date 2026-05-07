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
};

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string lixo;
    cin >> n;

    while (n--)
    {
        getline(cin, lixo);

        string s;
        int n_counter = 0;
        char fir;
        unordered_map<char, int> dict;
        vector<pair<char, char>> edges;
        int comp = 0;

        cin >> fir;
        cin.ignore();
        for (char c = 'A'; c <= fir; c++)
        {
                dict[c] = n_counter++;
        }
        while (getline(cin, s) && !s.empty())
        {
            char f = s[0];
            char g = s[1];
            edges.emplace_back(make_pair(f, g));

            if (!dict.count(f))
            {
                dict[f] = n_counter;
                n_counter++;
            }
            if (!dict.count(g))
            {
                dict[g] = n_counter;
                n_counter++;
            }
        }

        vector<bool> vis(dict.size(), false);
        Graph g(dict.size());
        for (int i = 0; i < edges.size(); i++)
        {
            int n1 = dict[edges[i].first];
            int n2 = dict[edges[i].second];
            g.add_edge(n1, n2);
        }
        for (int i = 0; i < g.n; i++)
        {
            if (!vis[i])
            {
                g.dfs_util(i, vis);
                comp++;
            }
        }

        cout << comp;
    }

    return 0;
}