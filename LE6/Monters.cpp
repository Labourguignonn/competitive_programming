#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int n;
    vector<vector<pair<int, int>>> adj;

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
    // BFS DOS MONSTROS
    // ========================
    vector<int> bfs_monsters(vector<int> monsters)
    {
        vector<int> dist(n, -1);

        queue<int> q;

        for (int m : monsters)
        {
            dist[m] = 0;
            q.push(m);
        }

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
    // BFS DO PLAYER
    // ========================
    pair<vector<int>, vector<int>> bfs_player(int src,
                                              vector<int> &monster_dist)
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
                    int nd = dist[u] + 1;

                    if (monster_dist[v] != -1 &&
                        monster_dist[v] <= nd)
                        continue;

                    dist[v] = nd;
                    parent[v] = u;

                    q.push(v);
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

    vector<string> lab(n);

    Graph g(n * m);

    int start;

    vector<int> monsters;

    for (int i = 0; i < n; i++)
    {
        cin >> lab[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (lab[i][j] == '#')
                continue;

            int u = i * m + j;

            if (lab[i][j] == 'A')
                start = u;

            if (lab[i][j] == 'M')
                monsters.push_back(u);

            if (i != n - 1 && lab[i + 1][j] != '#')
            {
                g.add_edge(u, (i + 1) * m + j);
            }

            if (i != 0 && lab[i - 1][j] != '#')
            {
                g.add_edge(u, (i - 1) * m + j);
            }

            if (j != m - 1 && lab[i][j + 1] != '#')
            {
                g.add_edge(u, i * m + (j + 1));
            }

            if (j != 0 && lab[i][j - 1] != '#')
            {
                g.add_edge(u, i * m + (j - 1));
            }
        }
    }

    vector<int> monster_dist =
        g.bfs_monsters(monsters);


    pair<vector<int>, vector<int>> resp = g.bfs_player(start, monster_dist);

    vector<int> dist = resp.first;
    vector<int> parent = resp.second;

    int finish = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int id = i * m + j;

            if (dist[id] == -1)
                continue;

            if (i == 0 || j == 0 ||
                i == n - 1 || j == m - 1)
            {
                finish = id;
                break;
            }
        }

        if (finish != -1)
            break;
    }

    if (finish == -1)
    {
        cout << "NO" << "\n";
        return 0;
    }

    stack<char> path;

    int cur = finish;

    while (cur != start)
    {
        int p = parent[cur];

        if (cur == p + 1)
            path.push('R');

        else if (cur == p - 1)
            path.push('L');

        else if (cur == p + m)
            path.push('D');

        else if (cur == p - m)
            path.push('U');

        cur = p;
    }

    cout << "YES" << "\n";
    cout << path.size() << "\n";

    while (!path.empty())
    {
        cout << path.top();
        path.pop();
    }

    cout << "\n";

    return 0;
}
