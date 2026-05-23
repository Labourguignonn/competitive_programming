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

    void add_edge(int u, int v, bool undirected = false)
    {
        adj[u].push_back(v);

        if (undirected)
            adj[v].push_back(u);
    }

    vector<int> bfs(int src)
    {
        vector<int> vis(n, 0);
        queue<int> q;

        vis[src] = 1;
        q.push(src);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return vis;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> grid(H);

    for (int i = 0; i < H; i++)
        cin >> grid[i];

    string snuke = "snuke";

    auto next_char = [&](char c)
    {
        for (int i = 0; i < 5; i++)
        {
            if (snuke[i] == c)
                return snuke[(i + 1) % 5];
        }

        return '?';
    };

    if (grid[0][0] != 's')
    {
        cout << "No\n";
        return 0;
    }

    int total = H * W;

    Graph g(total);

    auto id = [&](int r, int c)
    {
        return r * W + c;
    };

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int r = 0; r < H; r++)
    {
        for (int c = 0; c < W; c++)
        {
            for (int k = 0; k < 4; k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= H || nc < 0 || nc >= W)
                    continue;

                if (grid[nr][nc] == next_char(grid[r][c]))
                {
                    g.add_edge(id(r, c), id(nr, nc));
                }
            }
        }
    }

    vector<int> vis = g.bfs(0);

    if (vis[id(H - 1, W - 1)])
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}