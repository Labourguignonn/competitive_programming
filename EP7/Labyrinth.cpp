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
    pair<vector<int>, vector<int>> bfs(int src)
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

        return {dist, parent};
    }
};

pair<int, int> edge(int u, int v)
{
    return {min(u, v), max(u, v)};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s, f;
    cin >> n >> m;
    set<int> walls;
    vector<string> lab(n);

    Graph g(n * m);

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> lab[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (lab[i][j] == '#')
                continue;

            if (lab[i][j] == 'A')
                s = i * m + j;

            if (lab[i][j] == 'B')
                f = i * m + j;

            // baixo
            if (i != n - 1)
            {
                if (lab[i + 1][j] != '#')
                {
                    g.add_edge(i * m + j, (i + 1) * m + j);
                }
            }

            // cima
            if (i != 0)
            {
                if (lab[i - 1][j] != '#')
                {
                    g.add_edge(i * m + j, (i - 1) * m + j);
                }
            }

            // direita
            if (j != m - 1)
            {
                if (lab[i][j + 1] != '#')
                {
                    g.add_edge(i * m + j, i * m + (j + 1));
                }
            }

            // esquerda
            if (j != 0)
            {
                if (lab[i][j - 1] != '#')
                {
                    g.add_edge(i * m + j, i * m + (j - 1));
                }
            }
        }
    }

    pair<vector<int>, vector<int>> resp = g.bfs(s);
    stack<char> fin_print;

    int cur = f;
    int start = s;
    vector<int> dist = resp.first;
    vector<int> parent = resp.second;

    int f_dist = dist[f];
    if (f_dist == -1)
    {
        cout << "NO" << "\n";
    }
    else
    {
        cout << "YES" << "\n";
        cout << f_dist << "\n";
        while (cur != start)
        {
            int p = parent[cur];

            if (cur == p + 1)
                fin_print.push('R');

            else if (cur == p - 1)
                fin_print.push('L');

            else if (cur == p + m)
                fin_print.push('D');

            else if (cur == p - m)
                fin_print.push('U');

            cur = p;
        }

        while (!fin_print.empty())
        {
            cout << fin_print.top();
            fin_print.pop();
        }
    }

    return 0;
}