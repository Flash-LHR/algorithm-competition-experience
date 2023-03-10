#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = int(1e6);

int sz[M + 5];
ll f[M + 5];
ll h[M + 5];
vector<int> g[M + 5];

void dfs1(int u, int fa) {
    sz[u] = 1;
    for (const int &v: g[u]) if (v != fa) {
        dfs1(v, u);
        sz[u] += sz[v];
        f[u] += f[v] + sz[v];
    }
}

void dfs2(int u, int fa) {
    for (const int &v: g[u]) if (v != fa) {
        h[v] = h[u] + sz[1] - 2 * sz[v];
        dfs2(v, u);
    }
}

void work() {
    int n; scanf("%d", &n);
    for (int i = 2, u, v; i <= n; i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs1(1, 0);
    h[1] = f[1]; dfs2(1, 0);
    printf("%d\n", int(max_element(h + 1, h + n + 1) - h));
}

int main() {
    work();
    return 0;
}