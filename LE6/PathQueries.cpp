#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent, sz;

    DSU(int n)
    {
        parent.resize(n);
        sz.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    long long unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return 0;

        if (sz[a] < sz[b])
            swap(a, b);

        long long new_pairs = 1LL * sz[a] * sz[b];

        parent[b] = a;
        sz[a] += sz[b];

        return new_pairs;
    }
};

struct Edge
{
    int u, v, w;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<Edge> edges(n-1);

    for (int i = 0; i < n-1; i++)
    {
        int a, b, c;

        cin >> edges[i].u >> edges[i].v >> edges[i].w;

        edges[i].u--;
        edges[i].v--;
    }

    sort(edges.begin(), edges.end(),
     [](Edge a, Edge b)
     {
         return a.w < b.w;
     });

    vector<pair<int,int>> queries(m);

    for (int i = 0; i < m; i++)
    {
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(queries.begin(), queries.end());

    vector<long long> ans(m);

    DSU dsu(n);

    long long pairs = 0;

    int ptr = 0;

    for (auto [q, idx] : queries)
    {
        while (ptr < n - 1 && edges[ptr].w <= q)
        {
            pairs += dsu.unite(edges[ptr].u,
                               edges[ptr].v);

            ptr++;
        }

        ans[idx] = pairs;
    }

    for (long long x : ans)
        cout << x << " ";

    return 0;
}