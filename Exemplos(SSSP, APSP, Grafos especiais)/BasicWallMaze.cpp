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
    // BFS (menor caminho sem peso)
    // ========================
    vector<int> bfs(int src)
    {
        vector<int> parent(n, -1);
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
                    parent[v] = u;

                    q.push(v);
                }
            }
        }

        return parent;
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

    int sc, sr, ec, er;

    cin >> sc >> sr;

    while (sc != 0 || sr != 0)
    {
        cin >> ec >> er;
        set<pair<int, int>> walls;

        for (int i = 0; i < 3; i++)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;

            // parede vertical
            if (a == c)
            {
                for (int y = b; y < d; y++)
                {
                    int left = id(y + 1, a);
                    int right = id(y + 1, a + 1);

                    walls.insert(edge(left, right));
                }
            }

            // parede horizontal
            else
            {
                for (int x = a; x < c; x++)
                {
                    int up = id(b, x + 1);
                    int down = id(b + 1, x + 1);

                    walls.insert(edge(up, down));
                }
            }
        }

        Graph g(36);

        for (int i = 0; i < 36; i++)
        {
            int row = i / 6;
            int col = i % 6;

            // baixo
            if (row + 1 < 6)
            {
                int v = i + 6;

                if (!walls.count(edge(i, v)))
                {
                    g.add_edge(i, v);
                }
            }

            // cima
            if (row - 1 >= 0)
            {
                int v = i - 6;

                if (!walls.count(edge(i, v)))
                {
                    g.add_edge(i, v);
                }
            }

            // direita
            if (col + 1 < 6)
            {
                int v = i + 1;

                if (!walls.count(edge(i, v)))
                {
                    g.add_edge(i, v);
                }
            }

            // esquerda
            if (col - 1 >= 0)
            {
                int v = i - 1;

                if (!walls.count(edge(i, v)))
                {
                    g.add_edge(i, v);
                }
            }
        }

        vector<int> parent = g.bfs(id(sr, sc));
        stack<char> fin_print;

        int cur = id(er, ec);
        int start = id(sr, sc);

        while (cur != start)
        {
            int p = parent[cur];

            if (cur == p + 1)
                fin_print.push('E');

            else if (cur == p - 1)
                fin_print.push('W');

            else if (cur == p + 6)
                fin_print.push('S');

            else if (cur == p - 6)
                fin_print.push('N');

            cur = p;
        }

        while (!fin_print.empty())
        {
            cout << fin_print.top();
            fin_print.pop();
        }

        cout << "\n";

        cin >> sc >> sr;
    }

    return 0;
}