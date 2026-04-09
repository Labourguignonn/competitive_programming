#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    // soma delta na posição i (1-based)
    void update(int i, ll delta) {
        for (; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    // soma de 1 até i (1-based)
    ll query(int i) {
        ll sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }

    // opcional: range query [l, r]
    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    Fenwick ft(N);
    for (int i=1; i <= N; i++){
        int x;
        cin >> x;
        ft.update(i,x);
    }

    while (Q--) {
        int v1, v2;
        ll sum1, sum2;
        cin >> v1 >> v2;

        cout << ft.query(v1,v2) << "\n";
    }

    return 0;
}
