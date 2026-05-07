#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int n;
    vector<vector<int>> adj;

    Graph(int n) : n(n)
    {
        adj.resize(n);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
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

            for (int v : adj[u])
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

    int total = n * n;
    Graph g(total);

    vector<pair<int,int>> moves = {
        {2,1}, {2,-1}, {-2,1}, {-2,-1},
        {1,2}, {1,-2}, {-1,2}, {-1,-2}
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int u = i * n + j;

            for (auto [dx, dy] : moves)
            {
                int ni = i + dx;
                int nj = j + dy;

                if (ni >= 0 && ni < n && nj >= 0 && nj < n)
                {
                    int v = ni * n + nj;
                    g.add_edge(u, v);
                }
            }
        }
    }

    vector<int> dist = g.bfs(0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i * n + j] << " ";
        }
        cout << "\n";
    }

    return 0;
}