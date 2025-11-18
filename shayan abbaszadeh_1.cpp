#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int findSet(int v) {
    if (parent[v] != v)
        parent[v] = findSet(parent[v]);
    return parent[v];
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == '+') {
            unionSet(a, b);
        } else if (type == '?') {
            if (findSet(a) == findSet(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}