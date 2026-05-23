#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    long long limit;

    Graph(long long limit) : limit(limit) {}

    pair<unordered_map<long long, long long>,
         unordered_map<long long, long long>>
    bfs(long long src)
    {
        unordered_map<long long, long long> dist;
        unordered_map<long long, long long> parent;

        queue<long long> q;

        dist[src] = 0;

        q.push(src);

        while (!q.empty())
        {
            long long u = q.front();
            q.pop();

            // operação 1
            long long v1 = u * 2;

            if (v1 <= limit && !dist.count(v1))
            {
                dist[v1] = dist[u] + 1;
                parent[v1] = u;

                q.push(v1);
            }

            // operação 2
            long long v2 = u * 10 + 1;

            if (v2 <= limit && !dist.count(v2))
            {
                dist[v2] = dist[u] + 1;
                parent[v2] = u;

                q.push(v2);
            }
        }

        return {dist, parent};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;

    cin >> a >> b;

    Graph g(b);

    auto resp = g.bfs(a);

    auto dist = resp.first;
    auto parent = resp.second;

    if (!dist.count(b))
    {
        cout << "NO\n";
        return 0;
    }

    vector<long long> path;

    long long cur = b;

    while (cur != a)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    path.push_back(a);

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";

    for (auto x : path)
    {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}