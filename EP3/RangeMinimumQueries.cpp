#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n, vector<int>& arr) : n(n), tree(4 * n) {
        build(arr, 1, 1, n);
    }

    void build(vector<int>& arr, int node, int l, int r) {
        if (l == r) { tree[node] = arr[l]; return; }
        int mid = (l + r) / 2;
        build(arr, 2*node,   l,   mid);
        build(arr, 2*node+1, mid+1, r);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) { tree[node] = val; return; }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2*node,   l,   mid, pos, val);
        else            update(2*node+1, mid+1, r, pos, val);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];
        if (qr < l || r < ql)  return INT_MAX;
        int mid = (l + r) / 2;
        return min(query(2*node,   l,   mid, ql, qr),
                   query(2*node+1, mid+1, r, ql, qr));
    }

    void update(int pos, int val) { update(1, 1, n, pos, val); }
    int  query(int l, int r)      { return query(1, 1, n, l, r); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N + 1);

    for (int i=1; i <= N; i++){
        cin >> arr[i];
    }

    SegTree st(N, arr);

    while (Q--) {
        int v1, v2;
        cin >> v1 >> v2;
        cout << st.query(v1,v2) << "\n";
    }
}