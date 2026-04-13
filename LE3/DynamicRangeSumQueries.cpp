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

    // soma no intervalo [l, r]
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
    vector<ll> arr(N + 1);

    // leitura inicial
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        ft.update(i, arr[i]);
    }

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int k;
            ll u;
            cin >> k >> u;

            // calcular delta para transformar em "set"
            ll delta = u - arr[k];
            arr[k] = u;
            ft.update(k, delta);

        } else {
            int a, b;
            cin >> a >> b;
            cout << ft.query(a, b) << "\n";
        }
    }

    return 0;
}
