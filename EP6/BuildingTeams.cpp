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

    void add_edge(int u, int v, int w = 1, bool undirected = true)
    {
        adj[u].push_back({v, w});
        if (undirected)
            adj[v].push_back({u, w});
    }

    bool color_dfs(int u, int color, vector<int> &team)
    {
        team[u] = color;
        for (auto [v, _] : adj[u]){
            if (team[v] == 0)
            {
                if (!color_dfs(v, 3 - color, team))
                    return false;
            }
            else if (team[v] == color)
            {
                return false;
            }
        }
        return true;
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
    cin >> n >> m;

    Graph g(n);

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        g.add_edge(x - 1, y - 1);
    }

    vector<int> team(n, 0);
    bool is_impossible = false;

    for (int i = 0; i < n; i++)
    {
        if (team[i] == 0)
        {
            if (!g.color_dfs(i, 1, team))
            {
                is_impossible = true;
                break;
            }
        }
    }
    if (!is_impossible)
    {
        for (int i = 0; i < n; i++)
        {
            cout << team[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}