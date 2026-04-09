#include <bits/stdc++.h>
using namespace std;

pair<int,int> bfs(int start, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthest = start;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                if (dist[neighbor] > dist[farthest])
                    farthest = neighbor;
            }
        }
    }
    return {farthest, dist[farthest]};
}

int main() {
    return 0;
}